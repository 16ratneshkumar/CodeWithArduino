int potPin=A0 ;                     // Potentiometer pin
int ledValue,potValue;              // Variable to store Brightness value (0-255) ,Potentiometer value

void setup(){
    pinMode(8,OUTPUT);          // Set Output pin
}

void loop(){
    potValue = analogRead(potPin);   // Read Potentiometer value (0 to 1023)
    ledValue = map(potValue, 0, 1023, 0, 255) // Map to PWM range
    analogWrite(8, ledValue);       // Set LED brightness
}