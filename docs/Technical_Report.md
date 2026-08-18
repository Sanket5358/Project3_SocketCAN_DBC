# Technical Report

## Project 3: AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

---

## 1. Introduction

Controller Area Network (CAN) is widely used in automotive and embedded
systems for communication between electronic control units. Raw CAN
frames contain identifiers and hexadecimal data bytes, but these values
are difficult to understand without information about the signal
layout and physical scaling.

A DBC (CAN database) provides the information required to interpret CAN
messages. It defines message identifiers, signal positions, signal
lengths, scaling factors, offsets, physical ranges and engineering
units.

This project implements a Vehicle Information Network using SocketCAN,
a DBC database and a monitoring dashboard. AI assistance was used
during DBC development, validation, troubleshooting and documentation.

---

## 2. Objective

The main objective of the project is to demonstrate the complete
conversion of raw CAN frames into meaningful engineering values using
a DBC file.

The project demonstrates:

- CAN message design
- DBC database creation
- AI-assisted DBC development
- SocketCAN communication
- Raw CAN frame generation
- DBC-based decoding
- Engineering value visualization
- DBC modification
- AI-assisted DBC review

---

## 3. System Overview

The implemented system consists of three main software components:

1. CAN Transmitter
2. DBC Database
3. Monitoring Dashboard

The CAN transmitter generates vehicle information and transmits CAN
frames through the Linux SocketCAN virtual CAN interface `vcan0`.

The DBC database defines how the raw CAN data is interpreted.

The Python monitoring dashboard receives CAN frames, decodes them using
the DBC database and displays the engineering values.

### System Flow

Signal Generation
        ↓
CAN Transmitter
        ↓
SocketCAN / vcan0
        ↓
Raw CAN Frames
        ↓
DBC Database
        ↓
cantools Decoder
        ↓
Monitoring Dashboard
        ↓
Engineering Values

---

## 4. CAN Signal Design

The original Vehicle Information Network contains five required
signals. An additional Ambient Temperature signal was added as part of
Challenge 3.

| CAN ID | Signal | Length | Scaling | Offset | Range | Unit |
|---|---|---:|---:|---:|---|---|
| 0x100 | VehicleSpeed | 16 bit | 0.1 | 0 | 0–120 | km/h |
| 0x101 | EngineRPM | 16 bit | 1 | 0 | 800–5000 | rpm |
| 0x102 | CoolantTemperature | 16 bit | 0.1 | 0 | 20–120 | degC |
| 0x103 | FuelLevel | 8 bit | 1 | 0 | 0–100 | % |
| 0x104 | BatteryVoltage | 16 bit | 0.01 | 0 | 11–15 | V |
| 0x105 | AmbientTemperature | 16 bit | 0.1 | 0 | -20–60 | degC |

The physical value is calculated using:

Physical Value = Raw Value × Scaling + Offset

For example, Vehicle Speed uses a scaling factor of 0.1.
Therefore:

65 km/h → Raw Value = 650

Battery Voltage uses a scaling factor of 0.01:

12.5 V → Raw Value = 1250

---

## 5. DBC Implementation

The DBC file is stored at:

`dbc/vehicle_information.dbc`

The database contains six CAN messages and six corresponding signals.

The CAN identifiers are:

- 0x100 — VehicleSpeed
- 0x101 — EngineRPM
- 0x102 — CoolantTemperature
- 0x103 — FuelLevel
- 0x104 — BatteryVoltage
- 0x105 — AmbientTemperature

All signals use little-endian Intel byte ordering and unsigned
representation in the current implementation.

The DBC was validated using the `cantools` Python package.

---

## 6. SocketCAN Implementation

Linux SocketCAN was used as the CAN communication interface.

The project uses the virtual CAN interface:

`vcan0`

This allows CAN communication to be developed and tested without
requiring physical CAN hardware.

The transmitter is implemented in:

`src/can_transmitter.c`

The compiled transmitter executable is:

`./can_transmitter`

The transmitter periodically generates realistic vehicle parameters
and converts the physical values into raw CAN data according to the
defined scaling factors.

The CAN frames are then transmitted through `vcan0`.

---

## 7. DBC Decoding

The monitoring application is implemented in:

`src/dashboard.py`

The application uses:

- Python
- python-can
- cantools
- SocketCAN

The DBC database is loaded using cantools. Each received CAN frame is
matched with its CAN identifier and decoded according to the
corresponding signal definition.

The decoded values are then displayed using engineering units.

---

## 8. Monitoring Dashboard

The dashboard displays six vehicle parameters:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage
- Ambient Temperature

The dashboard also provides system information including:

- CAN interface status
- Number of received messages
- Decode error count
- DBC status
- CAN status

Example test values were:

Vehicle Speed       : 74.0 km/h
Engine RPM          : 800 rpm
Coolant Temperature : 85.0 degC
Fuel Level          : 50 %
Battery Voltage     : 14.60 V
Ambient Temperature : 27.0 degC

The dashboard reported:

Messages Received : 10117
Decode Errors     : 0
DBC Status        : ACTIVE
CAN Status        : ONLINE

---

## 9. Challenge 1 — Raw Data vs Decoded Data

The same CAN communication was observed in two forms.

### Raw CAN Data

Raw CAN frames contain the CAN identifier and hexadecimal data bytes.

Example:

ID: 0x100
DATA: ...

The hexadecimal data alone does not directly communicate the physical
meaning of the value.

### Decoded CAN Data

The DBC database provides the signal definition and scaling required to
convert the raw value into an engineering value.

For example:

Raw Value: 650

Scaling: 0.1

Decoded Vehicle Speed:

65 km/h

This demonstrates the importance of the DBC database.

---

## 10. Challenge 2 — DBC Modification

The DBC signal definitions were modified during the project to
demonstrate the effect of database parameters on decoded values.

A change in scaling affects the engineering value displayed by the
decoder even when the raw CAN frame remains unchanged.

This demonstrates that the transmitter and DBC must use matching
signal definitions.

An incorrect DBC can therefore result in incorrect engineering values
even when the CAN communication itself is functioning correctly.

---

## 11. Challenge 3 — Adding Ambient Temperature

Ambient Temperature was added as a new signal.

The new CAN message uses:

CAN ID: 0x105

Signal length: 16 bits

Scaling: 0.1

Range: -20 to 60 degC

Unit: degC

The transmitter, DBC and dashboard were updated.

The new signal was successfully decoded and displayed by the
monitoring dashboard.

Example:

Ambient Temperature : 27.0 degC

This demonstrated that adding a new signal requires coordinated
changes to the message generator, DBC database and visualization
application.

---

## 12. Challenge 4 — AI-Assisted DBC Review

The final DBC was reviewed using AI assistance.

The review covered:

- CAN identifiers
- Signal length
- Scaling
- Offset
- Physical ranges
- Units
- Naming
- Signal organization
- Possible inconsistencies

One important design observation was identified for
AmbientTemperature.

The signal currently uses an unsigned representation while its
physical range includes -20 degC. An unsigned zero-offset signal cannot
directly represent negative physical values.

For the current demonstration, the transmitter generates positive
ambient temperatures, so the implementation operates correctly within
the tested range.

The issue was documented as a possible future improvement.

The review also identified that related signals could be packed into
fewer CAN messages in a production system to improve bus utilization.
The current one-message-per-signal structure was retained because it
simplifies demonstration and debugging.

---

## 13. Validation and Test Results

The project was tested using:

- Linux SocketCAN
- vcan0
- CAN transmitter
- vehicle_information.dbc
- cantools
- Python monitoring dashboard

The final dashboard successfully displayed all six signals.

The dashboard test showed:

Messages Received : 10117
Decode Errors     : 0
DBC Status        : ACTIVE
CAN Status        : ONLINE

The cantools monitor also successfully decoded the CAN traffic.

A validation observation showed:

Received  : 598
Discarded : 0
Errors    : 0

These results demonstrate successful CAN transmission, DBC decoding
and signal visualization.

---

## 14. Software Structure

The final project is organized as follows:

Project3_SocketCAN_DBC/

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
└── README.md

---

## 15. AI Assistance

ChatGPT was used as an engineering assistance tool during the project.

The assistance included:

- DBC structure generation
- Signal definition review
- Scaling verification
- SocketCAN troubleshooting
- Python dashboard debugging
- DBC validation guidance
- AI-assisted DBC review
- Documentation preparation

AI-generated content was verified against the actual implementation.

The AI was not treated as a replacement for testing. Final decisions
were confirmed using SocketCAN, cantools and the monitoring dashboard.

---

## 16. Limitations

The current implementation uses a virtual CAN interface rather than
physical CAN hardware.

The AmbientTemperature signal has a documented signed/unsigned
representation issue for negative temperatures.

The one-message-per-signal design is simple but may not be optimal
for production automotive CAN networks.

The project uses simulated vehicle values rather than physical vehicle
sensors.

---

## 17. Future Improvements

Possible future improvements include:

- Use of physical CAN hardware
- Integration with real automotive sensors
- Packing multiple signals into optimized CAN messages
- Proper signed encoding for negative ambient temperatures
- CAN message cycle-time monitoring
- CAN error and bus-load monitoring
- Additional vehicle signals
- Graphical visualization
- Data logging and replay
- Hardware ECU integration

---

## 18. Conclusion

The project successfully demonstrates the complete workflow from CAN
signal definition to engineering-value visualization.

The implemented system combines SocketCAN, a DBC database, cantools,
a C-based CAN transmitter and a Python monitoring dashboard.

Six vehicle signals were successfully transmitted, decoded and
displayed.

The final testing showed zero decode errors and zero discarded frames
during the recorded validation.

AI assistance was used throughout development for database generation,
review, troubleshooting and documentation, while all important
changes were verified through actual SocketCAN testing.

The project therefore demonstrates the fundamental workflow used in
automotive CAN communication and DBC-based signal interpretation.
