# AI Usage Report

## Project 3

### AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

---

## 1. Purpose

Artificial Intelligence was used as an engineering assistance tool
during the development of the CAN DBC database and its supporting
documentation.

The AI assistance was used for DBC syntax generation, signal
definition review, validation guidance, troubleshooting, documentation,
and review of the final DBC implementation.

The generated content was verified against the actual SocketCAN
implementation before being used in the project.

---

## 2. AI Tool Used

AI Tool:

ChatGPT

Purpose of AI assistance:

- DBC structure generation
- CAN signal definition assistance
- DBC syntax review
- Scaling and offset verification
- SocketCAN troubleshooting
- Python dashboard debugging
- DBC validation guidance
- Documentation preparation
- Final DBC review

---

## 3. Initial Project Requirements

The project required a Vehicle Information Network containing the
following CAN signals:

| Signal | Unit | CAN ID |
|---|---|---|
| Vehicle Speed | km/h | 0x100 |
| Engine RPM | rpm | 0x101 |
| Coolant Temperature | degC | 0x102 |
| Fuel Level | % | 0x103 |
| Battery Voltage | V | 0x104 |

An additional signal was later added as part of Challenge 3:

| Signal | Unit | CAN ID |
|---|---|---|
| Ambient Temperature | degC | 0x105 |

---

## 4. AI Assistance for Signal Design

The AI was used to assist in defining the CAN signal parameters.

The following parameters were considered for each signal:

- CAN identifier
- Start bit
- Signal length
- Data type
- Scaling factor
- Offset
- Minimum value
- Maximum value
- Physical unit

The final signal definitions were checked against the transmitter
implementation.

---

## 5. Final Signal Definitions

| CAN ID | Signal | Length | Scaling | Offset | Range | Unit |
|---|---|---:|---:|---:|---|---|
| 0x100 | VehicleSpeed | 16 | 0.1 | 0 | 0–120 | km/h |
| 0x101 | EngineRPM | 16 | 1 | 0 | 800–5000 | rpm |
| 0x102 | CoolantTemperature | 16 | 0.1 | 0 | 20–120 | degC |
| 0x103 | FuelLevel | 8 | 1 | 0 | 0–100 | % |
| 0x104 | BatteryVoltage | 16 | 0.01 | 0 | 11–15 | V |
| 0x105 | AmbientTemperature | 16 | 0.1 | 0 | -20–60 | degC |

---

## 6. DBC Generation Assistance

AI assistance was used to construct the DBC message and signal
definitions.

The generated structure was then checked against the DBC syntax
required by cantools.

The final DBC contains:

- Six CAN messages
- Six corresponding signals
- Explicit scaling factors
- Physical ranges
- Engineering units
- Signal start positions
- Signal lengths
- Unsigned signal definitions

---

## 7. Corrections and Verification

AI-generated information was not accepted without verification.

The following checks were performed:

### Vehicle Speed

Scaling:

0.1 km/h per raw count

Example:

65 km/h → raw value 650

Status: Verified

### Engine RPM

Scaling:

1 rpm per raw count

Example:

2450 rpm → raw value 2450

Status: Verified

### Coolant Temperature

Scaling:

0.1 degC per raw count

Example:

87 degC → raw value 870

Status: Verified

### Fuel Level

Scaling:

1 % per raw count

Example:

72 % → raw value 72

Status: Verified

### Battery Voltage

Scaling:

0.01 V per raw count

Example:

12.5 V → raw value 1250

Status: Verified

### Ambient Temperature

Scaling:

0.1 degC per raw count

The signal was added as part of Challenge 3 and successfully decoded
using the DBC.

Status: Verified for the positive temperature range used during the
demonstration.

---

## 8. Troubleshooting Assistance

AI assistance was also used during implementation when problems were
encountered.

### SocketCAN Interface

The transmitter initially reported:

SIOCGIFINDEX failed: No such device

The issue was related to the SocketCAN interface configuration.

The project was subsequently operated using:

vcan0

The interface was verified using:

ip link show

---

## 9. Python Environment Issue

Installation of cantools using system pip resulted in the Ubuntu
externally-managed-environment restriction.

A Python virtual environment was therefore used.

The project environment became:

.venv

The installed cantools version was verified as:

42.0.3

The executable was verified using:

which cantools

---

## 10. Dashboard Debugging

During development, indentation errors were introduced while adding
AmbientTemperature to the dashboard.

The errors included:

- Unexpected indentation
- Incorrect indentation of the AmbientTemperature decoding block
- Incorrect placement of the except block

The dashboard was subsequently replaced with a clean implementation
containing all six decoded signals.

Python syntax was verified using:

python3 -m py_compile src/dashboard.py

The dashboard then operated successfully.

---

## 11. Challenge 3 AI Assistance

The project was extended with:

AmbientTemperature

CAN ID:

0x105

DBC definition:

Scaling: 0.1

Range: -20 to 60 degC

The transmitter and dashboard were updated to support the new signal.

Live testing successfully displayed AmbientTemperature values.

---

## 12. Challenge 4 AI-Assisted DBC Review

The final DBC was reviewed for:

- Signal definitions
- CAN identifiers
- Scaling
- Offset
- Signal length
- Physical ranges
- Units
- Naming
- Signal organization
- Possible inconsistencies

The review identified one important design observation.

AmbientTemperature is defined as an unsigned signal while its physical
range includes -20 degC.

An unsigned signal with zero offset cannot directly represent negative
physical values.

For the current demonstration, the transmitter generates positive
ambient temperatures, so the implementation works correctly.

This issue was documented rather than changing the working
demonstration.

---

## 13. Signal Layout Review

The project uses one CAN message for each signal:

0x100 → VehicleSpeed

0x101 → EngineRPM

0x102 → CoolantTemperature

0x103 → FuelLevel

0x104 → BatteryVoltage

0x105 → AmbientTemperature

This layout is simple and makes the project easy to understand and
debug.

For a production automotive network, related signals could be packed
into fewer messages to improve CAN bus utilization.

The current design was retained because it is suitable for the
assignment demonstration.

---

## 14. Validation Results

The final implementation was tested using SocketCAN, cantools, the
DBC database, and the monitoring dashboard.

The dashboard successfully displayed:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage
- Ambient Temperature

Example live dashboard values included:

Vehicle Speed: 74.0 km/h

Engine RPM: 800 rpm

Coolant Temperature: 85.0 degC

Fuel Level: 50 %

Battery Voltage: 14.60 V

Ambient Temperature: 27.0 degC

The dashboard reported:

Messages Received: 10117

Decode Errors: 0

DBC Status: ACTIVE

CAN Status: ONLINE

The cantools monitor also successfully decoded all six signals.

A validation observation showed:

Received: 598

Discarded: 0

Errors: 0

---

## 15. AI Suggestions Accepted

The following suggestions were accepted:

1. Use a structured DBC definition for all CAN signals.
2. Explicitly define scaling and physical ranges.
3. Validate the DBC using cantools.
4. Use a dedicated virtual environment for Python packages.
5. Add AmbientTemperature as an additional signal.
6. Review the final DBC for consistency before demonstration.
7. Document identified DBC limitations instead of hiding them.

---

## 16. AI Suggestions Not Directly Implemented

The suggestion to pack multiple signals into fewer CAN messages was
not implemented.

Reason:

The assignment is intended to demonstrate individual CAN messages,
DBC decoding, and signal visualization clearly.

Keeping one signal per message makes debugging and demonstration
simpler.

The AmbientTemperature signed/unsigned issue was also documented
rather than changing the current implementation because the transmitter
uses positive temperatures during the demonstration.

---

## 17. Lessons Learned

The AI-assisted development process provided the following practical
learning:

1. A DBC file is essential for converting raw CAN data into meaningful
   engineering values.

2. Scaling factors must match the transmitter encoding.

3. CAN IDs, signal lengths, scaling, units and ranges must be consistent
   between the transmitter and DBC.

4. AI-generated DBC content must always be verified before use.

5. cantools provides a practical method for validating and decoding
   DBC-based CAN traffic.

6. SocketCAN and vcan0 allow CAN communication to be developed and
   tested without physical CAN hardware.

7. A small DBC data-type inconsistency can affect the representation of
   physical values.

8. Separating the CAN transmitter, DBC database and monitoring
   dashboard makes troubleshooting easier.

---

## 18. Final Conclusion

AI was used as an engineering assistance tool rather than as a
replacement for implementation and verification.

The final DBC was manually checked against the SocketCAN transmitter
and validated using cantools.

The complete system successfully demonstrated:

Signal Definition
        ↓
CAN Message Design
        ↓
DBC Creation
        ↓
SocketCAN Transmission
        ↓
Raw CAN Frames
        ↓
DBC Decoding
        ↓
Engineering Values
        ↓
Monitoring Dashboard

The AI review also helped identify a limitation in the
AmbientTemperature signal definition and provided suggestions for
future improvement.

All important AI-assisted changes were verified through actual
SocketCAN testing before being considered part of the final project.
