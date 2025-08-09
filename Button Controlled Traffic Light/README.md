# **Button Controlled Traffic Light Simulation**

## **Description**

This Arduino project simulates a traffic light system using three LEDs: Red, Yellow, and Green. A push button is used to cycle through the LEDs, representing the traffic light changing from red to yellow to green. This project demonstrates basic pin control, button input reading, and debouncing.

## **Features**

* Cycles through **Red, Yellow, and Green** LEDs based on button presses.
* **Debounce** logic to prevent multiple button presses from being registered at once.
* Simple wiring setup for easy hardware implementation.
* Great for learning basic interaction between buttons and LEDs.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Create a free account on [Tinkercad](https://www.tinkercad.com/).
* **Internet connection**: Required for using Tinkercad's online platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or any compatible Arduino board)
* **Red LED**
* **Yellow LED**
* **Green LED**
* **220-ohm Resistors** (for each LED)
* **Push button**
* **10kΩ Pull-up Resistor** (for the button)
* **Breadboard**
* **Jumper wires**
* **Arduino IDE** installed on your computer
* **USB cable** for connecting the Arduino to your computer

## **Circuit Diagram**

![Circuit Diagram](<Button Controlled Traffic Light.png>)

### **For Tinkercad Simulation**

1. Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project.
3. Drag and drop the components:

   * **Arduino Uno**
   * **Red, Yellow, and Green LEDs** (with 220-ohm resistors in series)
   * **Push button**
   * **Wires** to connect the components as shown in the connection table below.

### **For Hardware Setup**

* **Red LED** is connected to **Pin 13**.
* **Yellow LED** is connected to **Pin 9**.
* **Green LED** is connected to **Pin 7**.
* **Push button** is connected to **Pin 2** and **Ground**.

Use **220-ohm resistors** in series with each LED to limit current and avoid damaging the components.

## **Connection**

| Arduino Pin | Component                                    |
| ----------- | -------------------------------------------- |
| 13          | Red LED (with 220-ohm resistor)              |
| 9           | Yellow LED (with 220-ohm resistor)           |
| 7           | Green LED (with 220-ohm resistor)            |
| 2           | Push Button (with pull-down resistor to GND) |

## **Code Explanation**

This code cycles through the three LEDs when the push button is pressed. It uses a simple debounce technique to avoid reading multiple button presses in quick succession.

### **Code:**

```cpp
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
```

* **`pinMode()`**: Sets each pin as an output for the LEDs and an input for the button.
* **`digitalWrite()`**: Controls the LEDs (turn them on or off based on the value of `ledTurn`).
* **`digitalRead()`**: Reads the state of the push button (HIGH when pressed).
* **Debounce**: A `delay(200)` is used to debounce the button, ensuring that multiple presses are not counted.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up Circuit in Tinkercad**:

   * Go to [Tinkercad Circuits](https://www.tinkercad.com/circuits).
   * Create a new project and add the following components:

     * **Arduino Uno**
     * **Red, Yellow, Green LEDs** (with 220-ohm resistors in series)
     * **Push button** connected to pin 2 and ground.
   * Make the connections as per the table above.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button in Tinkercad to open the code editor.
   * Select **Text** and paste the provided code.
   * Click **Start Simulation** to see the LEDs cycle through colors when the button is pressed.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Place **Red, Yellow, and Green LEDs** on the breadboard.
   * Connect **Pin 13** to the **Red LED**'s anode (with a 220-ohm resistor).
   * Connect **Pin 9** to the **Yellow LED**'s anode (with a 220-ohm resistor).
   * Connect **Pin 7** to the **Green LED**'s anode (with a 220-ohm resistor).
   * Connect the **push button** to **Pin 2** and **Ground**.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE** on your computer.
   * Connect your **Arduino Uno** to the computer using a **USB cable**.
   * Select the correct **board** and **port** under **Tools**.
   * Copy and paste the provided code into the IDE.
   * Click **Upload** to send the code to your Arduino.

3. **Verify the Output**:

   * After uploading the code, pressing the push button will cycle through the LEDs in the following order: **Red -> Yellow -> Green -> Red**.

## **Demo Video**

*Insert YouTube or Google Drive link to your demo video here.*

## **Troubleshooting**

* **LEDs not working as expected?**

  * Double-check the wiring and ensure each LED has a **220-ohm resistor**.
  * Ensure the push button is connected properly (one side to pin 2, the other to ground).

* **Button not responding?**

  * Make sure the button is properly connected and there are no loose wires.
  * Check the Arduino IDE for any errors during upload.

* **Arduino not powering?**

  * Ensure your Arduino is connected to the PC via USB or to an external power source.
  * Verify the correct **board and port** are selected in the IDE.
