# AI-Assisted DBC Review

## Project 3

### AI Review of Vehicle Information CAN Database

The DBC file was reviewed using an AI-assisted analysis approach.
The review focused on signal definitions, CAN identifiers, scaling,
ranges, units, naming conventions, and signal organization.

---

## 1. Review Scope

The following signals were reviewed:

| CAN ID | Signal |
|---|---|
| 0x100 | VehicleSpeed |
| 0x101 | EngineRPM |
| 0x102 | CoolantTemperature |
| 0x103 | FuelLevel |
| 0x104 | BatteryVoltage |
| 0x105 | AmbientTemperature |

---

## 2. Review Results

### VehicleSpeed

Scaling, signal length, unit and physical range are consistent with
the transmitter implementation.

Status: PASS

### EngineRPM

Scaling, signal length, unit and physical range are consistent.

Status: PASS

### CoolantTemperature

Scaling, signal length, unit and physical range are consistent.

Status: PASS

### FuelLevel

The 8-bit unsigned signal with a scaling factor of 1 is appropriate
for the defined 0–100 % range.

Status: PASS

### BatteryVoltage

The 16-bit signal with a scaling factor of 0.01 provides the required
voltage resolution.

Status: PASS

### AmbientTemperature

The newly added AmbientTemperature signal was reviewed.

The signal currently uses an unsigned data type with a physical range
of -20 to 60 degC.

An unsigned signal with zero offset cannot directly represent negative
physical values. Therefore, this is identified as a DBC design
observation.

For the current demonstration, the transmitter generates positive
ambient temperatures between approximately 20 and 40 degC, so the
implementation operates correctly.

Status: REVIEW REQUIRED FOR NEGATIVE TEMPERATURES

---

## 3. Signal Layout Review

Each signal currently uses a separate CAN message.

This approach is simple and makes the system easy to understand,
debug and demonstrate.

In a production automotive network, multiple related signals could
potentially be packed into fewer CAN messages to improve bus
utilization.

For this academic project, the existing layout was retained.

---

## 4. Naming Review

Signal names were reviewed for clarity and consistency.

The following names are considered clear:

- VehicleSpeed
- EngineRPM
- CoolantTemperature
- FuelLevel
- BatteryVoltage
- AmbientTemperature

No major naming changes were required.

---

## 5. Unit Review

Units are explicitly defined in the DBC:

- km/h
- rpm
- degC
- %
- V

The units are consistent with the signal definitions.

---

## 6. Scaling Review

The scaling factors were checked against the transmitter:

| Signal | Scaling |
|---|---:|
| VehicleSpeed | 0.1 |
| EngineRPM | 1 |
| CoolantTemperature | 0.1 |
| FuelLevel | 1 |
| BatteryVoltage | 0.01 |
| AmbientTemperature | 0.1 |

The scaling factors match the encoding implemented in the CAN
transmitter.

---

## 7. Validation Performed

The DBC was tested using cantools and SocketCAN.

The system successfully decoded:

- Vehicle Speed
- Engine RPM
- Coolant Temperature
- Fuel Level
- Battery Voltage
- Ambient Temperature

During testing, the DBC monitor reported received CAN messages with
zero discarded frames and zero decoding errors.

The monitoring dashboard also successfully displayed the six signals.

---

## 8. AI Suggestions

The AI-assisted review identified:

1. The AmbientTemperature negative range should be reviewed because
   the signal is currently unsigned.
2. Related signals could be packed into fewer CAN messages in a
   production implementation.
3. Signal naming and units are already clear and consistent.

---

## 9. Decisions Taken

The current message layout was retained because it provides a simple
and transparent demonstration of CAN communication and DBC decoding.

The AmbientTemperature implementation was retained because the
current transmitter generates only positive ambient temperatures.
The negative range issue is documented as a possible future
improvement.

---

## 10. Conclusion

The DBC database is consistent with the current SocketCAN transmitter
and monitoring dashboard for the tested operating range.

The AI-assisted review was useful for identifying a subtle data-type
and physical-range inconsistency in the AmbientTemperature signal and
for suggesting possible improvements to message organization.

All AI-generated suggestions were reviewed before being accepted or
rejected.
