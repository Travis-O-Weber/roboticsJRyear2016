# NXT Robot Control Programs

## Overview
This project contains two programs designed for the LEGO NXT robot: one for button-controlled actions and one for autonomous turning and obstacle detection. These programs showcase the use of the NXT's built-in buttons, sensors, and motors for movement and interaction.

## File Descriptions

### 1. `NXT Button.c`
This program overrides the default behavior of the NXT buttons and assigns user-defined actions.
- **Button Tracking**: Tracks presses of the left, right, enter, and exit buttons.
- **Custom Sounds**: Each button press triggers a unique sound.
- **Exit Sequence**: Implements a triple-click mechanism for safely exiting the program.
- **Button Hijacking**: Prevents default NXT button behavior, requiring custom handling.
- **Live Display**: Shows real-time button press counts on the NXT screen.

### 2. `Turn and Distance.c`
This program enables the NXT robot to autonomously move and turn using sensors.
- **Gyro-Based Turning**: Uses a HiTechnic gyro sensor to execute precise turns.
- **Sonar-Based Distance Measurement**: Moves forward until an obstacle is detected at a specified distance.
- **Obstacle Avoidance**: After reaching an obstacle, turns 180 degrees and continues moving.
- **Looped Navigation**: Repeats obstacle detection and turning for a set number of cycles.

## Features
- **Manual Control (`NXT Button.c`)**: Allows custom button handling for interactive applications.
- **Autonomous Navigation (`Turn and Distance.c`)**: Implements sensor-based movement and object avoidance.
- **Real-Time Feedback**: Uses display output and sound notifications for user interaction.

## Usage
1. **Manual Button Interaction**
   - Upload `NXT Button.c` to the NXT brick.
   - Observe button press counts and listen for corresponding sounds.
   - Exit the program using a triple-click of the exit button.

2. **Autonomous Movement**
   - Upload `Turn and Distance.c` to the NXT brick.
   - Ensure the gyro sensor is calibrated and the sonar sensor is positioned correctly.
   - The robot will move forward until it detects an obstacle, then turn and continue navigating.

## Dependencies
- ROBOTC for LEGO NXT
- HiTechnic Gyro Sensor (for `Turn and Distance.c`)
- NXT Sonar Sensor (for `Turn and Distance.c`)

---
This project demonstrates both manual interaction and autonomous movement, making it suitable for interactive robotics applications.

