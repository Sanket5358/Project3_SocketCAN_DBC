# AI Usage Report

## Project

AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

## 1. AI Tool Used

The AI tool used for this project was **ChatGPT**.

ChatGPT was used as an engineering assistance tool during the design,
generation, review, documentation, and validation of the CAN DBC database.

The final DBC definitions were verified against the project requirements
and tested with the SocketCAN implementation before being used for decoding.

---

## 2. Purpose of Using AI

AI assistance was used for:

- Understanding DBC file structure and syntax
- Designing CAN messages and signals
- Selecting signal scaling and offsets
- Generating an initial DBC structure
- Reviewing signal definitions
- Checking CAN IDs and signal ranges
- Improving project documentation

AI-generated suggestions were manually verified before implementation.

---
## 3. AI-Assisted DBC Generation

The Vehicle Information Network contains the following signals:

| Signal | Unit | Range |
|---|---|---|
| Vehicle Speed | km/h | 0–120 |
| Engine RPM | rpm | 800–5000 |
| Coolant Temperature | °C | 20–120 |
| Fuel Level | % | 0–100 |
| Battery Voltage | V | 11–15 |

An additional signal, Ambient Temperature, was later added as part of
the DBC modification challenge.

---

## 4. AI Prompt for DBC Generation

A prompt used with ChatGPT was:

> Generate a DBC file for a Vehicle Information Network using SocketCAN
> with Vehicle Speed, Engine RPM, Coolant Temperature, Fuel Level and
> Battery Voltage. Define CAN IDs, start bits, signal lengths, scaling,
> offsets, ranges and units.

The generated structure was reviewed against the assignment requirements.

---

## 5. Final DBC Message Design

The final project database contains these messages:

| CAN ID | Message | Signal |
|---:|---|---|
| 0x100 | VehicleSpeed | VehicleSpeed |
| 0x101 | EngineRPM | EngineRPM |
| 0x102 | CoolantTemperature | CoolantTemperature |
| 0x103 | FuelLevel | FuelLevel |
| 0x104 | BatteryVoltage | BatteryVoltage |
| 0x105 | AmbientTemperature | AmbientTemperature |

The final database is stored in:

`dbc/vehicle_information.dbc`

---

## 6. Human Verification

The AI-generated DBC was manually verified before use.

The following items were checked:

- CAN identifiers
- Message DLC
- Signal start bits
- Signal lengths
- Byte order
- Signed/unsigned representation
- Scaling factors
- Offsets
- Minimum values
- Maximum values
- Units
- Signal names
- Compatibility with the transmitter
- Compatibility with DBC decoding

The final database was tested using SocketCAN and the DBC decoding
dashboard.

---
## 7. AI DBC Review

After generating the DBC, ChatGPT was used to review it.

The review prompt was:

> Review this DBC file for syntax errors, incorrect signal definitions,
> scaling, offsets, ranges, units and possible improvements.

The review focused on:

- DBC syntax
- Signal definitions
- Start bits
- Signal lengths
- Byte order
- Data type
- Scaling
- Offset
- Minimum and maximum values
- Units
- Naming
- Possible improvements

---

## 8. DBC Verification

The final DBC was checked against the required engineering ranges:

| Signal | Minimum | Maximum | Unit |
|---|---:|---:|---|
| Vehicle Speed | 0 | 120 | km/h |
| Engine RPM | 800 | 5000 | rpm |
| Coolant Temperature | 20 | 120 | degC |
| Fuel Level | 0 | 100 | % |
| Battery Voltage | 11 | 15 | V |
| Ambient Temperature | -20 | 60 | degC |

The signal definitions were then tested with the SocketCAN transmitter
and DBC decoding dashboard.

---

## 9. Scaling Verification

### Vehicle Speed

Scaling = 0.1

Raw value = 650

Engineering value:

`650 × 0.1 = 65 km/h`

### Engine RPM

Scaling = 1

Raw value = 2450

Engineering value:

`2450 × 1 = 2450 rpm`

### Coolant Temperature

Scaling = 0.1

Raw value = 880

Engineering value:

`880 × 0.1 = 88 degC`

### Fuel Level

Scaling = 1

Raw value = 72

Engineering value:

`72 × 1 = 72 %`

### Battery Voltage

Scaling = 0.01

Raw value = 1250

Engineering value:

`1250 × 0.01 = 12.5 V`

### Ambient Temperature

Scaling = 0.1

Raw value = 250

Engineering value:

`250 × 0.1 = 25 degC`

---
## 10. AI-Assisted DBC Modification

The project added the following signal during the DBC modification challenge:

**Ambient Temperature**

Final definition:

- CAN ID: `0x105`
- Start Bit: `0`
- Signal Length: `16 bits`
- Scaling: `0.1`
- Offset: `0`
- Range: `-20 to 60 degC`
- Unit: `degC`

The updated DBC was tested with the CAN transmitter and dashboard.

---
## 11. AI Review of the Modified DBC

The modified DBC was reviewed again.

The review checked:

- Correct new CAN ID
- Correct signal length
- Correct scaling
- Correct offset
- Correct temperature range
- Correct unit
- No CAN ID conflict
- Compatibility with the transmitter
- Compatibility with the dashboard

---
## 12. Lessons Learned

AI provided useful assistance for:

1. Understanding DBC syntax.
2. Creating an initial CAN database structure.
3. Reviewing signal definitions.
4. Checking scaling and offset calculations.
5. Improving technical documentation.
6. Identifying possible inconsistencies.

However, AI-generated CAN definitions must not be accepted without verification.

The final DBC must be checked against the actual CAN requirements, transmitter implementation, signal ranges, message layout and decoder.

---
## 13. AI-Assisted Development Workflow

The project followed this workflow:

CAN Requirements
       ↓
AI-Assisted DBC Generation
       ↓
Human Review
       ↓
DBC Verification
       ↓
SocketCAN Testing
       ↓
DBC Decoding
       ↓
Dashboard Visualization
       ↓
Final Validation

---

## 14. Final Observation

AI was used as an engineering assistance tool rather than as a replacement for engineering verification.

The final DBC database was manually reviewed and integrated with the SocketCAN transmitter and DBC decoding dashboard.

The project demonstrated that AI can accelerate DBC development, documentation and review, while the final CAN database still requires testing against the actual communication implementation.

## Conclusion

AI assistance reduced the effort required for initial DBC development and documentation. The project demonstrated an AI-assisted workflow from CAN signal definition through DBC creation, SocketCAN communication, DBC decoding and visualization.
