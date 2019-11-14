bool cabinetOpened = false;

state_types state = NOTHING;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
}

void loop() {
  float randPicker = (float)random(0, 101)/100.0;
  // put your main code here, to run repeatedly:
  if (randPicker < 0.2) { // nothing happens
    
  } 
  else if (randPicker >= 0.2 & randPicker < 0.4) // someone entered 
  {
  }
  else if (randPicker >= 0.4 & randPicker < 0.6) // fridge selected
  {
  }
  else if (randPicker >= 0.6 & randPicker < 0.8) // cabinet selected
  {
    cabinetOpened = !cabinetOpened;
    if (cabinetOpened)
      Serial.println("CabinetOpened");
    else 
      Serial.println("CabinentClosed");
  }
  else // Carlos' thing. Forgot the name of it :(
  {
  }

  delay(500);
}
