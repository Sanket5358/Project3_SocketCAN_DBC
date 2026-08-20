# AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

A Linux-based CAN communication and visualization project that demonstrates how raw CAN frames can be transformed into meaningful engineering values using a DBC (CAN Database).

The project uses Linux SocketCAN with the virtual CAN interface `vcan0`. A C-based transmitter generates vehicle information, while a DBC file defines the CAN messages and signals. Raw CAN traffic is monitored using `candump`, decoded using `cantools`, and displayed through a Python monitoring dashboard.

The project also demonstrates AI-assisted DBC generation and review, followed by actual SocketCAN-based verification.

---

## 1. Project Overview

In automotive and embedded systems, Electronic Control Units (ECUs) exchange information using CAN communication.

A raw CAN frame mainly contains:

- CAN Identifier
- Data Length Code (DLC)
- Data Payload

The hexadecimal payload alone does not directly provide the physical meaning of the data.

For example:

```text
CAN ID : 0x100
DATA   : Raw hexadecimal bytes2. Problem Statement

Raw CAN frames contain hexadecimal data that is difficult to interpret without information about the signal structure.

The objective of this project is to:

Design CAN messages for vehicle information.
Create a DBC database describing the CAN messages and signals.
Use AI to assist in DBC generation and review.
Validate the DBC definitions.
Generate CAN traffic using Linux SocketCAN.
Monitor raw CAN traffic.
Decode CAN messages using the DBC file.
Display decoded engineering values through a monitoring dashboard.
Study the effect of modifying DBC signal definitions.
Add and validate a new CAN signal.
3. Objectives

The main objectives of this project are:

Understand the purpose and structure of DBC files.
Design CAN messages and signal definitions.
Use AI to assist in DBC generation.
Review and validate AI-generated DBC content.
Generate CAN traffic using SocketCAN.
Use vcan0 for software-only CAN communication.
Monitor CAN traffic using candump.
Decode CAN messages using cantools.
Convert raw CAN data into engineering values.
Display decoded values using a Python dashboard.
Modify DBC definitions and observe their effect.
Add a new signal to an existing CAN database.
Demonstrate the complete CAN-to-DBC-to-visualization workflow.
4. System Description

The project implements a simple Vehicle Information Network.

The original assignment requires five vehicle signals:

Signal	Unit	Range
Vehicle Speed	km/h	0–120
Engine RPM	rpm	800–5000
Coolant Temperature	°C	20–120
Fuel Level	%	0–100
Battery Voltage	V	11–15

As part of Challenge 3 - Add a New Signal, an additional signal was implemented:

Signal	Unit	Range
Ambient Temperature	°C	-20–60

Therefore, the final project contains six CAN signals.

5. CAN Message Definition

The CAN message and signal definitions used in the project are:

CAN ID	Signal	Signal Length	Scaling	Offset	Range	Unit
0x100	VehicleSpeed	16 bit	0.1	0	0–120	km/h
0x101	EngineRPM	16 bit	1	0	800–5000	rpm
0x102	CoolantTemperature	16 bit	0.1	0	20–120	°C
0x103	FuelLevel	8 bit	1	0	0–100	%
0x104	BatteryVoltage	16 bit	0.01	0	11–15	V
0x105	AmbientTemperature	16 bit	0.1	0	-20–60	°C
CAN ID Allocation
0x100 → Vehicle Speed
0x101 → Engine RPM
0x102 → Coolant Temperature
0x103 → Fuel Level
0x104 → Battery Voltage
0x105 → Ambient Temperature
6. DBC File

The main DBC database is:

dbc/vehicle_information.dbc

A DBC file provides the information required to decode raw CAN data.

A typical signal definition has the following structure:

SG_ SignalName : StartBit|Length@ByteOrderSign
                (Scale,Offset)
                [Minimum|Maximum]
                "Unit"
                Receiver

Example:

SG_ VehicleSpeed : 0|16@1+ (0.1,0) [0|120] "km/h" Vector__XXX

This definition specifies:

Signal name: VehicleSpeed
Start bit: 0
Signal length: 16 bits
Byte order: Intel / little-endian
Signal type: unsigned
Scaling factor: 0.1
Offset: 0
Minimum: 0
Maximum: 120
Unit: km/h
7. Scaling and Offset

The physical engineering value is calculated using:

Physical Value = Raw Value × Scaling Factor + Offset

For example:

Raw Value = 650
Scaling   = 0.1
Offset    = 0

Therefore:

Physical Value = 650 × 0.1 + 0
               = 65 km/h

Scaling and offset allow raw CAN values to represent physical engineering quantities.

8. System Architecture

The system consists of a C-based CAN transmitter, Linux SocketCAN, the virtual CAN interface, raw CAN monitoring, a DBC database, a decoder, and a Python dashboard.

                    +----------------------+
                    | Vehicle Data         |
                    | Generator            |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    | CAN Transmitter      |
                    | can_transmitter.c    |
                    +----------+-----------+
                               |
                               v
                    +----------------------+
                    | Linux SocketCAN      |
                    |       vcan0          |
                    +----------+-----------+
                               |
                    +----------+----------+
                    |                     |
                    v                     v
              +-----------+       +---------------+
              | candump   |       | DBC Database  |
              | Raw CAN   |       | .dbc          |
              +-----------+       +-------+-------+
                                          |
                                          v
                                  +---------------+
                                  |   cantools    |
                                  |    Decoder    |
                                  +-------+-------+
                                          |
                                          v
                                  +---------------+
                                  | Python        |
                                  | Dashboard     |
                                  +---------------+
9. Software and Tools
Tool	Purpose
Ubuntu Linux	Development platform
C	CAN transmitter implementation
Python	Dashboard and decoding
SocketCAN	Linux CAN communication framework
vcan0	Virtual CAN interface
can-utils	CAN traffic monitoring
candump	Raw CAN frame monitoring
cantools	DBC loading and CAN decoding
Git	Version control
GitHub	Source-code repository
ChatGPT	AI-assisted DBC development
10. Project Directory Structure
Project3_SocketCAN_DBC/
│
├── dbc/
│   ├── vehicle_information.dbc
│   └── vehicle_information_correct.dbc
│
├── docs/
│   ├── AI_DBC_Review.md
│   ├── AI_Usage_Report.md
│   ├── DBC_Summary.md
│   ├── Signal_Definition.md
│   └── Technical_Report.md
│
├── src/
│   ├── can_transmitter.c
│   └── dashboard.py
│
├── Makefile
├── README.md
└── can_transmitter
11. SocketCAN and vcan0

SocketCAN is the CAN networking framework provided by Linux.

It allows CAN applications to communicate using Linux networking concepts.

For this project, a virtual CAN interface is used:

vcan0

The major advantage of vcan0 is that CAN communication can be developed and tested without physical CAN hardware.

Application
     ↓
SocketCAN
     ↓
vcan0
     ↓
CAN Frames

This makes it suitable for software development, debugging, and testing before physical CAN hardware is available.

12. CAN Transmitter

Source file:

src/can_transmitter.c

The CAN transmitter is responsible for:

Opening a CAN socket.
Connecting to vcan0.
Generating vehicle information.
Converting physical values into raw CAN values.
Creating CAN frames.
Transmitting the frames periodically.

The transmitter uses the following CAN IDs:

0x100
0x101
0x102
0x103
0x104
0x105

The generated values change during execution to represent changing vehicle information.

13. Raw CAN Traffic

Raw CAN traffic can be observed using:

candump vcan0

Example:

vcan0  100  [8]  XX XX XX XX XX XX XX XX
vcan0  101  [2]  XX XX
vcan0  102  [2]  XX XX
vcan0  103  [1]  XX
vcan0  104  [2]  XX XX
vcan0  105  [2]  XX XX

At this stage, the data is represented as raw hexadecimal bytes.

Without the DBC, the meaning of these bytes is not directly visible.

14. DBC-Based Decoding

The DBC database is loaded using cantools.

The decoding process is:

Raw CAN Frame
      ↓
CAN ID Matching
      ↓
DBC Message Definition
      ↓
Signal Extraction
      ↓
Scaling
      ↓
Offset
      ↓
Engineering Value

For example:

Raw CAN Frame
      ↓
CAN ID 0x100
      ↓
VehicleSpeed
      ↓
Raw Value × 0.1
      ↓
Vehicle Speed in km/h

This converts raw CAN data into meaningful engineering information.

15. CAN Data Visualization Dashboard

The Python dashboard is implemented in:

src/dashboard.py

The dashboard receives CAN messages, decodes them using the DBC database, and displays the engineering values.

Example:

----------------------------------------
       VEHICLE INFORMATION
----------------------------------------


Vehicle Speed       : 82.0 km/h
Engine RPM          : 1400 rpm
Coolant Temperature : 87.0 °C
Fuel Level          : 46 %
Battery Voltage     : 14.8 V
Ambient Temperature : 29.0 °C


----------------------------------------

The dashboard updates as new CAN messages are received.16. AI-Assisted DBC Development

AI was used as an engineering assistance tool during DBC development.

The AI was used for:

DBC syntax generation
Signal layout suggestions
Signal definition review
Documentation generation
Identification of possible DBC issues
DBC review and improvement

The AI-generated content was not accepted blindly.

The final DBC was checked using:

AI Assistance
      ↓
DBC Generation
      ↓
DBC Review
      ↓
cantools Validation
      ↓
SocketCAN Testing
      ↓
Final DBC

This ensured that the final DBC definitions were verified using actual CAN communication.

17. AI Usage Report

The detailed AI interaction is documented in:

docs/AI_Usage_Report.md

The report contains:

AI tool used
Prompts used
Generated outputs
Corrections performed
Validation process
Lessons learned

The main lesson was that AI can accelerate CAN database development, but AI-generated content must be verified using actual engineering tools and CAN communication tests.

18. DBC Validation

The DBC was validated using cantools and actual SocketCAN traffic.

Validation included:

DBC syntax
CAN message identifiers
Signal definitions
Signal lengths
Scaling factors
Offsets
Physical ranges
Engineering units
Actual CAN message decoding

The installed cantools version used during development was:

42.0.3

The validation workflow was:

DBC File
   ↓
cantools
   ↓
Syntax / Definition Check
   ↓
SocketCAN CAN Traffic
   ↓
DBC Decoding
   ↓
Engineering Value Verification
19. Challenge 1 — Raw Data vs Decoded Data

The same CAN communication was observed in two forms.

Raw CAN Data
CAN ID: 0x100
DATA: hexadecimal payload

This represents the actual bytes transmitted on the CAN interface.

DBC-Decoded Data
Vehicle Speed       : XX km/h
Coolant Temperature : XX °C

The difference is that raw CAN data contains bytes, while DBC decoding gives those bytes a defined signal meaning.

Therefore:

Raw CAN Data
      ↓
DBC Interpretation
      ↓
Engineering Value
20. Challenge 2 — Modify the DBC

A signal definition can be modified by changing parameters such as:

Scaling
Offset
Signal length
Unit
Range

For example:

Physical Value = Raw × Scale + Offset

If the scaling factor is changed, the same raw CAN data can result in a different displayed engineering value.

This demonstrates that the DBC defines how the receiver interprets the raw CAN payload.

21. Challenge 3 — Add a New Signal

The assignment required adding either:

Ambient Temperature

or:

Gear Position

The project added:

Ambient Temperature

using CAN ID:

0x105

The new signal was added to:

CAN message definition.
DBC file.
CAN transmitter.
Decoder.
Dashboard.

The signal was then tested using actual CAN traffic.

This demonstrates that the CAN database and software implementation must remain consistent when a new signal is introduced.

22. Challenge 4 — AI Review

The DBC was reviewed using AI to identify:

Possible errors
Signal layout issues
Missing documentation
Naming improvements
Potential limitations

The AI review is documented in:

docs/AI_DBC_Review.md

AI suggestions were evaluated and verified before being accepted.

The final engineering decision was based on actual DBC validation and SocketCAN testing.

23. Execution
Step 1 — Create the Virtual CAN Interface
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

Check the interface:

ip link show vcan0
Step 2 — Build the Project

From the project directory:

cd ~/Project3_SocketCAN_DBC
make

Check the transmitter:

ls -l can_transmitter
Step 3 — Start the CAN Transmitter
./can_transmitter

The transmitter starts generating and transmitting vehicle information over vcan0.

Step 4 — Monitor Raw CAN Traffic

Open another terminal:

candump vcan0

You should observe CAN messages with IDs:

0x100
0x101
0x102
0x103
0x104
0x105
Step 5 — Inspect the DBC
cantools dump dbc/vehicle_information.dbc

This displays the messages and signal definitions contained in the DBC file.

Step 6 — Run the Dashboard

Open another terminal:

cd ~/Project3_SocketCAN_DBC
python3 src/dashboard.py

The dashboard displays the decoded engineering values.

24. Results

The project successfully demonstrates:

CAN message generation.
Linux SocketCAN communication.
Software-only CAN communication using vcan0.
Raw CAN traffic monitoring.
DBC-based message interpretation.
Signal decoding using cantools.
Conversion of raw data into engineering values.
Continuous dashboard monitoring.
DBC modification and its effect on decoded values.
Addition of a new CAN signal.
AI-assisted DBC generation and review.
Verification of AI-assisted changes through actual SocketCAN testing.

The final workflow is:

Vehicle Values
      ↓
CAN Transmitter
      ↓
SocketCAN / vcan0
      ↓
Raw CAN Frames
      ↓
vehicle_information.dbc
      ↓
cantools
      ↓
Decoded Engineering Values
      ↓
Python Dashboard
25. Limitations

The project is a software-based demonstration and has the following limitations:

vcan0 does not represent a physical CAN bus.
No physical CAN transceiver or CAN controller hardware is used.
Vehicle values are simulated rather than measured from real sensors.
The system does not represent a production automotive CAN network.
Timing and bus-load behavior may differ from a physical CAN network.
The dashboard is intended for demonstration and educational purposes.
26. Future Improvements

Possible future improvements include:

Integration with physical CAN hardware.
Testing with a real CAN interface.
CAN FD support.
More realistic vehicle signal models.
Advanced graphical visualization.
Real-time signal plots.
CAN logging and playback.
Automated DBC validation.
Additional vehicle signals.
Integration with professional CAN analysis tools.
Automated regression testing for DBC changes.
27. Documentation Files

The project documentation is organized as follows:

File	Description
docs/DBC_Summary.md	DBC concepts and purpose
docs/Signal_Definition.md	CAN message and signal definitions
docs/AI_Usage_Report.md	AI tools, prompts, outputs, and corrections
docs/AI_DBC_Review.md	AI-assisted DBC review
docs/Technical_Report.md	Complete technical report
28. Deliverables

The project fulfills the required Problem Statement 3 deliverables.

1. DBC File
dbc/vehicle_information.dbc

Complete CAN database containing the vehicle information signals.

2. Source Code
src/can_transmitter.c
src/dashboard.py

The transmitter generates CAN traffic and the dashboard displays decoded values.

3. AI Usage Report
docs/AI_Usage_Report.md

Includes:

AI tool selected
Prompts used
Generated outputs
Corrections performed
Final observations
4. Technical Report
docs/Technical_Report.md

Includes:

Signal design
DBC structure
Validation process
SocketCAN integration
Visualization
Results
Lessons learned
5. Demonstration

The project demonstrates:

SocketCAN message transmission.
Raw CAN traffic.
DBC loading.
Signal decoding.
Signal visualization.
DBC modification and its impact.
AI-assisted DBC generation and review.
29. Learning Outcomes

After completing this project, the following concepts were demonstrated:

Purpose of DBC files.
CAN message and signal design.
DBC syntax.
Signal scaling and offset.
Linux SocketCAN.
Virtual CAN interfaces.
Raw CAN frame monitoring.
DBC-based CAN decoding.
Engineering value interpretation.
CAN data visualization.
AI-assisted engineering workflows.
DBC validation and verification.

The complete CAN workflow demonstrated by this project is:

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
Human Readable Signals
        ↓
Visualization and Analysis

This workflow is representative of the general process used in automotive CAN network development, testing, diagnostics, and validation.

30. Conclusion

This project demonstrates how a DBC database can transform raw CAN communication into meaningful engineering information.

Linux SocketCAN and the virtual vcan0 interface were used to generate and monitor CAN traffic without physical CAN hardware. A C-based transmitter generated vehicle information, while the DBC database defined how the CAN payload should be interpreted.

The cantools library was used to decode the transmitted messages according to the DBC definitions, and a Python dashboard was developed to display the resulting engineering values.

AI was used to assist with DBC generation, review, and documentation. However, AI-generated content was verified using actual SocketCAN communication and DBC decoding before being accepted.

The project therefore demonstrates the complete workflow:

CAN Signal Definition
        ↓
DBC Database
        ↓
CAN Transmission
        ↓
SocketCAN
        ↓
Raw CAN Traffic
        ↓
DBC Decoding
        ↓
Engineering Values
        ↓
Visualization

The project provides practical understanding of how DBC databases are used to interpret CAN communication during development, testing, analysis, and validation.

Author

Sanket Chavan

Project: AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

Technology: C, Python, Linux SocketCAN, vcan0, DBC, cantools
cd ~/Project3_SocketCAN_DBC
---

# Project Evidence and Screenshots

The following screenshots provide execution evidence for the SocketCAN, DBC generation, validation, decoding, visualization, and AI-assisted development tasks.

## 1. Virtual CAN Interface Setup

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/1_vcan0_setup.png" alt="vCAN0 Setup" width="900">

## 2. Project Build

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/2_project_build.png" alt="Project Build" width="900">

## 3. CAN Transmitter

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/3_can_transmitter.png" alt="CAN Transmitter" width="900">

## 4. Raw CAN Traffic

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/08a_raw_vs_decoded.png" alt="Raw CAN Traffic" width="900">

## 5. DBC File

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/5_dbc_file.png" alt="DBC File" width="900">

## 6. DBC Validation

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/6_dbc_validation.png" alt="DBC Validation" width="900">

## 7. DBC Decoded Dashboard

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/7_dashboard.png" alt="DBC Decoded Dashboard" width="900">

## 8. Raw CAN vs Decoded Data

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/08_raw_vs_decoded.png" alt="Raw CAN vs Decoded Data" width="900">

## 9. DBC Modification

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/09_dbc_modification.png" alt="DBC Modification" width="900">

## 10. Ambient Temperature Signal

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/10a_ambient_temperature.png" alt="Ambient Temperature Signal" width="900">

## 11. AI-Assisted DBC Generation

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/11_ai_dbc_generation.png" alt="AI-Assisted DBC Generation" width="900">

## 12. AI DBC Review

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/12_ai_dbc_review.png" alt="AI DBC Review" width="900">

## 13. Overall CAN Traffic

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/10_overall_can_traffic.png" alt="Overall CAN Traffic" width="900">

---
