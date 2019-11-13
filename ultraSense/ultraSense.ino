const int trigPin1 = 4;
const int echoPin1 = 16;

const int trigPin2 = 25;
const int echoPin2 = 26;

int isOccupied = 0;

long duration, distance, BackSensor,FrontSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
FrontSensor = distance;
SonarSensor(trigPin2, echoPin2);
BackSensor = distance;

//Serial.print(FrontSensor);
//Serial.print(" - ");
//Serial.println(BackSensor);
Serial.println(FrontSensor - BackSensor);
/*
if (FrontSensor - BackSensor > 50)
{
  isOccupied = 1;
  Serial.println("Forward IN");
  Serial.println("");
  delay(2000);
}
else if (BackSensor - FrontSensor > 50)
{
  isOccupied = 1;
  Serial.println("Backward OUT");
  Serial.println("");
  delay(2000);

}
if (isOccupied == 1 && ((FrontSensor - BackSensor < 10) || (BackSensor - FrontSensor < 10)))
{
  isOccupied = 0;
  Serial.println("RESET"); 
  Serial.println("");

} 
*/


}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
