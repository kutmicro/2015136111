
void setup() {
 
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  //int sensorValue = analogRead(A5); //pot1 test
  //int sensorValue = analogRead(A6); //pot2 test
  int sensorValue = analogRead(A14); //pot3 test
  
  Serial.println(sensorValue); //print
  delay(100);        // delay
}
