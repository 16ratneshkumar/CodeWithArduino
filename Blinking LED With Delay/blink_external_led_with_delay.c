void setup(){
  pinMode(8, OUTPUT);  // Set pin 8 as output
}

void loop(){
  digitalWrite(8, HIGH);  // Turn LED on
  delay(1000);  // Wait for 1 second
  digitalWrite(8, LOW);  // Turn LED off
  delay(1000);  // Wait for 1 second
}