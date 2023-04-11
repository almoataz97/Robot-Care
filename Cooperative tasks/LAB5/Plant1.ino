#include "ESP8266WiFi.h"

char flag = 0;
int boton = 16;
byte last = LOW;
byte led = HIGH;
int trigPin = 13;
int echoPin = 12;
int buzzer = 14;
long duration, cm;
unsigned long time0 = 40;
unsigned long time1 = 0;

// WiFi parameters
                    const char* ssid = "AndroidAPA1A3";
                    const char* password = "alnoataz123";
                    
  String thingName="group4-RobotCare_Dweet"; 

const char* host = "dweet.io";


  String arrayVariableNames[]={"ONE","TWO","THREE","FOUR"};//THIS WAY WE REFER TO EACH VARIABLE AS AN INDEX IN THIS GLOBAL ARRAY. arrayVariableNames[0]="UNO"
  int   arrayVariableValues[]={1,2,3,4};  
//int numberVariables=sizeof(arrayVariableValues)/sizeof(arrayVariableValues[0]);//tells the number of arguments inside each array
//////////////////////////////

void setup() {
  
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
  
  Serial.begin(9600);
///////////wifi things
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  //initialice and connect to wifi lan
  WiFi.begin(ssid, password);  
  int retries = 0;
  while ((WiFi.status() != WL_CONNECTED) && (retries < 15)) {
    retries++;
    delay(500);
    Serial.print(".");
  }
  if(retries>14){
        Serial.println(F("WiFi conection FAILED"));
  }
  if (WiFi.status() == WL_CONNECTED) {
  Serial.println(F("WiFi connected"));
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(F("======================================================")); 
  }
  
   Serial.println(F("Setup ready")); 


}

void loop() { 

//arrayVariableValues[0]=cm;//this is how you change values of the variables
//arrayVariableValues[1]=0;
//arrayVariableValues[2]=0;
//arrayVariableValues[3]=1;

arrayVariableNames[0]="Distance";//this is how you change the name of the variable( veinticinco=25)
arrayVariableNames[1]="Buzzer";
arrayVariableNames[2]="Light_1";
arrayVariableNames[3]="Light_2";
sensing();
bottom();
dweetdata();//upload it
}

void dweetdata(){//connects TCP,sends dweet,drops connection, prints the server response on the console 
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

    client.print(GetDweetStringHttpBuilder());

  delay(10);//slow doown ...stability stuff
  
  // Read all the lines of the reply from dweet server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  //just display ending conection on the serial port
  Serial.println();
  Serial.println("closing connection");
   
}

String GetDweetStringHttpBuilder() {
  int i=0;
  int numberVariables=sizeof(arrayVariableValues)/sizeof(arrayVariableValues[0]);//tells the number of arguments inside each array
  String dweetHttpGet="GET /dweet/for/";//initial empty get request
  dweetHttpGet=dweetHttpGet+String(thingName)+"?";//start concatenating the thing name (dweet.io)
  
  for(i=0;i<(numberVariables);i++){//concatenate all the variable names and values
   if(i==numberVariables-1){
    dweetHttpGet=dweetHttpGet + String(arrayVariableNames[i]) + "="+ String( arrayVariableValues[i]);//the lastone doesnt have a "&" at the end

   }
   else
    dweetHttpGet=dweetHttpGet + String(arrayVariableNames[i]) + "="+ String( arrayVariableValues[i]) + "&";  
  }
 dweetHttpGet=dweetHttpGet+" HTTP/1.1\r\n"+
                  "Host: " + 
                    host + 
                  "\r\n" + 
                  "Connection: close\r\n\r\n";
                  
  return dweetHttpGet;//this is our freshly made http string request
}

void sensing() {
  // put your main code here, to run repeatedly: 
  if (flag == 0){
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
  arrayVariableValues[0]=cm;
  digitalWrite(buzzer,LOW);
  arrayVariableValues[1]=0;

    if(cm<150)
    {
      Serial.print("WARNING");
      Serial.println();
      //digitalWrite(buzzer,HIGH);
      tone(buzzer,1000);
      digitalWrite(0, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      arrayVariableValues[1]=1;
      arrayVariableValues[2]=1;
      arrayVariableValues[3]=1;      
    }
    else{
      digitalWrite(0, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      arrayVariableValues[2]=0;
      arrayVariableValues[3]=1;
    }
  delay(250);
  }
  else if (flag == 1){
    digitalWrite(trigPin,LOW);
    digitalWrite(buzzer,LOW);
    digitalWrite(0, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    arrayVariableValues[1]=0;
    arrayVariableValues[2]=0;
    arrayVariableValues[3]=0;
    delay(250);        
  }  
}

void bottom() {
  // put your main code here, to run repeatedly:
  if((millis()-time0)>time1){
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
        arrayVariableValues[2]=0;
        arrayVariableValues[3]=0;
        if (led == LOW){
          flag = 1;
        }
        else{
          flag = 0;
        }
      }
    }
  }    
}
