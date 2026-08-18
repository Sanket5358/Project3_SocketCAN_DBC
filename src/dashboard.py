import os
import can
import cantools


# ============================================================
# Project 3
# AI-Assisted DBC Generation and CAN Data Visualization
# Using SocketCAN
# ============================================================

CAN_INTERFACE = "vcan0"
DBC_FILE = "dbc/vehicle_information.dbc"


# ============================================================
# Load DBC
# ============================================================

try:
    db = cantools.database.load_file(DBC_FILE)

except Exception as e:
    print("ERROR: Could not load DBC file.")
    print(e)
    exit(1)


# ============================================================
# Connect to SocketCAN
# ============================================================

try:
    bus = can.Bus(
        interface="socketcan",
        channel=CAN_INTERFACE
    )

except Exception as e:
    print("ERROR: Could not connect to vcan0.")
    print(e)
    exit(1)


# ============================================================
# Signal Variables
# ============================================================

vehicle_speed = 0.0
engine_rpm = 0
coolant_temperature = 0.0
fuel_level = 0
battery_voltage = 0.0
ambient_temperature = 0.0

message_count = 0
error_count = 0


# ============================================================
# Dashboard Display
# ============================================================

def display_dashboard():

    os.system("clear")

    print("================================================")
    print("       VEHICLE INFORMATION MONITORING")
    print("================================================")

    print()

    print(f"Vehicle Speed       : {vehicle_speed:6.1f} km/h")
    print(f"Engine RPM          : {engine_rpm:6d} rpm")
    print(f"Coolant Temperature : {coolant_temperature:6.1f} degC")
    print(f"Fuel Level          : {fuel_level:6d} %")
    print(f"Battery Voltage     : {battery_voltage:6.2f} V")
    print(f"Ambient Temperature : {ambient_temperature:6.1f} degC")

    print()

    print("------------------------------------------------")

    print(f"CAN Interface       : {CAN_INTERFACE}")
    print(f"Messages Received   : {message_count}")
    print(f"Decode Errors       : {error_count}")

    print("------------------------------------------------")

    print("DBC Database        : vehicle_information.dbc")
    print("DBC Status          : ACTIVE")
    print("CAN Status          : ONLINE")

    print("================================================")
    print("Press Ctrl+C to stop")
    print("================================================")


# ============================================================
# Main Monitoring Loop
# ============================================================

try:

    display_dashboard()

    while True:

        # ----------------------------------------------------
        # Receive CAN frame
        # ----------------------------------------------------

        message = bus.recv(timeout=1.0)

        if message is None:
            display_dashboard()
            continue


        # ----------------------------------------------------
        # Decode CAN frame using DBC
        # ----------------------------------------------------

        try:

            decoded = db.decode_message(
                message.arbitration_id,
                message.data
            )

            message_count += 1


            # ------------------------------------------------
            # Vehicle Speed
            # ------------------------------------------------

            if "VehicleSpeed" in decoded:
                vehicle_speed = decoded["VehicleSpeed"]


            # ------------------------------------------------
            # Engine RPM
            # ------------------------------------------------

            if "EngineRPM" in decoded:
                engine_rpm = decoded["EngineRPM"]


            # ------------------------------------------------
            # Coolant Temperature
            # ------------------------------------------------

            if "CoolantTemperature" in decoded:
                coolant_temperature = decoded["CoolantTemperature"]


            # ------------------------------------------------
            # Fuel Level
            # ------------------------------------------------

            if "FuelLevel" in decoded:
                fuel_level = decoded["FuelLevel"]


            # ------------------------------------------------
            # Battery Voltage
            # ------------------------------------------------

            if "BatteryVoltage" in decoded:
                battery_voltage = decoded["BatteryVoltage"]


            # ------------------------------------------------
            # Ambient Temperature
            # ------------------------------------------------

            if "AmbientTemperature" in decoded:
                ambient_temperature = decoded["AmbientTemperature"]


        except Exception:
            error_count += 1


        # ----------------------------------------------------
        # Update dashboard
        # ----------------------------------------------------

        display_dashboard()


# ============================================================
# Stop dashboard with Ctrl+C
# ============================================================

except KeyboardInterrupt:

    print()
    print("Dashboard stopped by user.")


finally:

    bus.shutdown()
