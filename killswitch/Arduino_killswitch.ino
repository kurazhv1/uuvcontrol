

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  static int amIdead = 0;
  if (amIdead == 0) {
    if (Serial.available() > 0 && (Serial)) {
  
      String data = Serial.readStringUntil('\n');
      Serial.print("You sent me: ");
      Serial.println(data);
      Serial.write("Received!");
    }
    else {
      delay(2000);
      if (Serial.available() == 0 || !(Serial)) {
        amIdead = 1;
        Serial.write("Dead");
       
      }
    }
  }

  else {
      digitalWrite(13, HIGH); // sets the digital pin 13 on
      delay(1000);            // waits for a second
      digitalWrite(13, LOW);  // sets the digital pin 13 off
      delay(1000);            // waits for a second
      Serial.write("Surfacing because I died");
  }
}
