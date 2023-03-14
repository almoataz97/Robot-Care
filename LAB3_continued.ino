char entrada = 0;
char bandera = 0;
int boton = 16;
byte last = LOW;
byte led = HIGH;
int trigPin = 13;
int echoPin = 12;
int buzzer = 14;
long duration, cm;
unsigned long tiempo = 40;
unsigned long tiempo1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(16,INPUT);
  pinMode(5, OUTPUT);   //for D2 GREEN
  pinMode(4, OUTPUT);   //for D3 RED
  pinMode(0, OUTPUT);   //for buzzer D4
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(14,OUTPUT);
  Serial.begin(9600);  
  digitalWrite(0, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensing();
  bottom();
}

void sensing() {
  // put your main code here, to run repeatedly: 
  if (bandera == 0){
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

    if(cm<150)
    {
      Serial.print("WARNING");
      Serial.println();
      //digitalWrite(buzzer,HIGH);
      tone(buzzer,1000);
      digitalWrite(0, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);      
    }
    else{
      digitalWrite(0, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
  delay(250);
  }
  else if (bandera == 1){
    digitalWrite(trigPin,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);        
  }  
}

void bottom() {
  // put your main code here, to run repeatedly:
  if((millis()-tiempo)>tiempo1){
    byte button = digitalRead(boton);
    if(button != last)
    {
      last = button;
      if(button == LOW)
      {
        led = (led == HIGH) ? LOW : HIGH;
        digitalWrite(4,LOW);
        digitalWrite(0,LOW);
        digitalWrite(5,LOW);
        if (led == LOW){
          bandera = 1;
        }
        else{
          bandera = 0;
        }
      }
    }
  }    
}