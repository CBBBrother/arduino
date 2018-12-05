int trig = 11;
int echo = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  unsigned int duration = pulseIn(echo, HIGH);
  unsigned int distance = duration / 58;

  Serial.print(distance);
  Serial.println(" cm");
  delay(100);  
}
