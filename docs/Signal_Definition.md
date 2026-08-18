# Signal Definition

## Project 3
## AI-Assisted DBC Generation and CAN Data Visualization Using SocketCAN

The Vehicle Information Network uses five CAN signals.

| CAN ID | Signal | Start Bit | Length | Data Type | Scaling | Offset | Minimum | Maximum | Unit |
|---|---|---:|---:|---|---:|---:|---:|---:|---|
| 0x100 | Vehicle Speed | 0 | 16 | Unsigned | 0.1 | 0 | 0 | 120 | km/h |
| 0x101 | Engine RPM | 0 | 16 | Unsigned | 1 | 0 | 800 | 5000 | rpm |
| 0x102 | Coolant Temperature | 0 | 16 | Unsigned | 0.1 | 0 | 20 | 120 | °C |
| 0x103 | Fuel Level | 0 | 8 | Unsigned | 1 | 0 | 0 | 100 | % |
| 0x104 | Battery Voltage | 0 | 16 | Unsigned | 0.01 | 0 | 11 | 15 | V |

---

## Encoding Formula

The physical engineering value is calculated as:

Physical Value = Raw Value × Scaling Factor + Offset

The raw CAN value is calculated as:

Raw Value = (Physical Value - Offset) / Scaling Factor

---

## Signal Details

### 1. Vehicle Speed

- CAN ID: 0x100
- Start Bit: 0
- Signal Length: 16 bits
- Data Type: Unsigned
- Scaling: 0.1
- Offset: 0
- Minimum: 0 km/h
- Maximum: 120 km/h
- Unit: km/h

Example:

65 km/h

Raw Value = 65 / 0.1

Raw Value = 650

---

### 2. Engine RPM

- CAN ID: 0x101
- Start Bit: 0
- Signal Length: 16 bits
- Data Type: Unsigned
- Scaling: 1
- Offset: 0
- Minimum: 800 rpm
- Maximum: 5000 rpm
- Unit: rpm

Example:

2450 rpm

Raw Value = 2450 / 1

Raw Value = 2450

---

### 3. Coolant Temperature

- CAN ID: 0x102
- Start Bit: 0
- Signal Length: 16 bits
- Data Type: Unsigned
- Scaling: 0.1
- Offset: 0
- Minimum: 20 °C
- Maximum: 120 °C
- Unit: °C

Example:

87 °C

Raw Value = 87 / 0.1

Raw Value = 870

---

### 4. Fuel Level

- CAN ID: 0x103
- Start Bit: 0
- Signal Length: 8 bits
- Data Type: Unsigned
- Scaling: 1
- Offset: 0
- Minimum: 0 %
- Maximum: 100 %
- Unit: %

Example:

72 %

Raw Value = 72 / 1

Raw Value = 72

---

### 5. Battery Voltage

- CAN ID: 0x104
- Start Bit: 0
- Signal Length: 16 bits
- Data Type: Unsigned
- Scaling: 0.01
- Offset: 0
- Minimum: 11 V
- Maximum: 15 V
- Unit: V

Example:

12.5 V

Raw Value = 12.5 / 0.01

Raw Value = 1250
