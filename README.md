# PosiTrack - Smart Seating Tracking System

PosiTrack is a smart seating tracking system designed to promote better posture and provide real-time feedback on seating habits. Utilizing various sensors, PosiTrack monitors seating position, pressure, temperature, and more, ensuring users maintain correct posture and avoid health issues related to poor seating habits.

![img1](https://github.com/ErsinAgirman/PosiTrack/assets/117252660/9d097ede-b81a-458b-9467-90a19ab2b6ea)

## Features
- **Force Sensor**: Detects the pressure applied on the seat to determine if someone is sitting.
- **Temperature Sensor**: Measures the seat temperature to confirm the presence of a person.
- **IR Sensors**: Monitors the side positions to detect the presence and seating posture.
- **Ultrasonic Sensor**: Measures the distance to ensure correct seating distance.
- **Flex Sensor**: Detects bending and monitors the correct posture.
- **Buzzer and RGB LED**: Provides auditory and visual feedback on seating posture.

## Components Used
- **Arduino Uno R3**: The main microcontroller board for the project.
- **Force Sensor (A0)**: To detect pressure on the seat.
- **Temperature Sensor (A1)**: To measure the seat temperature.
- **IR Sensors (2, 3)**: To monitor the seating posture from the sides.
- **Ultrasonic Sensor (Trig: 5, Echo: 4)**: To measure the seating distance.
- **Flex Sensor (A2)**: To detect bending and monitor posture.
- **Buzzer (9)**: For auditory feedback.
- **RGB LED (Red: 13, Green: 11, Blue: 12)**: For visual feedback.

## How It Works
1. **Setup Phase**: Initializes all the sensors and serial communication.
2. **Loop Phase**: Continuously reads sensor values and checks for seating status and posture.
   - If the user is seated and maintains correct posture, a blue LED indicates everything is fine.
   - If the user remains seated for too long, the system changes the LED color and sounds the buzzer to encourage taking a break.
   - If incorrect posture is detected, the system provides immediate feedback through the buzzer.

## Usage
1. Connect all the sensors to the Arduino Uno R3 as per the pin configuration.
2. Upload the provided code to the Arduino.
3. Monitor the serial output for real-time sensor values and feedback.
4. Adjust the seating position based on the feedback from the system.

## Benefits
- Promotes better posture and prevents health issues related to prolonged poor seating habits.
- Provides real-time feedback and encourages regular breaks to improve overall health.
- Can be used in various environments such as offices, schools, and homes to promote better seating habits.

## Conclusion and Recommendations
PosiTrack is a practical solution for promoting healthy seating habits through continuous monitoring and feedback. It can significantly improve posture and reduce health risks associated with prolonged poor seating. Future improvements can include integrating wireless communication for remote monitoring and adding more advanced sensors for detailed posture analysis.

---

For more details and the complete code, please visit the [PosiTrack GitHub repository](https://github.com/ErsinAgirman/PosiTrack).
![img2](https://github.com/ErsinAgirman/PosiTrack/assets/117252660/686a047d-483f-4880-b1ba-d1746cef7510)

