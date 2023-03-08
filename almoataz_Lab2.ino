byte LED = 122;
void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(230400);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0)
{
LED = Serial.read();
}
if (LED == 97)
{
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("on");
}
if (LED == 122)
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("off");
}
if (LED == 65)
{
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("on");
}
if (LED == 90)
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("off");
}
}
