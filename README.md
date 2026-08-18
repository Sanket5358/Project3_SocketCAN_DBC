
Project 3 — AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

A Linux-based automotive CAN communication project demonstrating how raw CAN frames are generated through SocketCAN, interpreted using a DBC database, decoded with cantools, and displayed as meaningful vehicle engineering values.
1. Project Overview

In an automotive CAN network, a CAN frame normally contains a CAN identifier and raw hexadecimal bytes. These bytes do not directly identify vehicle speed, engine RPM, temperature, fuel level, or battery voltage.

A DBC (CAN database) describes the message and signal structure required to interpret those bytes, including signal names, start bits, lengths, byte order, scaling, offsets, ranges, and units.

This project demonstrates the complete workflow:

Vehicle Signal Generation
          ↓
C CAN Transmitter
          ↓
Linux SocketCAN
          ↓
vcan0
          ↓
Raw CAN Frames
          ↓
DBC Database
          ↓
cantools Decoder
          ↓
Engineering Values
          ↓
Monitoring Dashboard

The project uses Linux Virtual CAN (vcan0), allowing the complete system to be tested without physical CAN hardware.
2. Problem Statement
AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

The objective is to design a Vehicle Information Network, create a DBC database with AI assistance, generate CAN traffic using SocketCAN, validate the database, decode the messages, and visualize the resulting engineering values.

The implementation covers:

    Understanding DBC files

    CAN message and signal design

    AI-assisted DBC development

    DBC validation

    SocketCAN communication

    Raw CAN frame generation

    DBC-based decoding

    Engineering-value visualization

    DBC modification and impact analysis

    Adding a new signal

    AI-assisted DBC review

3. Signals Implemented

The assignment specifies five vehicle signals. Ambient Temperature was added as part of Challenge 3.
CAN ID	Signal	Length	Scaling	Offset	Range	Unit
0x100	VehicleSpeed	16 bit	0.1	0	0–120	km/h
0x101	EngineRPM	16 bit	1	0	800–5000	rpm
0x102	CoolantTemperature	16 bit	0.1	0	20–120	°C
0x103	FuelLevel	8 bit	1	0	0–100	%
0x104	BatteryVoltage	16 bit	0.01	0	11–15	V
0x105	AmbientTemperature	16 bit	0.1	0	-20–60	°C
Encoding Formula

Physical Value = Raw Value × Scaling Factor + Offset
Raw Value = (Physical Value - Offset) / Scaling Factor

Examples:

Vehicle Speed:       65 km/h  → raw 650
Engine RPM:          2450 rpm → raw 2450
Coolant Temperature: 87 °C    → raw 870
Battery Voltage:     12.5 V   → raw 1250

4. Project Structure

Project3_SocketCAN_DBC/
│
├── can_transmitter
├── src/
│   ├── can_transmitter.c
│   └── dashboard.py
├── dbc/
│   ├── vehicle_information.dbc
│   └── vehicle_information_correct.dbc
├── docs/
│   ├── DBC_Summary.md
│   ├── Signal_Definition.md
│   ├── AI_DBC_Review.md
│   ├── AI_Usage_Report.md
│   └── Technical_Report.md
├── Makefile
├── README.md
└── .gitignore

File	Purpose
src/can_transmitter.c	Generates and transmits CAN messages
src/dashboard.py	Receives, decodes, and displays CAN signals
dbc/vehicle_information.dbc	Final CAN database
dbc/vehicle_information_correct.dbc	Corrected/reference DBC used during development
docs/DBC_Summary.md	DBC concepts and project summary
docs/Signal_Definition.md	Complete signal specification
docs/AI_Usage_Report.md	AI usage, corrections, and lessons learned
docs/AI_DBC_Review.md	AI-assisted DBC review
docs/Technical_Report.md	Technical project report
Makefile	Builds the C transmitter
5. Requirements
Operating System

Ubuntu/Linux with SocketCAN support.
Software

    GCC

    GNU Make

    Python 3

    Python virtual environment

    cantools

    python-can

    Linux SocketCAN utilities

6. Setup

Clone the repository:

git clone https://github.com/Sanket5358/Project3_SocketCAN_DBC.git
cd Project3_SocketCAN_DBC

Create and activate a virtual environment:

python3 -m venv .venv
source .venv/bin/activate

Install the Python dependencies:

python -m pip install --upgrade pip
pip install cantools python-can

Verify:

cantools --version

The development environment used for this project reported cantools 42.0.3.
7. Create the Virtual CAN Interface

Check interfaces:

ip link show

If vcan0 is not present:

sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

Verify:

ip link show vcan0

The project uses vcan0 as its SocketCAN interface.
8. Build the CAN Transmitter

From the project root:

make

The executable should be available as:

./can_transmitter

9. Run the CAN Transmitter

Make sure vcan0 is up and run:

./can_transmitter

The transmitter generates changing vehicle values and sends CAN messages using IDs 0x100 through 0x104. The Ambient Temperature message uses 0x105 in the updated implementation.

Example transmitter output:

===========================================
       VEHICLE INFORMATION CAN TRANSMITTER
===========================================
Vehicle Speed       : 116.0 km/h
Engine RPM          : 3650 rpm
Coolant Temperature : 91.5 C
Fuel Level          : 37 %
Battery Voltage     : 14.65 V
-------------------------------------------
CAN IDs             : 0x100 0x101 0x102 0x103 0x104
Status              : TRANSMITTING
===========================================

10. Observe Raw CAN Traffic

Open another terminal and run:

candump vcan0

Example:

vcan0  100   [2]  E8 03
vcan0  101   [2]  AC 0D
vcan0  102   [2]  E8 03
vcan0  103   [1]  14
vcan0  104   [2]  CD 05

These are raw CAN frames. The hexadecimal data needs the DBC definitions to become engineering values.
11. Decode Using the DBC

Activate the environment:

source .venv/bin/activate

Run:

cantools monitor dbc/vehicle_information.dbc \
    --interface socketcan \
    --channel vcan0

Example decoded output:

Received: 598, Discarded: 0, Errors: 0

AmbientTemperature
    AmbientTemperature: 29.0 degC

BatteryVoltage
    BatteryVoltage: 14.8 V

CoolantTemperature
    CoolantTemperature: 87.0 degC

EngineRPM
    EngineRPM: 1400 rpm

FuelLevel
    FuelLevel: 46 %

VehicleSpeed
    VehicleSpeed: 82.0 km/h

12. Start the Monitoring Dashboard

With the virtual environment active:

python3 src/dashboard.py

Example:

================================================
       VEHICLE INFORMATION MONITORING
================================================

Vehicle Speed       : 74.0 km/h
Engine RPM          : 800 rpm
Coolant Temperature : 85.0 degC
Fuel Level          : 50 %
Battery Voltage     : 14.60 V
Ambient Temperature : 27.0 degC

------------------------------------------------
CAN Interface       : vcan0
Messages Received   : 10117
Decode Errors       : 0

------------------------------------------------
DBC Database        : vehicle_information.dbc
DBC Status          : ACTIVE
CAN Status          : ONLINE
================================================
Press Ctrl+C to stop

13. Recommended Demonstration Setup

Use three terminals.
Terminal 1 — Transmitter

cd ~/Project3_SocketCAN_DBC
./can_transmitter

Terminal 2 — Raw CAN

candump vcan0

Terminal 3 — DBC Dashboard

cd ~/Project3_SocketCAN_DBC
source .venv/bin/activate
python3 src/dashboard.py

This demonstrates:

CAN Transmitter
      ↓
    vcan0
      ↓
Raw CAN Frames
      ↓
DBC Decoder
      ↓
Dashboard

14. DBC Validation

Check the final signal definitions:

source .venv/bin/activate
cantools --version
grep "^ SG_" dbc/vehicle_information.dbc

The final database contains six signals:

SG_ VehicleSpeed
SG_ EngineRPM
SG_ CoolantTemperature
SG_ FuelLevel
SG_ BatteryVoltage
SG_ AmbientTemperature

The live validation successfully decoded all six signals.
15. Challenge 1 — Raw Data vs Decoded Data
Raw view

vcan0  100  [2]  E8 03

This provides the interface, CAN identifier, data length, and raw bytes.
Decoded view

VehicleSpeed : 100.0 km/h

The DBC provides the signal position, length, scaling, offset, and unit required to interpret the raw bytes.
16. Challenge 2 — Modify the DBC

The VehicleSpeed scaling factor was modified during the project to demonstrate how a DBC definition affects decoded values.

Changing the scaling factor changes the engineering value displayed by the decoder even when the transmitted raw CAN bytes remain unchanged.

This demonstrates that the transmitter encoding and receiver DBC must match.
17. Challenge 3 — Add Ambient Temperature

Ambient Temperature was added as a new signal:

CAN ID   : 0x105
Length   : 16 bits
Scaling  : 0.1
Offset   : 0
Range    : -20 to 60 degC
Unit     : degC

The DBC, transmitter, and dashboard were updated. The signal was successfully transmitted, decoded, and displayed.

Example:

AmbientTemperature : 29.0 degC

18. Challenge 4 — AI-Assisted DBC Review

AI assistance was used to review the final DBC for:

    Possible errors

    Signal layout

    Scaling

    Offset

    Signal length

    Units

    Physical ranges

    Naming

    Documentation

    Potential improvements

One important design observation was identified: AmbientTemperature is currently defined as an unsigned signal while its documented physical range includes negative temperatures. An unsigned zero-offset representation cannot directly encode negative physical values.

The current transmitter demonstration uses positive ambient temperatures, so the tested implementation operates correctly in the demonstrated range. The limitation is documented in docs/AI_DBC_Review.md.

The review also identified that a production CAN network could pack related signals into fewer messages to improve bus utilization. The current one-message-per-signal design was retained because it keeps the educational demonstration simple and easy to debug.
19. AI Usage

AI tool: ChatGPT

AI assistance was used for:

    DBC syntax generation

    Signal definition review

    Scaling and offset checking

    DBC review

    SocketCAN troubleshooting

    Python dashboard debugging

    Documentation

    Challenge analysis

    Final DBC review

AI-generated information was verified against the actual implementation. The final project was tested using SocketCAN, vcan0, cantools, the DBC database, the CAN transmitter, and the monitoring dashboard.

The detailed record is available in:

docs/AI_Usage_Report.md

20. Validation Results
Test	Result
SocketCAN interface	PASS
CAN transmission	PASS
Raw CAN frame reception	PASS
DBC loading	PASS
Vehicle Speed decoding	PASS
Engine RPM decoding	PASS
Coolant Temperature decoding	PASS
Fuel Level decoding	PASS
Battery Voltage decoding	PASS
Ambient Temperature decoding	PASS
Dashboard operation	PASS
Decode errors	0
Discarded frames	0

Recorded validation examples:

Received  : 598
Discarded : 0
Errors    : 0

Dashboard validation:

Messages Received : 10117
Decode Errors     : 0
DBC Status        : ACTIVE
CAN Status        : ONLINE

21. Known Limitations

    The project uses vcan0 instead of physical CAN hardware.

    Vehicle values are simulated by the transmitter.

    Ambient Temperature has a documented signed/unsigned representation limitation for negative values.

    One CAN message is used for each signal.

    No physical vehicle sensors are connected.

    The dashboard is terminal based rather than a graphical GUI.

22. Future Improvements

    Physical CAN interface and CAN transceiver

    Real automotive sensors

    Proper signed encoding for Ambient Temperature

    Optimized multi-signal CAN messages

    CAN bus-load measurement

    CAN error monitoring

    Message timeout detection

    CAN data logging and replay

    Graphical dashboard

    Additional vehicle signals

    ECU integration

23. Learning Outcomes

This project provided practical experience in:

    Automotive CAN communication

    Linux SocketCAN

    Virtual CAN

    DBC database design

    CAN signal scaling

    Raw CAN frame analysis

    cantools

    Python CAN decoding

    C-based CAN transmission

    CAN monitoring

    Signal visualization

    AI-assisted engineering development

    Debugging and validation

The complete workflow is:

Signal Definition
        ↓
CAN Message Design
        ↓
DBC Creation
        ↓
SocketCAN Communication
        ↓
Raw CAN Frames
        ↓
DBC-Based Decoding
        ↓
Engineering Values
        ↓
Visualization

24. Documentation

Additional project documentation is available in docs/:
Document	Description
DBC_Summary.md	DBC concepts and project summary
Signal_Definition.md	Signal definitions and encoding formulas
AI_Usage_Report.md	AI tool usage, corrections, and lessons learned
AI_DBC_Review.md	AI-assisted DBC review
Technical_Report.md	Detailed technical report
Author

Sanket Chavan
Electronics and Telecommunication Engineering
Project 3 — AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN
