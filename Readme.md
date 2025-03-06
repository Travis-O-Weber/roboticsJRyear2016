# BEST Robotics Default Code

## Overview
This project contains the default control code for a VEX-based BEST Robotics competition robot. The program is written in ROBOTC and provides basic arcade-style drive control along with additional motor control.

## File in the Project

- **`BEST_Default_Code_robotc.c`**: Implements the main control logic for the robot.

## Function Descriptions

### `task main`
The main execution loop of the robot.

#### **Functionality**
- Defines joystick channel mappings:
  - `Ch1`: Horizontal joystick input.
  - `Ch2`: Vertical joystick input.
  - `Ch3`: Motor control for port 5 (Servo motor).
  - `Ch4`: Motor control for port 6.
- Enters an infinite loop (`while (true)`) to continuously:
  - Control the servo on port 5 with inverted `Ch3` input.
  - Control the motor on port 6 with `Ch4` input.
  - Use `arcadeControl(Ch2, Ch1, 4);` for arcade-style driving, where the joystick input maps to the configured left and right motors.

## How to Use
1. Load the code onto a VEX Cortex controller using ROBOTC.
2. Ensure the joystick channels match the intended control scheme.
3. Run the program and use the joystick for movement.

## Notes
- The `arcadeControl` function is a built-in ROBOTC function for handling joystick-based driving.
- The motor ports must be correctly configured in the VEX hardware setup.
- Ensure the joystick is properly paired with the Cortex before running the program.
