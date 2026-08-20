




# Project Evidence and Screenshots

The following screenshots provide execution evidence for the SocketCAN communication, CAN traffic, DBC generation, DBC validation, signal decoding, visualization, DBC modification, and AI-assisted development.

## 1. Virtual CAN Interface Setup

<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/1_vcan0_setup.png" alt="Virtual CAN Interface Setup" width="900">

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

Very important

Do not paste the screenshot section inside:

```text
...
```

And don't put spaces before:

## 1. Virtual CAN Interface Setup

or:

<img src="...">

Test before committing

On GitHub's Edit README page, click Preview.

You should see:

1. Virtual CAN Interface Setup

followed by the actual terminal screenshot.

I verified that the underlying 7_dashboard.png itself is valid and publicly accessible, so the image file is not the problem.

The problem is definitely the README formatting/indentation.

create like battery project readme so screenshots seen 

Yes. I checked your live GitHub README, and now the exact problem is confirmed.
The real problem

From around line 212 onward, your README content has 4 spaces before every line. GitHub therefore treats almost the entire remaining README as a code block.

For example, GitHub is currently interpreting this:

    ## 35. Project Evidence and Screenshots
    <img src="...">

as code instead of:

## 35. Project Evidence and Screenshots

![...](screenshots/...)

That's why your images don't render. The PNG files themselves are already on GitHub.
Best solution

Let's make the README exactly like your Battery Monitoring project:

    Normal Markdown headings

    Normal paragraphs

    Normal tables

    Normal code blocks

    Relative image paths

    No HTML <img>

    No raw GitHub URLs

    No indentation before headings/images

    Screenshots directly displayed in README

For example:

## 1. Virtual CAN Interface Setup

![vCAN0 Setup](screenshots/1_vcan0_setup.png)

This is the cleanest approach.
Screenshot section you should use

# Project Evidence and Screenshots

The following screenshots provide execution evidence for the SocketCAN communication, CAN traffic, DBC generation, DBC validation, signal decoding, visualization, DBC modification, Ambient Temperature addition, and AI-assisted development.

## 1. Virtual CAN Interface Setup

![vCAN0 Setup](screenshots/1_vcan0_setup.png)

## 2. Project Build

![Project Build](screenshots/2_project_build.png)

## 3. CAN Transmitter

![CAN Transmitter](screenshots/3_can_transmitter.png)

## 4. Raw CAN Traffic

![Raw CAN Traffic](screenshots/08a_raw_vs_decoded.png)

## 5. DBC File

![DBC File](screenshots/5_dbc_file.png)

## 6. DBC Validation

![DBC Validation](screenshots/6_dbc_validation.png)

## 7. DBC Decoded Dashboard

![Dashboard](screenshots/7_dashboard.png)

## 8. Raw CAN vs Decoded Data

![Raw vs Decoded](screenshots/08_raw_vs_decoded.png)

## 9. DBC Modification

![DBC Modification](screenshots/09_dbc_modification.png)

## 10. Ambient Temperature Signal

![Ambient Temperature](screenshots/10a_ambient_temperature.png)

## 11. AI-Assisted DBC Generation

![AI DBC Generation](screenshots/11_ai_dbc_generation.png)

## 12. AI DBC Review

![AI DBC Review](screenshots/12_ai_dbc_review.png)

## 13. Overall CAN Traffic

![Overall CAN Traffic](screenshots/10_overall_can_traffic.png)

But don't just replace the screenshot section

Your whole README needs cleaning, because the indentation problem starts much earlier. The live README currently shows lines such as 2. Problem Statement, 3. Objectives, etc. as part of the indented block.
I recommend this exact approach

On your Ubuntu terminal:

cd ~/Project3_SocketCAN_DBC
nano README.md

Then replace the entire README with a clean version rather than trying to repair hundreds of individual lines.

I can give you the complete final README in one single code block, structured exactly like your Battery Monitoring README, with all your Project 3 content and the 13 screenshots using:

![Screenshot](screenshots/filename.png)

That is the version I recommend you paste into nano README.md.

give all readme file so i can copy paste as it is on github readme and seen large images on readme file

Yes. Below is a complete clean README.md. It uses the same simple Markdown image style as your Battery Monitoring project:

![Image](screenshots/filename.png)

This is preferable here because your screenshot files are already inside the repository's screenshots/ folder.

Important: Copy everything inside the single code block and replace your entire GitHub README.md. Do not add indentation before #, ##, or ![.

# AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

A Linux-based automotive CAN communication project demonstrating how raw CAN frames can be transformed into meaningful engineering values using a DBC (CAN Database).

The project uses Linux SocketCAN with the virtual CAN interface `vcan0`. A C-based transmitter generates vehicle information, while a DBC file defines CAN messages and signals. Raw CAN traffic is monitored using `candump`, decoded using `cantools`, and displayed through a Python monitoring dashboard.

The project also demonstrates AI-assisted DBC generation, validation, review, DBC modification, addition of a new signal, and visualization of decoded CAN data.

---

# 1. Project Overview

In automotive and embedded systems, Electronic Control Units (ECUs) exchange information using CAN communication.

A raw CAN frame mainly contains:

- CAN Identifier
- Data Length Code (DLC)
- Data Payload

Raw hexadecimal data is difficult to understand without information about the signal structure.

A DBC file provides the information required to interpret CAN messages and convert raw CAN data into meaningful engineering values.

The project demonstrates the complete workflow:

```text
Signal Definition
        ↓
CAN Message Design
        ↓
DBC Creation
        ↓
AI-Assisted Review
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

2. Problem Statement

The objective is to design a simple Vehicle Information Network using CAN communication.

The network contains the following signals:
Signal	Unit
Vehicle Speed	km/h
Engine RPM	rpm
Coolant Temperature	°C
Fuel Level	%
Battery Voltage	V

An additional signal, Ambient Temperature, is added as part of the challenge task.

The CAN messages are transmitted using Linux SocketCAN and decoded using a DBC file.
3. Objectives

The main objectives of this project are:

    Understand the purpose of DBC files.

    Design CAN messages and signals.

    Use AI to assist in DBC generation.

    Validate DBC definitions.

    Implement CAN communication using Linux SocketCAN.

    Generate realistic vehicle information values.

    Monitor raw CAN traffic.

    Decode CAN messages using a DBC file.

    Display decoded engineering values.

    Modify a DBC signal and observe its effect.

    Add Ambient Temperature as a new signal.

    Perform AI-assisted DBC review.

    Visualize the complete CAN communication workflow.

4. Learning Outcomes

After completing this project, the following concepts are demonstrated:

    DBC file structure

    CAN message design

    CAN signal definition

    CAN identifiers

    Start bits

    Signal lengths

    Scaling

    Offset

    Minimum and maximum values

    Engineering units

    Linux SocketCAN

    Virtual CAN

    Raw CAN traffic

    DBC decoding

    candump

    cantools

    Python CAN monitoring

    DBC validation

    DBC modification

    AI-assisted engineering workflow

5. System Description

The project implements a simple Vehicle Information Network.

The transmitter periodically generates and sends:

Vehicle Speed       : 0 - 120 km/h
Engine RPM          : 800 - 5000 rpm
Coolant Temperature : 20 - 120 °C
Fuel Level          : 0 - 100 %
Battery Voltage     : 11 - 15 V

The additional challenge signal is:

Ambient Temperature : °C

The values change during execution to simulate vehicle operation.
6. System Architecture

                 +----------------------+
                 |   C CAN Transmitter  |
                 +----------+-----------+
                            |
                            | CAN Frames
                            v
                 +----------------------+
                 |      SocketCAN       |
                 |        vcan0         |
                 +----------+-----------+
                            |
                +-----------+-----------+
                |                       |
                v                       v
       +----------------+       +----------------+
       |    candump     |       |    cantools    |
       | Raw CAN Frames |       | DBC Decoder    |
       +----------------+       +-------+--------+
                                        |
                                        v
                               +------------------+
                               | Python Dashboard |
                               +------------------+
                                        |
                                        v
                              Engineering Values

7. Project Directory Structure

Project3_SocketCAN_DBC/
│
├── dbc/
│   └── vehicle_information.dbc
│
├── docs/
│
├── screenshots/
│   ├── 1_vcan0_setup.png
│   ├── 2_project_build.png
│   ├── 3_can_transmitter.png
│   ├── 5_dbc_file.png
│   ├── 6_dbc_validation.png
│   ├── 7_dashboard.png
│   ├── 08_raw_vs_decoded.png
│   ├── 08a_raw_vs_decoded.png
│   ├── 09_dbc_modification.png
│   ├── 10_ambient_temperature.png
│   ├── 10a_ambient_temperature.png
│   ├── 10_overall_can_traffic.png
│   ├── 11_ai_dbc_generation.png
│   └── 12_ai_dbc_review.png
│
├── src/
│   ├── can_transmitter.c
│   └── dashboard.py
│
├── can_transmitter
├── Makefile
└── README.md

8. DBC File

The CAN database used in this project is:

dbc/vehicle_information.dbc

The DBC file defines the CAN messages and signals used by the Vehicle Information Network.

It contains information such as:

    CAN Identifier

    Message name

    Signal name

    Start bit

    Signal length

    Byte order

    Data type

    Scaling factor

    Offset

    Minimum value

    Maximum value

    Unit

The DBC file allows raw CAN frames to be decoded into meaningful engineering values.
9. CAN Signal Design

The project contains the following main signals:
Signal	Unit	Purpose
Vehicle Speed	km/h	Vehicle road speed
Engine RPM	rpm	Engine rotational speed
Coolant Temperature	°C	Engine coolant temperature
Fuel Level	%	Remaining fuel
Battery Voltage	V	Vehicle battery voltage
Ambient Temperature	°C	External temperature

The complete CAN ID, start bit, signal length, scaling, offset, range, and unit definitions are stored in:

dbc/vehicle_information.dbc

10. Required Signal Ranges

The assignment specifies:
Signal	Range	Unit
Vehicle Speed	0 - 120	km/h
Engine RPM	800 - 5000	rpm
Coolant Temperature	20 - 120	°C
Fuel Level	0 - 100	%
Battery Voltage	11 - 15	V

Ambient Temperature was added as an additional challenge signal.
11. What is a DBC File?

DBC stands for CAN Database.

A DBC file describes how CAN messages and signals are structured.

A DBC file tells a CAN tool:

    Which CAN ID represents a message

    Which bits contain a signal

    How many bits belong to the signal

    Whether the signal is signed or unsigned

    How raw values are converted

    What physical unit should be displayed

    What the valid signal range is

The relationship is:

CAN ID
   ↓
CAN Message
   ↓
Signal
   ↓
Raw Value
   ↓
Scaling + Offset
   ↓
Engineering Value

12. Why is a DBC Required?

Without a DBC file, a CAN tool may show only:

CAN ID: 0x200
DATA: XX XX

The meaning of the bytes is not directly known.

With a DBC file, the same data can be interpreted as:

Vehicle Speed: XX.X km/h

Therefore, a DBC file acts as a database describing the meaning of CAN data.
13. AI-Assisted DBC Development

AI was used to assist in creating and reviewing the DBC file.
AI Tool Used

ChatGPT

AI assistance was used for:

    DBC syntax generation

    Signal layout suggestions

    Scaling and offset review

    Range verification

    Unit verification

    Documentation

    DBC validation

    DBC review

    Naming improvements

AI-generated content was reviewed and verified before implementation.
14. Example AI Prompt

The following type of prompt was used:

Generate a valid DBC file for a Vehicle Information Network using
Linux SocketCAN.

Define signals for:

Vehicle Speed
Engine RPM
Coolant Temperature
Fuel Level
Battery Voltage

For each signal define:

CAN ID
Start Bit
Signal Length
Data Type
Scaling
Offset
Minimum
Maximum
Unit

Use realistic automotive engineering values.

Another review prompt was:

Review this DBC file for syntax errors, incorrect signal definitions,
scaling, offsets, ranges, units and possible improvements.

15. DBC Validation

The DBC file was checked for:

    Syntax correctness

    CAN message definitions

    Signal definitions

    CAN IDs

    Signal ranges

    Scaling factors

    Offsets

    Units

    Signal decoding

    Compatibility with the transmitter

    Compatibility with the dashboard

The final DBC was verified through actual SocketCAN communication and decoding.
16. SocketCAN Integration

The project uses Linux SocketCAN for CAN communication.

A virtual CAN interface is used:

vcan0

Virtual CAN allows CAN applications to be tested without physical CAN hardware.
17. Setting Up vcan0

The virtual CAN interface can be created using:

sudo modprobe can
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

Check the interface:

ip link show vcan0

The interface should appear as:

vcan0

18. CAN Transmitter

The CAN transmitter is implemented in:

src/can_transmitter.c

The transmitter:

    Opens a SocketCAN raw CAN socket.

    Connects to vcan0.

    Generates vehicle information.

    Encodes the values into CAN data bytes.

    Creates CAN frames.

    Sends the frames periodically.

The executable is:

can_transmitter

19. Building the Project

The transmitter can be compiled using GCC.

Example:

gcc src/can_transmitter.c -o can_transmitter

Run the transmitter:

./can_transmitter

The transmitter continuously sends CAN messages.
20. Monitoring Raw CAN Traffic

Raw CAN traffic can be monitored using:

candump vcan0

Example:

vcan0  200   [2]  XX XX
vcan0  201   [2]  XX XX
vcan0  300   [1]  XX
vcan0  301   [1]  XX
vcan0  400   [1]  XX

The exact values change during execution.
21. Raw CAN Data vs Decoded Data
Raw CAN

CAN ID: 0x200
DATA: XX XX

Raw hexadecimal bytes do not directly indicate the physical meaning.
Decoded CAN

The DBC file converts the raw value into an engineering value:

Vehicle Speed: XX.X km/h

The process is:

Raw CAN Frame
      ↓
CAN ID
      ↓
DBC Message
      ↓
DBC Signal
      ↓
Raw Signal Value
      ↓
Scaling + Offset
      ↓
Engineering Value

22. Python Dashboard

The monitoring dashboard is implemented in:

src/dashboard.py

The dashboard uses:

Python
cantools
SocketCAN
DBC database

The dashboard receives CAN frames from vcan0, decodes them using the DBC file, and displays engineering values.
23. Installing cantools

Install the required Python library:

python3 -m pip install cantools

If required:

python3 -m pip install --user cantools

The cantools package provides DBC decoding support and the cantools command-line utility.
24. Running the Dashboard

Run:

python3 src/dashboard.py

The dashboard displays decoded vehicle information.

Example:

===============================================
       VEHICLE INFORMATION MONITORING
===============================================

Vehicle Speed       : XX.X km/h
Engine RPM          : XXXX rpm
Coolant Temperature : XX.X °C
Fuel Level          : XX %
Battery Voltage     : XX.X V
Ambient Temperature : XX.X °C

CAN Interface       : vcan0
DBC Database        : vehicle_information.dbc

===============================================

The values update automatically as CAN messages are received.
25. Signal Monitoring Dashboard

The dashboard provides a human-readable representation of the CAN network.

It displays:

    Vehicle Speed

    Engine RPM

    Coolant Temperature

    Fuel Level

    Battery Voltage

    Ambient Temperature

It also provides CAN and DBC status information.
26. DBC Modification Challenge

The assignment requires modifying one DBC signal definition.

Possible modifications include:

    Scaling

    Offset

    Unit

    Signal length

The same raw CAN data can produce a different displayed engineering value if the DBC definition is changed.

Example:

Same Raw CAN Frame
        ↓
Original DBC
        ↓
Original Engineering Value

After modification:

Same Raw CAN Frame
        ↓
Modified DBC
        ↓
Different Engineering Value

This demonstrates why correct DBC definitions are important.
27. Adding Ambient Temperature

As part of the challenge task, the project adds:

Ambient Temperature

The new signal is integrated into:

    DBC file

    CAN transmitter

    DBC decoding

    Python dashboard

    Documentation

The dashboard displays the decoded Ambient Temperature value.
28. AI DBC Review

The final DBC was reviewed using AI.

The review checked:

    Possible syntax errors

    Incorrect signal definitions

    Incorrect scaling

    Incorrect offsets

    Incorrect ranges

    Incorrect units

    Signal layout

    Naming

    Documentation

The AI suggestions were evaluated before being applied.

Actual SocketCAN communication was used for final verification.
29. Complete Validation Workflow

DBC Design
    ↓
AI-Assisted Generation
    ↓
Human Review
    ↓
DBC Validation
    ↓
CAN Transmitter
    ↓
SocketCAN
    ↓
vcan0
    ↓
Raw CAN Traffic
    ↓
candump
    ↓
cantools
    ↓
DBC Decoding
    ↓
Python Dashboard
    ↓
Engineering Values

30. Demonstration Procedure
Step 1 - Start vcan0

ip link show vcan0

Step 2 - Start the CAN transmitter

./can_transmitter

Step 3 - Monitor raw CAN traffic

candump vcan0

Step 4 - Start the dashboard

python3 src/dashboard.py

Step 5 - Observe decoded values

Observe:

Vehicle Speed
Engine RPM
Coolant Temperature
Fuel Level
Battery Voltage
Ambient Temperature

Step 6 - Compare raw and decoded data

Compare the candump output with the dashboard values.
Step 7 - Modify the DBC

Change one signal definition and observe the effect.
Step 8 - Demonstrate Ambient Temperature

Show the signal in the DBC, transmitter, and dashboard.
Step 9 - Demonstrate AI assistance

Show the AI generation and review process.
31. Technologies Used
Technology	Purpose
C	CAN transmitter
Python	Monitoring dashboard
Linux	Development environment
SocketCAN	CAN communication
vcan0	Virtual CAN interface
can-utils	CAN traffic monitoring
cantools	DBC decoding
DBC	CAN database
Git	Version control
GitHub	Repository
ChatGPT	AI-assisted DBC development
32. Software Requirements

Required software:

Ubuntu / Linux
GCC
Python 3
SocketCAN
can-utils
cantools
Git

Install CAN utilities:

sudo apt install can-utils

Install cantools:

python3 -m pip install cantools

33. Project Evidence and Screenshots

The following screenshots provide execution evidence for the complete project.
33.1 Virtual CAN Interface Setup

vCAN0 Setup
33.2 Project Build

Project Build
33.3 CAN Transmitter

CAN Transmitter
33.4 Raw CAN Traffic

Raw CAN Traffic
33.5 DBC File

DBC File
33.6 DBC Validation

DBC Validation
33.7 DBC Decoded Dashboard

DBC Decoded Dashboard
33.8 Raw CAN vs Decoded Data

Raw CAN vs Decoded Data
33.9 DBC Modification

DBC Modification
33.10 Ambient Temperature Signal

Ambient Temperature
33.11 AI-Assisted DBC Generation

AI-Assisted DBC Generation
33.12 AI DBC Review

AI DBC Review
33.13 Overall CAN Traffic

Overall CAN Traffic
34. Assignment Deliverables
34.1 DBC File

Complete CAN database:

dbc/vehicle_information.dbc

34.2 Source Code
CAN Transmitter

src/can_transmitter.c

CAN Monitoring Dashboard

src/dashboard.py

34.3 AI Usage Report

The AI-assisted development includes:

    AI tool selected

    Prompts used

    DBC generation

    DBC review

    Corrections performed

    Validation

    Final observations

34.4 Technical Report

The project documentation includes:

    Signal design

    DBC structure

    AI-assisted generation

    DBC validation

    SocketCAN integration

    Raw CAN traffic

    DBC decoding

    Dashboard visualization

    DBC modification

    Ambient Temperature signal

    Lessons learned

34.5 Demonstration

The project demonstrates:

    SocketCAN message transmission

    Raw CAN traffic

    DBC import and use

    Signal decoding

    Signal visualization

    DBC modification and impact

    Ambient Temperature addition

    AI-assisted DBC generation

    AI-assisted DBC review

35. Challenges Completed
Challenge 1 - Raw Data vs Decoded Data

Raw CAN traffic was compared with DBC-decoded engineering values.
Challenge 2 - Modify the DBC

A DBC signal definition was modified and the effect on the decoded value was observed.
Challenge 3 - Add a New Signal

Ambient Temperature was added to the DBC and integrated into the CAN communication and monitoring system.
Challenge 4 - AI Review

AI was used to review the DBC for:

    Errors

    Signal definition problems

    Scaling

    Offset

    Range

    Units

    Naming

    Documentation

36. Lessons Learned

The project demonstrates the importance of a DBC database in automotive CAN communication.

Important observations include:

    Raw CAN frames contain hexadecimal data.

    The DBC provides the meaning of the data.

    Scaling and offset convert raw values into physical values.

    SocketCAN provides a Linux interface for CAN communication.

    vcan0 allows CAN communication to be tested without physical CAN hardware.

    candump is useful for monitoring raw CAN frames.

    cantools provides DBC-based decoding.

    Incorrect DBC definitions can produce incorrect engineering values.

    AI can assist with DBC development and review.

    AI-generated definitions must be verified.

    Adding a new signal requires updates to the DBC, transmitter, decoder, and visualization.

37. Complete CAN Workflow

The complete workflow implemented in this project is:

Signal Definition
        ↓
CAN Message Design
        ↓
DBC Creation
        ↓
AI-Assisted Review
        ↓
DBC Validation
        ↓
SocketCAN Communication
        ↓
Raw CAN Frames
        ↓
DBC-Based Decoding
        ↓
Engineering Values
        ↓
Python Visualization

38. Conclusion

This project demonstrates an end-to-end automotive CAN communication and DBC decoding workflow using Linux SocketCAN.

A C-based transmitter generates vehicle information and sends CAN frames through the virtual vcan0 interface.

The DBC file defines how the raw CAN data should be interpreted.

The candump utility is used to monitor raw CAN traffic, while cantools is used for DBC-based decoding.

A Python monitoring dashboard displays the decoded engineering values.

The project also demonstrates:

    AI-assisted DBC generation

    DBC validation

    AI-assisted DBC review

    Raw CAN traffic monitoring

    DBC decoding

    DBC modification

    Ambient Temperature signal addition

    Real-time signal visualization

The project therefore demonstrates the complete workflow from:

CAN Signal Definition
        ↓
DBC Database
        ↓
SocketCAN Communication
        ↓
Raw CAN Data
        ↓
DBC Decoding
        ↓
Engineering Values
        ↓
Visualization

39. Author

Sanket Chavan

Electronics and Telecommunication Engineering

Project:

AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN
40. Repository

GitHub Repository:

https://github.com/Sanket5358/Project3_SocketCAN_DBC
41. Project Summary

This project provides practical experience with:

C
Python
Linux
SocketCAN
CAN
vcan0
DBC
cantools
can-utils
Git
GitHub
AI-assisted engineering

It demonstrates how raw automotive CAN communication can be transformed into meaningful engineering information using a DBC database.


### One very important thing before you paste

Use **GitHub's README editor**, not the terminal's existing broken content:

**GitHub → `README.md` → ✏️ Edit → Ctrl+A → paste the complete README above → Preview changes.**

In the preview, the screenshots should appear under:

**33.1 Virtual CAN Interface Setup**

**33.7 DBC Decoded Dashboard**

**33.11 AI-Assisted DBC Generation**

etc.

If the first screenshot appears in Preview, **all the relative `screenshots/...png` # AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

A Linux-based automotive CAN communication project that demonstrates how raw CAN frames can be transformed into meaningful engineering values using a DBC (CAN Database).

The project uses **Linux SocketCAN**, a virtual CAN interface (`vcan0`), a C-based CAN transmitter, a DBC database, the `candump` CAN monitoring utility, the `cantools` Python library, and a Python-based vehicle information monitoring dashboard.

The project also demonstrates **AI-assisted DBC generation, DBC validation, DBC review, signal modification, addition of a new signal, raw CAN traffic analysis, and decoded signal visualization**.

---

# 1. Project Overview

In automotive and embedded systems, Electronic Control Units (ECUs) exchange information using the Controller Area Network (CAN).

A raw CAN frame contains mainly:

- CAN Identifier
- Data Length Code (DLC)
- Data bytes

Raw hexadecimal data does not directly explain what the individual bits and bytes represent.

For example:

```textWithout additional information, it is difficult to determine whether the bytes represent vehicle speed, engine RPM, temperature, voltage, or another signal.

A DBC file solves this problem by defining:

CAN messages
CAN identifiers
Signals
Start bits
Signal lengths
Byte order
Signed/unsigned representation
Scaling factors
Offsets
Minimum and maximum values
Physical units
Signal names

The overall workflow of this project is:

Vehicle Signals
       |
       v
CAN Message Design
       |
       v
DBC File
       |
       v
C CAN Transmitter
       |
       v
Linux SocketCAN
       |
       v
vcan0
       |
       +----------------------+
       |                      |
       v                      v
   candump                cantools
Raw CAN Frames          DBC Decoding
       |                      |
       +----------+-----------+
                  |
                  v
       Engineering Values
                  |
                  v
       Python Monitoring
           Dashboard
2. Problem Statement

The objective of this project is to design a simple Vehicle Information Network and demonstrate the complete process of transmitting, decoding, and visualizing CAN signals.

The project implements the following vehicle information signals:

Signal	Unit
Vehicle Speed	km/h
Engine RPM	rpm
Coolant Temperature	°C
Fuel Level	%
Battery Voltage	V

The project also implements the challenge signal:

Additional Signal	Unit
Ambient Temperature	°C

The values are generated by a C-based CAN transmitter and transmitted periodically through the Linux virtual CAN interface vcan0.

The DBC file is then used to decode the raw CAN frames into meaningful engineering values.

3. Objectives

The main objectives of the project are:

Understand the purpose of a DBC file.
Design CAN messages and signals.
Use AI to assist in DBC generation.
Validate the generated DBC file.
Implement CAN communication using Linux SocketCAN.
Generate realistic vehicle information values.
Monitor raw CAN frames using candump.
Decode CAN messages using the DBC file.
Display decoded engineering values.
Modify a DBC signal and observe the effect.
Add Ambient Temperature as a new signal.
Demonstrate AI-assisted DBC review.
Visualize the complete CAN communication workflow.
4. Learning Outcomes

After completing this project, the following concepts are demonstrated:

DBC file structure
CAN message design
CAN signal definition
CAN identifiers
Signal encoding
Signal decoding
Scaling and offset
Physical units
Linux SocketCAN
Virtual CAN interface
Raw CAN traffic
DBC-based decoding
candump
Python cantools
CAN data visualization
DBC validation
DBC modification
AI-assisted engineering workflow
5. System Description

The project models a simple automotive Vehicle Information Network.

The transmitter generates vehicle-related information and sends it through CAN.

The main signals are:

Vehicle Speed       : 0 - 120 km/h
Engine RPM          : 800 - 5000 rpm
Coolant Temperature : 20 - 120 °C
Fuel Level          : 0 - 100 %
Battery Voltage     : 11 - 15 V

The additional challenge signal is:

Ambient Temperature : °C

The values change during execution to simulate realistic vehicle conditions.

6. Project Architecture
                 +----------------------+
                 |   C CAN Transmitter  |
                 +----------+-----------+
                            |
                            | CAN Frames
                            v
                 +----------------------+
                 |      SocketCAN       |
                 |        vcan0         |
                 +----------+-----------+
                            |
                +-----------+-----------+
                |                       |
                v                       v
       +----------------+       +----------------+
       |    candump     |       |    cantools    |
       | Raw CAN Frames |       | DBC Decoder    |
       +----------------+       +-------+--------+
                                        |
                                        v
                               +------------------+
                               | Python Dashboard |
                               +------------------+
                                        |
                                        v
                              Engineering Values
7. Project Directory Structure
Project3_SocketCAN_DBC/
│
├── dbc/
│   └── vehicle_information.dbc
│
├── docs/
│
├── screenshots/
│   ├── 1_vcan0_setup.png
│   ├── 2_project_build.png
│   ├── 3_can_transmitter.png
│   ├── 5_dbc_file.png
│   ├── 6_dbc_validation.png
│   ├── 7_dashboard.png
│   ├── 08_raw_vs_decoded.png
│   ├── 08a_raw_vs_decoded.png
│   ├── 09_dbc_modification.png
│   ├── 10_ambient_temperature.png
│   ├── 10a_ambient_temperature.png
│   ├── 10_overall_can_traffic.png
│   ├── 11_ai_dbc_generation.png
│   └── 12_ai_dbc_review.png
│
├── src/
│   ├── can_transmitter.c
│   └── dashboard.py
│
├── can_transmitter
├── Makefile
└── README.md
8. DBC File

The DBC file used in this project is:

dbc/vehicle_information.dbc

The DBC database defines the CAN messages and signals required by the Vehicle Information Network.

The DBC file provides the information required to convert raw CAN data into engineering values.

It contains definitions for:

CAN messages
CAN identifiers
Signal names
Signal positions
Signal lengths
Byte order
Data type
Scaling
Offset
Minimum value
Maximum value
Units

The DBC file is the link between raw CAN communication and human-readable vehicle information.

9. CAN Message Design

The project uses separate CAN messages for the vehicle information signals.

The main CAN identifiers observed during execution include:

0x200
0x201
0x300
0x301
0x400

The exact signal layout, start bits, signal lengths, scaling factors, offsets, ranges, and units are defined in:

dbc/vehicle_information.dbc

The major signals are:

Signal	Unit	Description
Vehicle Speed	km/h	Vehicle road speed
Engine RPM	rpm	Engine rotational speed
Coolant Temperature	°C	Engine coolant temperature
Fuel Level	%	Remaining fuel level
Battery Voltage	V	Vehicle battery voltage
Ambient Temperature	°C	External/ambient temperature
10. Required Signal Ranges

The assignment specifies the following operating ranges:

Signal	Required Range	Unit
Vehicle Speed	0 - 120	km/h
Engine RPM	800 - 5000	rpm
Coolant Temperature	20 - 120	°C
Fuel Level	0 - 100	%
Battery Voltage	11 - 15	V

Ambient Temperature was added as an additional challenge signal.

11. Understanding a DBC File

DBC stands for CAN Database.

A DBC file describes how CAN messages and signals are organized.

A DBC database allows software tools to understand:

CAN ID
   |
   +---- Message
           |
           +---- Signal
                  |
                  +---- Start Bit
                  +---- Length
                  +---- Byte Order
                  +---- Data Type
                  +---- Scale
                  +---- Offset
                  +---- Range
                  +---- Unit

Without a DBC file, CAN tools can display only raw hexadecimal information.

With a DBC file, the same raw data can be displayed as:

Vehicle Speed       : 78.0 km/h
Engine RPM          : 1850 rpm
Coolant Temperature : 94.5 °C
Fuel Level          : 31 %
Battery Voltage     : 14.30 V
Ambient Temperature : 34.0 °C
12. Raw CAN Data vs Decoded Data
Raw CAN Frame

A raw CAN frame may appear as:

vcan0  200   [2]  4E 00

The hexadecimal bytes alone do not directly tell the user the physical engineering value.

DBC-Decoded Data

Using the DBC file, the same CAN message can be interpreted as an engineering value.

For example:

Vehicle Speed : 78.0 km/h

The DBC provides the conversion between the raw CAN value and the physical value.

Therefore:

Raw CAN Bytes
      |
      v
DBC Signal Definition
      |
      v
Scaling + Offset
      |
      v
Engineering Value
13. AI-Assisted DBC Generation

Artificial Intelligence was used to assist with the development of the DBC database.

The AI tool used for this project was:

ChatGPT

AI assistance was used for:

DBC syntax generation
CAN message organization
Signal layout suggestions
Scaling and offset review
Range verification
Unit verification
DBC documentation
DBC review
Identification of possible errors
Improvement suggestions

AI-generated content was not accepted blindly.

The generated DBC was reviewed against the project requirements and tested using actual SocketCAN communication.

14. AI Usage Method

The development workflow was:

Project Requirements
        |
        v
AI Prompt
        |
        v
AI-Generated DBC
        |
        v
Human Review
        |
        v
DBC Corrections
        |
        v
SocketCAN Testing
        |
        v
DBC Validation

The purpose of AI assistance was to reduce manual DBC syntax errors and improve the documentation and review process.

15. Example AI Prompt

An example prompt used during development was:

Generate a valid DBC file for a Vehicle Information Network using
Linux SocketCAN.


Define signals for:


Vehicle Speed
Engine RPM
Coolant Temperature
Fuel Level
Battery Voltage


For each signal define:
CAN ID
start bit
signal length
data type
scaling
offset
minimum
maximum
unit


Use realistic automotive engineering values.

A second review prompt was used to check:

Review this DBC file for syntax errors, incorrect signal definitions,
scaling, offsets, ranges, units, overlapping signals, and possible
improvements.
16. DBC Validation

The DBC file was validated before being used for final visualization.

The validation process checked:

DBC syntax
CAN message definitions
Signal definitions
Signal ranges
Scaling factors
Offsets
Units
Message identifiers
Signal decoding
Compatibility with the transmitter
Compatibility with the dashboard

The validation screenshots are included in the project evidence section.

17. SocketCAN Integration

The project uses Linux SocketCAN for CAN communication.

SocketCAN provides a standard CAN networking interface in Linux.

The project uses the virtual CAN interface:

vcan0

This allows CAN communication to be tested without physical CAN hardware.

The virtual CAN interface can be checked using:

ip link show vcan0

A successful setup shows the vcan0 interface.

18. Setting Up vcan0

Example commands:

sudo modprobe can
sudo modprobe vcan
sudo ip link add dev vcan0 type vcan
sudo ip link set up vcan0

Check the interface:

ip link show vcan0

Expected interface:

vcan0
19. CAN Traffic Monitoring

Raw CAN traffic is monitored using:

candump vcan0

Example:

vcan0  200   [2]  4E 00
vcan0  201   [1]  39
vcan0  300   [1]  5E
vcan0  301   [1]  1F
vcan0  400   [1]  04

The actual values change during transmitter execution.

This demonstrates that multiple CAN messages are being transmitted on the same virtual CAN network.

20. CAN Transmitter

The CAN transmitter is implemented in:

src/can_transmitter.c

The transmitter:

Opens a SocketCAN raw CAN socket.
Connects to vcan0.
Generates vehicle information.
Encodes values into CAN data bytes.
Creates CAN frames.
Transmits the frames periodically.

The compiled executable is:

can_transmitter
21. Building the Transmitter

The transmitter can be compiled using GCC.

Example:

gcc src/can_transmitter.c -o can_transmitter

Run:

./can_transmitter

The transmitter sends CAN frames continuously.

22. Python Dashboard

The monitoring dashboard is implemented in:

src/dashboard.py

The dashboard uses:

Python
cantools
SocketCAN
DBC database

The dashboard receives CAN frames from vcan0, decodes them using:

dbc/vehicle_information.dbc

and displays engineering values.

23. Installing cantools

The Python dashboard requires the cantools library.

Install it using:

python3 -m pip install cantools

If required:

python3 -m pip install --user cantools

The command-line cantools utility is also provided by the package.

24. Running the Dashboard

Run:

python3 src/dashboard.py

The dashboard displays values such as:

====================================================
          VEHICLE INFORMATION MONITORING
====================================================


Vehicle Speed       : 78.0 km/h
Engine RPM          : 1850 rpm
Coolant Temperature : 94.5 degC
Fuel Level          : 31 %
Battery Voltage     : 14.30 V
Ambient Temperature : 34.0 degC


----------------------------------------------------
CAN Interface       : vcan0
Messages Received   : 54
Decode Errors       : 0
----------------------------------------------------
DBC Database        : vehicle_information.dbc
DBC Status          : ACTIVE
CAN Status          : ONLINE
====================================================
Press Ctrl+C to stop

The displayed values update as CAN messages are received.

25. Signal Monitoring Dashboard

The dashboard provides a human-readable representation of the CAN network.

Example:

Vehicle Speed       : 78.0 km/h
Engine RPM          : 1850 rpm
Coolant Temperature : 94.5 degC
Fuel Level          : 31 %
Battery Voltage     : 14.30 V
Ambient Temperature : 34.0 degC

It also provides network information such as:

CAN Interface
Messages Received
Decode Errors
DBC Database
DBC Status
CAN Status

This makes it possible to verify that the CAN network and DBC decoding are working correctly.

26. DBC Modification Challenge

One of the assignment challenges was to modify a DBC signal definition.

Possible DBC modifications include:

Scaling
Offset
Unit
Signal length

The effect of a DBC modification can be observed in the decoded engineering value.

For example:

Raw CAN Data
     |
     v
Original DBC
     |
     v
Original Engineering Value

After modifying the DBC:

Same Raw CAN Data
     |
     v
Modified DBC
     |
     v
Different Engineering Value

This demonstrates that the DBC is essential for correct CAN signal interpretation.

27. Adding Ambient Temperature

The assignment requires an additional signal as a challenge.

The project adds:

Ambient Temperature

The signal was added to:

The DBC database.
The transmitter.
The decoding process.
The monitoring dashboard.
The project documentation.

The dashboard displays:

Ambient Temperature : 34.0 degC

This demonstrates the complete process of adding a new CAN signal.

28. AI DBC Review

The final DBC was reviewed using AI to identify:

Syntax problems
Incorrect signal definitions
Incorrect scaling
Incorrect offsets
Incorrect ranges
Incorrect units
Possible overlapping signals
Naming improvements
Documentation improvements

The AI review was treated as an engineering assistance step.

The final DBC was verified through actual CAN transmission and decoding rather than relying only on AI output.

29. Validation Workflow

The complete validation process was:

DBC Design
    |
    v
AI-Assisted Generation
    |
    v
Human Review
    |
    v
DBC Validation
    |
    v
CAN Transmitter
    |
    v
vcan0
    |
    v
candump
    |
    v
Raw CAN Verification
    |
    v
cantools
    |
    v
DBC Decoding
    |
    v
Dashboard
    |
    v
Engineering Value Verification
30. Demonstration Procedure

The project can be demonstrated in the following order.

Step 1 - Start vcan0
ip link show vcan0
Step 2 - Start CAN traffic
./can_transmitter
Step 3 - Monitor raw CAN frames

In another terminal:

candump vcan0
Step 4 - Start the dashboard
python3 src/dashboard.py
Step 5 - Observe decoded values

The dashboard displays:

Vehicle Speed
Engine RPM
Coolant Temperature
Fuel Level
Battery Voltage
Ambient Temperature
Step 6 - Compare raw and decoded data

Compare:

candump

with:

dashboard.py
Step 7 - Modify the DBC

Change one signal definition and observe the decoded result.

Step 8 - Demonstrate the added signal

Show Ambient Temperature in the DBC, transmitter, and dashboard.

Step 9 - Explain AI assistance

Show the AI-generated DBC prompt and the AI review process.

31. Raw Data vs Engineering Data

The project demonstrates an important difference between raw CAN data and engineering data.

Raw CAN:

vcan0  200  [2]  XX XX

Engineering data:

Vehicle Speed : XX.X km/h

The DBC performs the interpretation.

Therefore:

CAN Frame
   |
   v
CAN ID
   |
   v
Signal Extraction
   |
   v
Raw Value
   |
   v
Scaling + Offset
   |
   v
Engineering Value

This process is commonly used during automotive CAN development and testing.

32. Why DBC is Important

Without a DBC:

CAN ID + Raw Bytes

With a DBC:

CAN ID
   |
   +--- Message
         |
         +--- Vehicle Speed
         +--- Engine RPM
         +--- Coolant Temperature
         +--- Fuel Level
         +--- Battery Voltage
         +--- Ambient Temperature

The DBC makes CAN traffic understandable to engineers and CAN analysis tools.

33. Technologies Used
Technology	Purpose
C	CAN transmitter
Python	Monitoring dashboard
Linux	Development environment
SocketCAN	CAN communication
vcan0	Virtual CAN interface
can-utils	CAN traffic monitoring
cantools	DBC decoding
DBC	CAN database
Git	Version control
GitHub	Project repository
ChatGPT	AI-assisted DBC development
34. Software Requirements

Required software:

Linux / Ubuntu
GCC
Python 3
SocketCAN
can-utils
cantools
Git

Python dependency:

python3 -m pip install cantools

CAN utilities:

sudo apt install can-utils
35. Project Evidence and Screenshots

The following screenshots provide execution evidence for the SocketCAN communication, CAN traffic, DBC generation, DBC validation, signal decoding, visualization, DBC modification, Ambient Temperature addition, and AI-assisted development.

35.1 Virtual CAN Interface Setup

<img width="1102" height="229" alt="1_vcan0_setup" src="https://github.com/user-attachments/assets/eb8369fe-050d-47a5-b185-bf9668262323" />

35.2 Project Build
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/2_project_build.png" width="100%" alt="Project Build">
35.3 CAN Transmitter
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/3_can_transmitter.png" width="100%" alt="CAN Transmitter">
35.4 Raw CAN Traffic
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/08a_raw_vs_decoded.png" width="100%" alt="Raw CAN Traffic">
35.5 DBC File
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/5_dbc_file.png" width="100%" alt="DBC File">
35.6 DBC Validation
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/6_dbc_validation.png" width="100%" alt="DBC Validation">
35.7 DBC Decoded Dashboard
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/7_dashboard.png" width="100%" alt="DBC Decoded Dashboard">
35.8 Raw CAN vs Decoded Data
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/08_raw_vs_decoded.png" width="100%" alt="Raw CAN vs Decoded Data">
35.9 DBC Modification
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/09_dbc_modification.png" width="100%" alt="DBC Modification">
35.10 Ambient Temperature Signal
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/10a_ambient_temperature.png" width="100%" alt="Ambient Temperature Signal">
35.11 AI-Assisted DBC Generation
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/11_ai_dbc_generation.png" width="100%" alt="AI-Assisted DBC Generation">
35.12 AI DBC Review
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/12_ai_dbc_review.png" width="100%" alt="AI DBC Review">
35.13 Overall CAN Traffic
<img src="https://raw.githubusercontent.com/Sanket5358/Project3_SocketCAN_DBC/main/screenshots/10_overall_can_traffic.png" width="100%" alt="Overall CAN Traffic">
36. Assignment Deliverables
Deliverable 1 - DBC File

Completed CAN database:

dbc/vehicle_information.dbc

The database contains the CAN message and signal definitions used by the project.

Deliverable 2 - Source Code
CAN Transmitter
src/can_transmitter.c

Responsible for generating and transmitting CAN frames.

Monitoring Dashboard
src/dashboard.py

Responsible for receiving and decoding CAN messages and displaying engineering values.

Deliverable 3 - AI Usage Report

The AI-assisted development included:

AI tool selection
DBC generation prompts
DBC syntax assistance
Signal layout suggestions
DBC validation assistance
DBC review
Corrections after review
Final verification using SocketCAN

The AI output was reviewed and verified before implementation.

Deliverable 4 - Technical Report

The project documentation covers:

Signal design
DBC structure
AI-assisted DBC generation
DBC validation
SocketCAN integration
Raw CAN traffic
DBC decoding
Dashboard visualization
DBC modification
Ambient Temperature addition
Lessons learned
Deliverable 5 - Demonstration

The project demonstrates:

SocketCAN message transmission
Raw CAN traffic
DBC file
DBC validation
DBC decoding
Engineering signal visualization
DBC modification
Ambient Temperature signal addition
AI-assisted DBC generation
AI-assisted DBC review
37. Challenges Completed
Challenge 1 - Raw Data vs Decoded Data

Completed by comparing:

candump vcan0

with the decoded values displayed by the dashboard.

Challenge 2 - Modify the DBC

Completed by modifying a DBC signal definition and observing the change in the displayed engineering value.

Challenge 3 - Add a New Signal

Completed by adding:

Ambient Temperature

and updating:

DBC
Transmitter
Decoder
Dashboard
Documentation
Challenge 4 - AI Review

Completed using AI to review:

DBC syntax
Signal definitions
Scaling
Offsets
Ranges
Units
Naming
Documentation

The suggestions were evaluated against the actual project implementation.

38. Lessons Learned

This project provided practical understanding of the complete CAN data workflow.

Important lessons include:

Raw CAN data cannot be interpreted correctly without knowledge of the message and signal definitions.
A DBC file provides the metadata required for CAN decoding.
Scaling and offset are important for converting raw values into physical values.
SocketCAN provides a convenient Linux interface for CAN communication.
vcan0 allows CAN software to be tested without physical CAN hardware.
candump is useful for checking raw CAN traffic.
cantools can decode CAN messages using a DBC database.
A small DBC error can produce an incorrect engineering value even when CAN communication itself is working.
AI can assist with DBC generation and review, but generated content must be verified.
Adding a new signal requires coordinated changes to the DBC, transmitter, decoder, and visualization.
39. Complete CAN Workflow

The final workflow demonstrated by the project is:

Signal Definition
        |
        v
CAN Message Design
        |
        v
AI-Assisted DBC Generation
        |
        v
DBC Validation
        |
        v
C CAN Transmitter
        |
        v
Linux SocketCAN
        |
        v
vcan0
        |
        v
Raw CAN Frames
        |
        v
candump
        |
        v
DBC-Based Decoding
        |
        v
cantools
        |
        v
Engineering Values
        |
        v
Python Dashboard
        |
        v
Visualization and Analysis

This represents the complete transformation:

Raw Hexadecimal CAN Data
             |
             v
       DBC Interpretation
             |
             v
     Engineering Signals
             |
             v
      Human-Readable Data
40. Conclusion

This project demonstrates an end-to-end automotive CAN communication and DBC decoding workflow using Linux SocketCAN.

A C-based transmitter generates vehicle information and sends CAN frames through the virtual vcan0 interface.

The DBC file defines how the raw CAN data should be interpreted.

The candump utility is used to monitor raw CAN traffic, while cantools is used for DBC-based decoding.

A Python monitoring dashboard displays the decoded engineering values such as:

Vehicle Speed
Engine RPM
Coolant Temperature
Fuel Level
Battery Voltage
Ambient Temperature

The project also demonstrates DBC modification, signal addition, validation, AI-assisted DBC generation, and AI-assisted DBC review.

The complete workflow is therefore:

CAN Signal Definition
        ↓
DBC Creation
        ↓
AI-Assisted Review
        ↓
SocketCAN Transmission
        ↓
Raw CAN Traffic
        ↓
DBC Decoding
        ↓
Engineering Values
        ↓
Visualization

The project provides practical experience with technologies and concepts used in automotive communication, CAN network development, signal decoding, testing, and validation.

41. Repository Information

Repository:

Project3_SocketCAN_DBC

GitHub:

https://github.com/Sanket5358/Project3_SocketCAN_DBC

Project:

AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

Technology:

C
Python
Linux
SocketCAN
vcan0
CAN
DBC
cantools
can-utils
Git
GitHub
42. Author

Sanket Chavan

Project:

AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

Department:

Electronics and Telecommunication Engineering

43. Final Project Summary

This project demonstrates how automotive CAN communication can be transformed from raw hexadecimal frames into meaningful engineering information using a DBC database.

The implementation combines:

C
+
Linux SocketCAN
+
vcan0
+
DBC
+
cantools
+
Python
+
AI Assistance

The final system demonstrates:

CAN message transmission
Raw CAN monitoring
DBC generation
DBC validation
DBC decoding
Signal visualization
DBC modification
New signal addition
AI-assisted development
AI-assisted review

The project therefore covers the complete workflow from CAN signal definition to human-readable engineering data visualization.
vcan0  200   [2]  4E 00
