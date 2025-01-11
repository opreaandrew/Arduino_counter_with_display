# Arduino Vinyl Turntable Position Display

## Description
This project implements an automated digital position display for a vinyl turntable using an Arduino board and an I2C LCD display. The system tracks and displays the current position on the vinyl record, helping users navigate to specific sections of their recordings.

## Hardware Requirements
- Arduino board
- I2C LCD display (16x2 characters)
- 3 push buttons
- Vinyl turntable compatible with position tracking
- Connecting wires

## Pin Configuration
- Pin 2: Direction button (Inner/Outer record direction)
- Pin 3: Position adjustment button
- Pin 4: Reset button (Return to start position)

## Features
- Tracks position from outer to inner groove and vice versa
- 16-digit position counter
- LCD display showing current position value
- Reset functionality to return to start position
- Compatible with both 33 and 45 RPM records
- Debounced button inputs for reliable operation

## Operation
1. Direction Control: 
   - HIGH (pressed) = move towards inner groove
   - LOW (released) = move towards outer groove

2. Position Button:
   - Press to fine-tune the current position value

3. Reset Button:
   - Press to reset the counter to the starting position (outer groove)

## Display
- Top line: Shows "ROSTOVEECTOR" (system name)
- Bottom line: Shows current position value

## Dependencies
- Wire.h library
- LiquidCrystal_I2C library

## Installation
1. Install the required libraries in your Arduino IDE
2. Connect the LCD display and buttons to your Arduino following the pin configuration
3. Mount the position tracking system to your turntable
4. Upload the code to your Arduino board

## Notes
- High-precision tracking using unsigned long long for position values
- Display auto-formats to 16 characters for consistent reading
- Button debouncing prevents accidental position jumps
- System can be calibrated for different turntable sizes and speeds

## Safety Considerations
- Ensure all mounting is secure to prevent interference with turntable operation
- Keep wiring away from moving parts
- Calibrate the system before first use with a test record