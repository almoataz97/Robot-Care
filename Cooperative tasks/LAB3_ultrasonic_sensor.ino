int trigPin = 12;
int echoPin = 13;
int buzzer = 14;
long duration, cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(14,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  cm = (duration/2)/29.1;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  digitalWrite(buzzer,LOW);

  if(cm<15)
  {
    Serial.print("WARNING");
    Serial.println();
    digitalWrite(buzzer,HIGH);
  }
  delay(250);
}
