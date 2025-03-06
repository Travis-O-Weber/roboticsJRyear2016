# 6502 Robotics Control System

## Overview
This project consists of multiple scripts designed for autonomous and teleoperated control of a Tetrix-based robot. The system is configured using a shared hardware configuration file and includes functionalities for both competition and general use.

## File Descriptions

### 1. `6502_Config.c` / `6502_Config.h`
These files define the motor and sensor configurations for the robot, ensuring consistency between Autonomous and TeleOp modes.
- **Motors**: Left and right motors, flag motor, arm, lift, and an additional motor.
- **Sensors**: Touch sensor for autonomous mode selection.
- **Servos**: Controls a gripper mechanism.

### 2. `Autonomous.c`
Handles fully automated movement and task execution.
- **Gyro-Based Turning**: Uses a gyro sensor to execute precise turns.
- **Basket Interaction**: Moves toward a basket, lifts an arm, and releases a block.
- **Ramp Navigation**: Chooses a direction based on sensor input and moves onto a ramp.

### 3. `Lego_TeleOp.c`
A teleoperated control program using joystick input for movement.
- **Arcade Drive**: Uses joystick input for smooth turning and movement.
- **Deadband Filtering**: Prevents small joystick movements from affecting the robot.

### 4. `TeleOp.c` / `TeleOp_Old.c`
These files provide joystick-based manual control.
- **Joystick Scaling**: Adjusts inputs to avoid sudden movements.
- **Arcade Drive**: Allows fine-tuned robot movement.
- **Arm & Lift Control**: Controls the arm, lift, and gripper using button inputs.
- **Flag Raiser**: Uses joystick input to raise and lower a flag.

### 5. `TeleOp Template.c`
A skeleton template for creating a new teleoperated program.
- **Basic Initialization**: Provides a starting structure for new teleoperated projects.
- **Sensor Setup**: Ensures proper hardware initialization.

## Features
- **Unified Configuration**: Ensures Autonomous and TeleOp use the same motor and sensor settings.
- **Autonomous Mode**: Executes a predefined set of tasks based on sensor input.
- **Manual Control**: Provides multiple joystick-driven control modes.
- **Deadband Filtering**: Enhances control precision by ignoring minor joystick movements.

## Usage
1. **Autonomous Mode**:
   - Upload `Autonomous.c` to the robot.
   - The robot will execute tasks such as object manipulation and ramp navigation.
2. **TeleOp Mode**:
   - Upload `TeleOp.c` or `Lego_TeleOp.c`.
   - Use the joystick to drive and control robot mechanisms.

## Dependencies
- ROBOTC for Tetrix & LEGO NXT
- HiTechnic Gyro Sensor (for `Autonomous.c`)
- Joystick driver library (`JoystickDriver.c`)

---
This system provides a structured approach for both autonomous and manual robot control, making it suitable for competitive and educational robotics applications.

