void setup() {
  // put your setup code here, to run once:
  pinMode(34,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float val = analogRead(34);
  Serial.print(String(val) +"\n");
}
