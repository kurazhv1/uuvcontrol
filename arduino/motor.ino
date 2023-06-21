int pwm_pin = 12;
int dir_pin = 48;
int break_pin = 47;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(pwm_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(break_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir_pin, HIGH);
  digitalWrite(break_pin, HIGH);
  analogWrite(pwm_pin, 255); 
}
