char ENTRY = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(9600); 
  
}

void loop() {
  // put your main code here, to run repeatedly:

    ENTRY = Serial.read();
    Serial.println(ENTRY);
    delay(1000); 
    if(ENTRY == 'A'){
          digitalWrite(LED_BUILTIN, LOW);
          delay(1000);     
    }
    if(ENTRY == 'T'){
          digitalWrite(LED_BUILTIN, HIGH);
          delay(1000);     
    }        
}
