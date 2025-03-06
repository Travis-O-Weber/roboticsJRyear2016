# Autonomous and TeleOp Control for Robotics

## Overview
This project implements autonomous and teleoperated control for a Tetrix-based robot. The system consists of two autonomous scripts (`AutoLeft.c` and `AutoRight.c`) and a teleoperated script (`TeleOp.c`).

## File Descriptions
### 1. `AutoLeft.c`
This script controls the robot's autonomous movement when positioned on the left side of the field.
- **Hook Mechanism**: Raises and lowers a hook before starting movement.
- **Pendulum Interaction**: Moves forward to interact with a pendulum.
- **Cube Release**: Uses a servo to drop a cube.
- **Ramp Navigation**: Executes a sequence of turns and movements to navigate onto a ramp.

### 2. `AutoRight.c`
This script is similar to `AutoLeft.c` but is designed for the robot starting on the right side.
- **Hook Mechanism**: Raises and lowers a hook.
- **Pendulum Interaction**: Moves forward to interact with a pendulum.
- **Cube Release**: Uses a servo to drop a cube.
- **Ramp Navigation**: Adjusted sequence of turns and movements for right-side navigation.

### 3. `TeleOp.c`
This script enables manual control using a joystick.
- **Driving Control**: Uses joystick inputs to control wheel movement with turn and power adjustments.
- **Hook Control**: Allows raising and lowering of hooks using button presses.
- **Flag Raiser**: Uses a joystick axis to control a flag motor.
- **Arm Control**: Moves the arm using joystick input while applying a deadband to prevent small movements.
- **Gripper Control**: Controls the gripper servo using buttons to open and close it.

## Features
- **Autonomous Left and Right Scripts**: Predefined movements for field navigation.
- **Teleoperated Mode**: Allows real-time user control.
- **Deadband Filtering**: Reduces minor joystick noise for smoother movement.
- **Multiple Subsystems**: Supports hooks, arms, grippers, and flag mechanisms.

## Usage
1. **Autonomous Mode**:
   - Upload `AutoLeft.c` if the robot starts on the left side.
   - Upload `AutoRight.c` if the robot starts on the right side.
   - The robot will automatically execute predefined tasks.
2. **TeleOp Mode**:
   - Upload `TeleOp.c` to allow manual joystick control.
   - Use joystick inputs to drive and control mechanisms.

## Dependencies
- ROBOTC for Tetrix
- Joystick driver library (`JoystickDriver.c`)

---
This project provides a structured approach to both autonomous and teleoperated robot control, ensuring efficient field navigation and responsive manual operation.
