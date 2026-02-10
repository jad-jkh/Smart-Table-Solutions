# Smart-Table-Solutions

Sample files from Jad Haddad's Smart Table Solutions including: KiCad PCB files (schematic, layout, and 3D view) and screenshots, along with embedded C code for motor control.

## Overview
Smart Table Solutions provides an automated height-adjustable table control system using an STM32F103C8T6 (Blue Pill) microcontroller and DRV8876 motor driver. The system allows users to adjust table height via simple button controls.

## Hardware Components
- **Microcontroller:** STM32F103C8T6 (Blue Pill)
- **Motor Driver:** DRV8876
- **Buttons:** 2x momentary push buttons (Up/Down control)
- **LED:** Status indicator (reserved for future features)

## Pin Configuration
| Component | Pin | Description |
|--------------|----------|-------------------------------------------|
| Button Down  |   PB12   | Active LOW with internal pull-up          |
| Button Up    |   PB15   | Active LOW with internal pull-up          |
| Motor Enable | (IN1/EN) | PA6 | Enable signal to DRV8876            |
| Motor Phase  | (IN2/PH) | PA5 | Phase/direction control to DRV8876  |
| LED Reserve  |    PB7   | Reserved for future add-on features       |

## Functionality
- **Hold DOWN button (PB12):** Motor drives table downward
- **Hold UP button (PB15):** Motor drives table upward
- **Hold BOTH buttons:** Motor stops (safety feature)
- **Release buttons:** Motor stops

## Software
The embedded firmware is written in C using the Arduino framework with STM32duino support.

### Features
- Simple hold-to-run button logic
- Safety stop when both buttons pressed simultaneously
- 10ms software debouncing
- Reserved LED pin for custom add on

### Code Structure
- `motorControl.ino` - Main control logic for motor operations

## Setup Instructions

### Hardware Setup
1. Connect ST-Link programmer to Blue Pill SWD pins (SWDIO, SWCLK, GND, 3.3V)
2. Solder buttons to PB12 and PB15 with pull-up configuration and LED + controller if applicable
3. Solder DRV8876 motor driver IN1 to PA6, IN2 to PA5
4. Plug jack into female connector

### Software Setup
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Add STM32 board support:
   - Go to **Settings → Additional boards manager URLs**
   - Add: `https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json`
3. Install STM32 boards:
   - **Tools → Board → Boards Manager**
   - Search and install **"STM32 MCU based boards"**
4. Select board:
   - **Tools → Board → STM32 boards → Generic STM32F1 series**
   - **Tools → Board part number → BluePill F103C8**
   - **Tools → Upload method → STLink**
5. Open `motorControl.ino` and upload to Blue Pill

## Repository Contents
- `/pcb` - KiCad PCB design files
  - Schematic files
  - PCB layout
  - 3D view renders
- `/firmware` - Embedded C code
  - `motorControl.ino` - Motor control firmware
- `/screenshots` - Project documentation images


## Author
Jad Haddad

## Contact
[Add contact information]
