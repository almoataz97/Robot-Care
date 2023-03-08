char entrada = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(9600); 
  Serial.println("Casa");
}

void loop() {
  // put your main code here, to run repeatedly:

    entrada = Serial.read();
    Serial.println(entrada);
    delay(1000); 
    if(entrada == 'J'){
          digitalWrite(LED_BUILTIN, LOW);
          delay(1000);     
    }
    if(entrada == 'E'){
          digitalWrite(LED_BUILTIN, HIGH);
          delay(1000);     
    }        
}
