const int BUFFER_SIZE = 50;
char buf[BUFFER_SIZE];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial set");
}

void loop() {
  // put your main code here, to run repeatedly:

  #define CTD_ACQUISITION_TRIGGER_PACKET "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",0xff,0xff,0xff,0xff,0xff,0xaa,0,0x90,0,0,0,0,0,0,0x6c
  byte send_str[] = {0xff,0xff,0xff,0xff,0xaa,0,0x90,0,0,0,0,0,0,0x6c};
  Serial.print("Sending: ");
  /*
  for (int i = 0 ; i < 14; i++) {
    Serial.print(send_str[i], HEX);
  }
  Serial.println();
  */
  String testsend = "FFFFFFFFAA0900000006C";
  
  // Serial.println(send_str[15]);
  // Serial.print("Possibly sending: ");
 // Serial.println(send_str);
  //Serial.write("FFFFFFFFAA0900000006C");
  Serial.write(send_str, sizeof(send_str));
  
  if (Serial.available() > 0 ) {
    Serial.println("\nI AM ALIVE!");
    int rlen = Serial.readBytes(buf, BUFFER_SIZE);
    Serial.print("Received: ");
    for (int i = 0; i < rlen; i++) {
      Serial.print(buf[i], HEX);  
      Serial.print(" ");
    }
    
    //Serial.println(read_str, HEX);
    /*
    unsigned int len = read_str.length();
    for (unsigned int i = 0 ; i < len; i++) {
      Serial.println(read_str[i]);
    }
    */
    Serial.println();
    /*
    for (byte i=0; i < sizeof(read_str) - 1; i++){
      Serial.println(read_str[i], HEX);
    }*/
  } else {
    Serial.println("\nI am ded");
  }
  delay(2000);
  
  // char read_data = Serial.read();
}