# Advanced Control for Drive, Gripper, and Arm

## Overview
This project implements advanced control for a VEX 2.0 Cortex-based robot, focusing on driving, gripping, and arm movement using joystick inputs. The control system supports different joystick configurations, threshold filtering for noise reduction, and specific commands for manipulating objects like corn and tomatoes.

## Features
- **Tank and Arcade Drive Control**: Supports both tank and arcade control methods.
- **Gripper Manipulation**: Allows opening and closing of different gripper configurations.
- **Arm Control**: Enables arm movement with smooth control.
- **Threshold Filtering**: Reduces joystick noise to improve stability.
- **Automated Sequences**: Certain versions include a sequence for object pickup and movement.

## Functions

### 1. **Drive Control**
- **Tank Drive Mode**:
  - Uses separate joysticks for left and right motor control.
  - Includes a threshold to eliminate small joystick movements (noise filtering).
- **Arcade Drive Mode** (in some versions):
  - Uses a single joystick for speed and direction control.
  - Implements a logarithmic scaling function for smoother movement.

### 2. **Gripper Control**
- `Btn5U`: Opens gripper fully for large objects (corn).
- `Btn5D`: Closes gripper completely.
- `Btn8U`: Opens gripper partially for smaller objects (tomato).
- `Btn8D`: Closes gripper to a predefined position.
- Some versions include additional control for intermediate gripping.

### 3. **Arm Control**
- `Btn6U`: Moves the arm up.
- `Btn6D`: Moves the arm down.
- Stops when no button is pressed.

### 4. **Automated Object Handling** (in certain versions)
- `Btn7U`: Triggers an automated sequence:
  1. Opens gripper.
  2. Raises the arm.
  3. Moves forward for a set time.

### 5. **Threshold-Based Motor Activation**
- Ensures small joystick fluctuations don’t activate motors unnecessarily.
- Threshold values are configurable.

## File Descriptions
- `basic code working 1.c` - Initial basic functionality.
- `advanced Control drive,gripper, and arm.c` - Enhanced control with arcade drive.
- `Tank Control with Thresholds.c` - Implements tank drive with thresholds.
- `Current test day 1.c` - Includes an experimental log-scale joystick adjustment.
- `advanced Control just drive.c` - Focuses only on drive control.
- `advanced Control drive,gripper, and arm Oct 15-23 Tank.c` - Iterative improvements with enhanced automation and finer gripper control.

## Dependencies
- ROBOTC for VEX Cortex

## Usage
1. Upload the desired `.c` file to the VEX Cortex.
2. Use the joystick buttons and analog sticks to control the robot.
3. Modify the threshold values or button mappings as needed for fine-tuned control.

---

### Notes:
- Ensure motors are properly configured before running.
- Adjust the joystick sensitivity settings if needed.

