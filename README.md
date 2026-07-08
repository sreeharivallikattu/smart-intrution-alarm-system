# Smart Intrusion Alarm System

An Arduino-based security system that detects vibration or physical intrusion and activates an alarm using a buzzer, RGB LED, and relay.

## Features

- Detects vibration or shock
- Visual alarm using RGB LED
- Audible alarm using buzzer
- Relay output for external siren/light
- Automatic reset after alarm sequence

## Components Used

- Arduino Uno
- SW-18020P Vibration Sensor (Raw)
- RGB LED
- 3 × 220Ω Resistors
- Active Buzzer
- JQC-3FC (T73) 5V Relay
- BC547 NPN Transistor
- 1N4007 Flyback Diode
- 1kΩ Base Resistor
- Breadboard
- Jumper Wires

## Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| Vibration Sensor | D2 |
| RGB Red | D3 |
| RGB Green | D4 |
| RGB Blue | D5 |
| Buzzer | D6 |
| Relay Driver | D7 |


## Working Principle

1. System powers on.
2. Green LED indicates the system is armed.
3. Vibration sensor continuously monitors movement.
4. When vibration is detected:
   - Red LED flashes.
   - Buzzer sounds.
   - Relay activates an external device.
5. After several alarm cycles, the system automatically resets.

## Project Flow

```
Power ON
     │
     ▼
System Armed
(Green LED)
     │
     ▼
Monitor Vibration Sensor
     │
     ▼
Vibration Detected?
     │
 ┌───┴────┐
 │        │
No       Yes
 │        │
 │        ▼
 │   Activate Alarm
 │        │
 │        ▼
 │  Relay + Buzzer +
 │   Flashing LED
 │        │
 └────────▼
   Return to Armed State
```

## Learning Outcomes

- Arduino Programming
- Digital Input Handling
- Event-driven Programming
- Relay Interfacing
- Transistor Switching
- Flyback Diode Protection
- Embedded System Design
- Hardware Integration


## Future Improvements

- GSM SMS Alerts
- ESP32 Wi-Fi Notifications
- Keypad Password Reset
- PIR Motion Sensor
- Battery Backup
- Mobile App Monitoring
- IoT Dashboard


## Demo Video : 

Watch the project detect vibration and activate the complete alarm sequence.

 demo video link : 

## Author

SREEHARI VALLIKATTU 
Electrical and Electronics Engineering
NIT Calicut
