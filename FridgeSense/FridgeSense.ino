#include "painlessMesh.h"

#define   MESH_PREFIX     "TheBees"
#define   MESH_PASSWORD   "TheHiveLives"
#define   MESH_PORT       5555

const int Fridge = 4;
int valFridge = 0;

int flipper = 0;

Scheduler userScheduler; // to control your personal task
painlessMesh mesh;

// User stub
void sendMessage() ; // Prototype so PlatformIO doesn't complain

Task taskSendMessage( TASK_SECOND * 1 , TASK_FOREVER, &sendMessage );

void sendMessage() {
  //Update message here 
  String msg = "";
  //String msg2 = "";
  //msg += mesh.getNodeId();

  if (valFridge < 15 ){
    flipper = 1;
    msg = "Touched";
    mesh.sendBroadcast(msg);
    Serial.println(valFridge);
  //taskSendMessage.setInterval(1);
    //msg2 += "Touched";
  }else if (flipper == 1){
    flipper = 0;
    msg = "Released";
    Serial.println(valFridge);
    mesh.sendBroadcast(msg);
    //msg2 += "Released";
  }
  //mesh.sendBroadcast( msg );
  //taskSendMessage.setInterval( random( TASK_SECOND * 1, TASK_SECOND * 5 ));
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  //Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
  Serial.println(msg.c_str());

}

void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
    Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(),offset);
}

void setup() {
  Serial.begin(115200);

  pinMode (Fridge, INPUT);
  

//mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages

  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  userScheduler.addTask( taskSendMessage );
  taskSendMessage.enable();
}

void loop() {
  // it will run the user scheduler as well
  valFridge = touchRead(Fridge);
  mesh.update();
  
  //Serial.println(valFridge);
  delay(200);
  
}
