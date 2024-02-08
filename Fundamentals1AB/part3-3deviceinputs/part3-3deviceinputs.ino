void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("sensorPinA0: ");
  Serial.println(analogRead(A0));
  Serial.print("sensorPinA3: ");
  Serial.println(analogRead(A3));
  Serial.print("sensorPinA5: ");
  Serial.println(analogRead(A5));
  
  delay(1);
}
