# Bus Safety Project

## Overview
The **Bus Safety Project** is an Arduino-based solution designed to enhance student safety on school buses. It detects students' presence on seats using light sensors (LDRs) and ensures no students are left behind using an ultrasonic sensor. If a student is detected within a specified distance, an alarm is triggered, and the driver's phone is called automatically.

---

## Features
1. **Seat Detection**:
   - Detects whether a student is seated using light-dependent resistors (LDRs).
   - Turns on a red LED if the seat is occupied and a green LED if the seat is vacant.

2. **Ultrasonic Monitoring**:
   - Measures distance up to 75 cm to detect students left on the bus.
   - Triggers an alarm and makes a phone call to the driver if a student is detected.

3. **Emergency Alert**:
   - Sounds a buzzer alarm and activates a red LED to alert the driver.
   - Uses the OneSheeld shield to initiate a call to the driver's phone.

---

## Components Required
- **Arduino Uno (or compatible)**: Microcontroller to run the program.
- **Light Dependent Resistors (LDR)** (x2): Detects seat occupancy.
- **Ultrasonic Sensor**: Measures distance to detect students left in the bus.
- **LEDs** (4):
  - Red (x2): Indicates seat occupancy.
  - Green (x2): Indicates vacant seats.
- **Piezo Buzzer**: Produces the alarm sound.
- **OneSheeld Shield**: Enables phone call functionality.
- **Resistors**: For LDR connections.
- **Jumper Wires**: For all connections.
- **Power Source**: Such as a 9V battery.

---

## Wiring Diagram
### 1. **LDR Connections**
- **LDR0**:
  - One leg connected to **A0**.
  - Second leg connected to a resistor (pull-down) and then to **GND**.
  - Shared point connected to **5V**.
- **LDR1**:
  - One leg connected to **A1**.
  - Second leg connected to a resistor (pull-down) and then to **GND**.
  - Shared point connected to **5V**.

### 2. **Ultrasonic Sensor Connections**
- **Trig Pin** → Pin 12.
- **Echo Pin** → Pin 11.
- **VCC** → 5V.
- **GND** → GND.

### 3. **LED Connections**
- **Red LED 0 (R0)** → Pin 7.
- **Green LED 0 (G0)** → Pin 6.
- **Red LED 1 (R1)** → Pin 5.
- **Green LED 1 (G1)** → Pin 4.
- All LEDs' cathodes connected to GND through resistors.

### 4. **Buzzer Connection**
- Positive terminal → Pin 8.
- Negative terminal → GND.

### 5. **OneSheeld Shield**
- Directly mounted onto the Arduino.

---

## Code Description
1. **Setup**:
   - Initializes pins for inputs (LDRs, ultrasonic sensor) and outputs (LEDs, buzzer).
   - Activates OneSheeld library for phone call functionality.

2. **Seat Monitoring**:
   - Reads values from LDR sensors.
   - Controls LEDs (red for occupied, green for vacant) based on sensor values.

3. **Ultrasonic Monitoring**:
   - Measures distance to detect any student within 75 cm.
   - Triggers the buzzer alarm and calls the driver's phone if a student is detected.

4. **Alarm Function**:
   - Produces a melody using the buzzer.
   - Activates the red LED as a visual alert.

---

## How to Use
1. Connect all components as per the wiring diagram.
2. Upload the provided code to the Arduino using the Arduino IDE.
3. Ensure the OneSheeld app is set up and linked to the phone shield.
4. Place the system in the bus:
   - Fix LDRs on seats.
   - Mount the ultrasonic sensor near the bus exit.
5. Power the Arduino.
6. Monitor the LEDs and alarms for any alerts.

---

## Future Improvements
- Add more LDRs to monitor additional seats.
- Integrate GPS tracking for real-time location alerts.
- Enhance alarm system with SMS notifications.

---

## License
This project is open-source and available for educational purposes. Contributions are welcome!
