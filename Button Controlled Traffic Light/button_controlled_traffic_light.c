int redPin = 13;  // Pin for red LED
int greenPin = 7;  // Pin for green LED
int yellowPin = 9;  // Pin for yellow LED
int pushButtonPin = 2;  // Pin for the push button

int ledTurn = 0;  // 0-Red, 1-Yellow, 2-Green

void setup(){
  pinMode(redPin, OUTPUT);  // Set red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set yellow LED pin as output
  pinMode(greenPin, OUTPUT);  // Set green LED pin as output
  pinMode(pushButtonPin, INPUT);  // Set button pin as input
  
  digitalWrite(redPin, 1);  // Turn on red LED initially
}

void loop(){
  bool pushButtonValue = digitalRead(pushButtonPin);  // Read button state
  if (pushButtonValue == 1){  // If button is pressed
    ledTurn = (ledTurn + 1) % 3;  // Cycle through 0, 1, 2
    updateLed(ledTurn);  // Update the LEDs based on the value
    delay(200);  // Debounce delay
  }
}

void updateLed(int ledTurn){
  digitalWrite(redPin, 0);  // Turn off red LED
  digitalWrite(greenPin, 0);  // Turn off green LED
  digitalWrite(yellowPin, 0);  // Turn off yellow LED
  
  if (ledTurn == 0){  // If red is selected
    digitalWrite(redPin, 1);  // Turn on red LED
  } else if (ledTurn == 1){  // If yellow is selected
    digitalWrite(yellowPin, 1);  // Turn on yellow LED
  } else if (ledTurn == 2){  // If green is selected
    digitalWrite(greenPin, 1);  // Turn on green LED
  }
}