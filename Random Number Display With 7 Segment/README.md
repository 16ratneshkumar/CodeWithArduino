# **7-Segment Display with Random Number Generator**

## **Description**

This Arduino project uses a **7-segment display** to show a random number between 0 and 9 each time a button is pressed. The program generates a random digit and lights up the appropriate segments on the 7-segment display to represent that digit.

## **Features**

* **7-segment display** for showing digits 0 to 9.
* **Button-controlled random number generation**.
* Easy-to-understand interaction for learning about 7-segment displays and random number generation.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **7-segment display** (common cathode or common anode)
* **Resistors** (220Ω for each segment)
* **Push button**
* **10kΩ Pull-up Resistor** (for the button)
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**

![alt text](<Random Number Display With 7 Segment.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the following components:

   * **Arduino Uno**
   * **7-segment display**
   * **Push button**
   * **Wires** to connect components.

### **For Hardware Setup**

* **7-segment Display**: Connect the 7 segments (a to g) of the display to **Pins 2, 3, 4, 5, 6, 7, 8** on the Arduino.

  * Use **220Ω resistors** for each segment to limit the current.
* **Button**: Connect the button to **Pin 9** on the Arduino and use a **10kΩ pull-up resistor** between **Pin 9** and **5V**.

## **Connection**

| Arduino Pin | Component                                      |
| ----------- | ---------------------------------------------- |
| 2           | Segment a (7-segment display)                  |
| 3           | Segment b (7-segment display)                  |
| 4           | Segment c (7-segment display)                  |
| 5           | Segment d (7-segment display)                  |
| 6           | Segment e (7-segment display)                  |
| 7           | Segment f (7-segment display)                  |
| 8           | Segment g (7-segment display)                  |
| 9           | Push button (with 10kΩ pull-up resistor to 5V) |

### **Note**:

* Each segment of the 7-segment display is connected to one of the Arduino pins.
* The button is connected to **Pin 9** with a **10kΩ pull-up resistor** to **5V**.

## **Code Explanation**

This code generates a random digit (0-9) every time the button is pressed and displays it on the 7-segment display. The button press triggers the random number generation, and the corresponding segments of the 7-segment display are turned on to show the digit.

### **Code:**

```cpp
// Segment pins (a-g)
int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};  // Pin numbers for 7-segment display
const int buttonPin = 9;  // Pin for the button

bool buttonPressed = false;  // Track button press state

// Digits 0-9 for 7-segment display (a-g) segments
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);  // Set segment pins as outputs
  }
  pinMode(buttonPin, INPUT);  // Set button pin as input
  randomSeed(analogRead(A0));  // Use analog noise for randomness
}

void displayDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);  // Set segment states based on the digit
  }
}

void loop() {
  int reading = digitalRead(buttonPin);  // Read button state

  if (reading == HIGH && !buttonPressed) {  // Button pressed
    buttonPressed = true;
    int randNum = random(0, 10);  // Generate a random digit between 0 and 9
    displayDigit(randNum);  // Display the random digit on the 7-segment display
    delay(200);  // Debounce delay to avoid multiple triggers
  }

  if (reading == LOW) {  // Button released
    buttonPressed = false;
  }
}
```

* **`pinMode()`**: Sets the segment pins as **OUTPUT** and the button pin as **INPUT**.
* **`random(0, 10)`**: Generates a random number between 0 and 9.
* **`displayDigit(num)`**: Turns on the appropriate segments for the digit, based on the binary representation of the segments.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project and drag the following components:

     * **Arduino Uno**
     * **7-segment display**
     * **Push button**
   * Make the connections according to the table above.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Text** and paste the provided code into the editor.
   * Press **Start Simulation** to see the random digit displayed on the 7-segment display when the button is pressed.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Connect the **7-segment display** to **Pins 2 to 8** through **220-ohm resistors** for each segment.
   * Connect the **push button** to **Pin 9** and to **GND**. Ensure you have a **10kΩ pull-up resistor** connected to **5V** for the button.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Select the correct **board** and **port** under the **Tools** menu.
   * Copy and paste the provided code into the IDE.
   * Click **Upload** to send the code to your Arduino.

3. **Verify the Output**:

   * After uploading the code, pressing the button will generate a random number between 0 and 9 and display it on the 7-segment display.

## **Demo Video**

*Insert YouTube or Google Drive link to your demo video here.*

## **Troubleshooting**

* **7-segment display not showing the correct digit?**

  * Double-check the wiring of the 7-segment display. Make sure each segment is connected to the correct Arduino pin.

* **Button not working?**

  * Ensure the button has a **10kΩ pull-up resistor** to keep the pin HIGH when the button is not pressed.

* **Arduino not powering?**

  * Ensure the Arduino is connected properly via USB or an external power source.