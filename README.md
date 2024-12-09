# RFID Attendance System

## Description

This is a simple RFID-based attendance system built using an **Arduino** and an **RFID module** (e.g., MFRC522). The system allows users to register their attendance by scanning RFID cards or tags, and it records the attendance in a CSV file or a database (depending on the code).

## Features

- **RFID Scanning:** Users can register their attendance by scanning RFID tags/cards.
- **Attendance Logging:** The system logs the attendance data, which can be saved to a CSV file.
- **LED Indicator:** A green LED indicates successful attendance, and a red LED signals an error or invalid RFID tag.
- **LCD Display:** Displays user information and attendance status.

## Hardware Requirements

- **Arduino (e.g., Uno, Mega)**
- **MFRC522 RFID Module**
- **RFID Cards/Tags**
- **LCD Display (optional)**
- **LEDs (Green and Red)**
- **Buzzer (optional)**
- **Wires and Breadboard**
- **Power Source for Arduino**

## Software Requirements

- **Arduino IDE** to upload the code to your Arduino board.
- **Libraries:**
  - MFRC522 Library for RFID communication.
  - LiquidCrystal (if using an LCD).

## Installation Instructions

### Step 1: Install Libraries

1. Open the Arduino IDE.
2. Go to **Sketch** → **Include Library** → **Manage Libraries**.
3. Search for and install the following libraries:
   - **MFRC522** (for the RFID module).
   - **LiquidCrystal** (for LCD, if you're using it).

### Step 2: Connect the Hardware

1. **RFID Module (MFRC522):**
   - Connect the RFID module to your Arduino as follows:
     - SDA → Pin 10
     - SCK → Pin 13
     - MOSI → Pin 11
     - MISO → Pin 12
     - IRQ → Not connected
     - GND → Ground
     - RST → Pin 9
     - 3.3V → 3.3V on Arduino

2. **LEDs and Buzzer:**
   - Connect a green and red LED to the appropriate pins on the Arduino, and a buzzer if you want to add audio feedback.

### Step 3: Upload the Code

1. Open the Arduino IDE and load the code into the IDE.
2. Connect your Arduino board to the computer via USB.
3. Select the correct board and port in the Arduino IDE.
4. Click **Upload** to transfer the code to the Arduino board.

### Step 4: Test the System

- Scan an RFID tag and check if the system records the attendance correctly.

## Code Explanation

- **`rfid_attendance_system.ino`:** Main code to read RFID cards and store the attendance.
- **Data Logging:** The system logs data to a CSV file (or any other storage method you implement).

## Troubleshooting

- **Issue:** RFID not recognized.
  - **Solution:** Ensure your RFID module is properly connected and powered.
- **Issue:** Arduino not showing up in the IDE.
  - **Solution:** Check the USB connection, install drivers if necessary.

## Future Enhancements

- **Database Integration:** Store attendance data in a cloud database for real-time access.
- **Mobile App:** Develop a mobile app for checking attendance.
- **Admin Panel:** Create a web interface to manage and view attendance data.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Thanks to the community for open-source libraries like MFRC522 and LiquidCrystal.
- Special thanks to any tutorials or resources that helped build this project.
