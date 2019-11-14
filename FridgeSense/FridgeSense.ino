const int Fridge = 4;

int valFridge = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode (Fridge, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  valFridge = touchRead(Fridge);

  Serial.println(valFridge);

  delay(1000);

}

//When the sensor is touched, the values go down. Would need a threshold to determine when the sensor is touched
