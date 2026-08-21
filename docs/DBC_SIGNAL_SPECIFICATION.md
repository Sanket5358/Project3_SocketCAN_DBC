# DBC Signal Specification

## Vehicle Information Network

This document defines the CAN message and signal encoding used by the Vehicle Information Network implemented using SocketCAN.

The DBC database contains six vehicle signals:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage
- Ambient Temperature

## CAN Message and Signal Definition

| CAN ID | Message | DLC | Signal | Start Bit | Length | Data Type | Scaling | Offset | Minimum | Maximum | Unit |
|---:|---|---:|---|---:|---:|---|---:|---:|---:|---:|---|
| 0x100 | VehicleSpeed | 2 | VehicleSpeed | 0 | 16 | Unsigned | 0.1 | 0 | 0 | 120 | km/h |
| 0x101 | EngineRPM | 2 | EngineRPM | 0 | 16 | Unsigned | 1 | 0 | 800 | 5000 | rpm |
| 0x102 | CoolantTemperature | 2 | CoolantTemperature | 0 | 16 | Unsigned | 0.1 | 0 | 20 | 120 | degC |
| 0x103 | FuelLevel | 1 | FuelLevel | 0 | 8 | Unsigned | 1 | 0 | 0 | 100 | % |
| 0x104 | BatteryVoltage | 2 | BatteryVoltage | 0 | 16 | Unsigned | 0.01 | 0 | 11 | 15 | V |
| 0x105 | AmbientTemperature | 2 | AmbientTemperature | 0 | 16 | Unsigned | 0.1 | 0 | -20 | 60 | degC |

## Common Encoding Properties

All signals use:

- Byte order: Intel / Little Endian
- Data type: Unsigned
- Transmitter: Vehicle_ECU
- Offset: 0

## Scaling Formula

Engineering Value = Raw Value × Scaling + Offset

### Vehicle Speed

CAN ID: `0x100`

Raw value × 0.1 = Vehicle Speed in km/h

Example:

Raw value = 650

Speed = 650 × 0.1 = 65 km/h

### Engine RPM

CAN ID: `0x101`

Raw value × 1 = Engine RPM

Example:

Raw value = 2450

Engine RPM = 2450 rpm

### Coolant Temperature

CAN ID: `0x102`

Raw value × 0.1 = Coolant Temperature in degC

Example:

Raw value = 880

Temperature = 880 × 0.1 = 88 degC

### Fuel Level

CAN ID: `0x103`

Raw value × 1 = Fuel Level in %

Example:

Raw value = 72

Fuel Level = 72 %

### Battery Voltage

CAN ID: `0x104`

Raw value × 0.01 = Battery Voltage in V

Example:

Raw value = 1250

Battery Voltage = 1250 × 0.01 = 12.5 V

### Ambient Temperature

CAN ID: `0x105`

Raw value × 0.1 = Ambient Temperature in degC

Example:

Raw value = 250

Ambient Temperature = 250 × 0.1 = 25 degC

## DBC Message Layout

### Vehicle Speed — 0x100

- Start Bit: 0
- Length: 16 bits
- Scaling: 0.1
- Offset: 0
- Range: 0 to 120
- Unit: km/h

### Engine RPM — 0x101

- Start Bit: 0
- Length: 16 bits
- Scaling: 1
- Offset: 0
- Range: 800 to 5000
- Unit: rpm

### Coolant Temperature — 0x102

- Start Bit: 0
- Length: 16 bits
- Scaling: 0.1
- Offset: 0
- Range: 20 to 120
- Unit: degC

### Fuel Level — 0x103

- Start Bit: 0
- Length: 8 bits
- Scaling: 1
- Offset: 0
- Range: 0 to 100
- Unit: %

### Battery Voltage — 0x104

- Start Bit: 0
- Length: 16 bits
- Scaling: 0.01
- Offset: 0
- Range: 11 to 15
- Unit: V

### Ambient Temperature — 0x105

- Start Bit: 0
- Length: 16 bits
- Scaling: 0.1
- Offset: 0
- Range: -20 to 60
- Unit: degC

## Validation

The signal definitions are defined in:

`dbc/vehicle_information.dbc`

The definitions are used by the SocketCAN transmitter and DBC decoding dashboard to convert raw CAN payload values into engineering values.

The database includes six CAN messages with identifiers from `0x100` through `0x105`.
