# **Traffic Light Simulation with Delay**

## **Description**

This project simulates a traffic light using three **LEDs**: red, yellow, and green. The LEDs will follow a sequence that mimics the behavior of a real traffic light:

* **Red LED**: Turns on for 3 seconds.
* **Yellow LED**: Turns on for 1 second.
* **Green LED**: Turns on for 3 seconds.
* **Yellow LED**: Turns on again for 1 second to indicate the transition between red and green.

## **Features**

* **Red, Yellow, Green LEDs**: Simulates a traffic light cycle.
* **Timed intervals**: Each LED turns on for a specific duration.
* **Simple and clear**: Perfect for understanding basic digital output and timing in Arduino.

## **Requirements**

### **For Tinkercad (Online Simulation)**

* **Tinkercad Account**: Sign up for a free account at [Tinkercad](https://www.tinkercad.com/).
* **Internet Connection**: Required to access the Tinkercad Circuits platform.

### **For Hardware Setup (Physical Project)**

* **Arduino Uno** (or compatible Arduino board)
* **3 x LEDs** (Red, Yellow, Green)
* **3 x 220Ω Resistors**
* **Jumper wires**
* **Breadboard** (optional)
* **Arduino IDE** installed on your computer
* **USB cable** to connect the Arduino to your computer

## **Circuit Diagram**

![Circuit Diagram](<Time Delay Traffic Light.png>)

### **For Tinkercad Simulation**

1. Open [Tinkercad Circuits](https://www.tinkercad.com/circuits).
2. Create a new project and drag the following components:

   * **Arduino Uno**
   * **3 LEDs** (Red, Yellow, Green)
   * **Resistors** (220Ω)
3. Make the necessary connections using the provided **connection table**.

### **For Hardware Setup**

* **Red LED**: Connect the long leg (anode) to **Pin 13**, the short leg (cathode) to **GND** through a 220Ω resistor.
* **Yellow LED**: Connect the long leg (anode) to **Pin 9**, the short leg (cathode) to **GND** through a 220Ω resistor.
* **Green LED**: Connect the long leg (anode) to **Pin 7**, the short leg (cathode) to **GND** through a 220Ω resistor.

## **Connection**

| Arduino Pin | Component     |
| ----------- | ------------- |
| 13          | Red LED       |
| 9           | Yellow LED    |
| 7           | Green LED     |
| GND         | Common ground |

## **Code Explanation**

This code controls the LEDs to simulate the sequence of a traffic light. The LEDs will turn on for a specific time, then turn off and move to the next LED in the sequence.

### **Code:**

```cpp
int redPin = 13;  // Pin for red LED
int greenPin = 7;  // Pin for green LED
int yellowPin = 9;  // Pin for yellow LED

void setup(){
  pinMode(redPin, OUTPUT);  // Set red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set yellow LED pin as output
  pinMode(greenPin, OUTPUT);  // Set green LED pin as output
}

void loop(){
  digitalWrite(redPin, HIGH);  // Turn on red LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(redPin, LOW);  // Turn off red LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(greenPin, HIGH);  // Turn on green LED
  delay(3000);  // Wait for 3 seconds
  digitalWrite(greenPin, LOW);  // Turn off green LED
  delay(500);  // Wait for 0.5 seconds

  digitalWrite(yellowPin, HIGH);  // Turn on yellow LED again
  delay(1000);  // Wait for 1 second
  digitalWrite(yellowPin, LOW);  // Turn off yellow LED
  delay(500);  // Wait for 0.5 seconds
}
```

* **`digitalWrite()`**: Controls whether the LED is turned on (`HIGH`) or off (`LOW`).
* **`delay()`**: Pauses the program for a specified number of milliseconds.
* The **Red LED** turns on for 3 seconds, then the **Yellow LED** for 1 second, followed by the **Green LED** for 3 seconds, and finally the **Yellow LED** again for 1 second before starting the cycle over.

## **How to Use**

### **1. Online (Tinkercad Simulation)**

1. **Set Up the Circuit in Tinkercad**:

   * Visit [Tinkercad Circuits](https://www.tinkercad.com/circuits) and create a new project.
   * Add an **Arduino Uno** and the three LEDs (red, yellow, green), along with **resistors** (220Ω).
   * Connect the components based on the provided **connection table**.

2. **Upload Code to Tinkercad**:

   * Click on the **Code** button to open the editor.
   * Select **Text** and paste the provided code.
   * Press **Start Simulation** to watch the LEDs follow the traffic light pattern.

### **2. Hardware (Physical Setup)**

1. **Build the Circuit**:

   * Wire the **LEDs** to the appropriate **pins** (13, 9, 7) on the Arduino.
   * Ensure each LED is connected to **GND** through a **220Ω resistor** to prevent overcurrent.

2. **Upload the Code to Arduino**:

   * Open the **Arduino IDE**.
   * Connect your **Arduino Uno** to your computer via **USB**.
   * Choose the appropriate **board** and **port** from the **Tools** menu.
   * Copy the provided code into the IDE and press **Upload**.

3. **Observe the Traffic Light**:

   * Once the code is uploaded, the **LEDs** will start flashing according to the traffic light pattern:

     * Red for 3 seconds.
     * Yellow for 1 second.
     * Green for 3 seconds.
     * Yellow for 1 second.

## **Demo Video**

https://github.com/user-attachments/assets/1c480a1f-e004-48e4-afcf-bb73d0b8f437

## **Troubleshooting**

* **LED not turning on?**

  * Check the wiring and ensure the LEDs are connected to the correct pins and have the correct polarity (long leg to the pin).
  * Ensure the **220Ω resistor** is connected in series with the LEDs to limit current.
* **Arduino not responding?**

  * Ensure your Arduino is correctly connected to your computer via **USB**.
  * Verify that the correct **board** and **port** are selected in the **Arduino IDE**.
