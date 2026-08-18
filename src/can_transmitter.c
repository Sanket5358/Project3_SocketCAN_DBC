#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#define CAN_INTERFACE "vcan0"

/* CAN IDs */
#define VEHICLE_SPEED_ID       0x100
#define ENGINE_RPM_ID          0x101
#define COOLANT_TEMP_ID        0x102
#define FUEL_LEVEL_ID          0x103
#define BATTERY_VOLTAGE_ID     0x104
#define AMBIENT_TEMP_ID        0x105


/*
 * Send a CAN frame
 */
int send_can_frame(int sock,
                   int can_id,
                   unsigned char *data,
                   unsigned char dlc)
{
    struct can_frame frame;

    memset(&frame, 0, sizeof(frame));

    frame.can_id = can_id;
    frame.can_dlc = dlc;

    for (int i = 0; i < dlc; i++)
    {
        frame.data[i] = data[i];
    }

    int bytes = write(sock,
                      &frame,
                      sizeof(struct can_frame));

    if (bytes != sizeof(struct can_frame))
    {
        perror("CAN write failed");
        return -1;
    }

    return 0;
}


/*
 * Encode 16-bit unsigned value
 * in little-endian format.
 */
void encode_uint16(unsigned short value,
                   unsigned char *data)
{
    data[0] = value & 0xFF;
    data[1] = (value >> 8) & 0xFF;
}


int main()
{
    int sock;

    struct sockaddr_can addr;
    struct ifreq ifr;

    unsigned char data[8];

    /*
     * Simulated vehicle values
     */
    float vehicle_speed = 30.0;
    int engine_rpm = 1500;
    float coolant_temperature = 70.0;
    int fuel_level = 80;
    float battery_voltage = 12.5;

    /*
     * New signal
     */
    float ambient_temperature = 25.0;


    /*
     * Create SocketCAN socket
     */
    sock = socket(PF_CAN,
                  SOCK_RAW,
                  CAN_RAW);

    if (sock < 0)
    {
        perror("Socket creation failed");
        return 1;
    }


    /*
     * Select CAN interface
     */
    strcpy(ifr.ifr_name,
           CAN_INTERFACE);

    if (ioctl(sock,
              SIOCGIFINDEX,
              &ifr) < 0)
    {
        perror("SIOCGIFINDEX failed");

        close(sock);

        return 1;
    }


    /*
     * Configure CAN address
     */
    memset(&addr, 0, sizeof(addr));

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;


    /*
     * Bind socket
     */
    if (bind(sock,
             (struct sockaddr *)&addr,
             sizeof(addr)) < 0)
    {
        perror("CAN bind failed");

        close(sock);

        return 1;
    }


    printf("========================================\n");
    printf("   VEHICLE INFORMATION CAN TRANSMITTER\n");
    printf("========================================\n");
    printf("CAN Interface : %s\n",
           CAN_INTERFACE);
    printf("Status        : ONLINE\n");
    printf("========================================\n");


    while (1)
    {
        unsigned short raw_value;


        /*
         * ------------------------------------
         * 0x100 Vehicle Speed
         * Scaling = 0.1
         * ------------------------------------
         */

        raw_value =
            (unsigned short)(vehicle_speed / 0.1);

        encode_uint16(raw_value, data);

        send_can_frame(sock,
                       VEHICLE_SPEED_ID,
                       data,
                       2);


        /*
         * ------------------------------------
         * 0x101 Engine RPM
         * Scaling = 1
         * ------------------------------------
         */

        raw_value =
            (unsigned short)engine_rpm;

        encode_uint16(raw_value, data);

        send_can_frame(sock,
                       ENGINE_RPM_ID,
                       data,
                       2);


        /*
         * ------------------------------------
         * 0x102 Coolant Temperature
         * Scaling = 0.1
         * ------------------------------------
         */

        raw_value =
            (unsigned short)(coolant_temperature / 0.1);

        encode_uint16(raw_value, data);

        send_can_frame(sock,
                       COOLANT_TEMP_ID,
                       data,
                       2);


        /*
         * ------------------------------------
         * 0x103 Fuel Level
         * Scaling = 1
         * ------------------------------------
         */

        data[0] =
            (unsigned char)fuel_level;

        send_can_frame(sock,
                       FUEL_LEVEL_ID,
                       data,
                       1);


        /*
         * ------------------------------------
         * 0x104 Battery Voltage
         * Scaling = 0.01
         * ------------------------------------
         */

        raw_value =
            (unsigned short)(battery_voltage / 0.01);

        encode_uint16(raw_value, data);

        send_can_frame(sock,
                       BATTERY_VOLTAGE_ID,
                       data,
                       2);


        /*
         * ------------------------------------
         * 0x105 Ambient Temperature
         *
         * Scaling = 0.1
         *
         * Example:
         *
         * 25.0 C
         *
         * Raw = 25.0 / 0.1
         *     = 250
         * ------------------------------------
         */

        raw_value =
            (unsigned short)(ambient_temperature / 0.1);

        encode_uint16(raw_value, data);

        send_can_frame(sock,
                       AMBIENT_TEMP_ID,
                       data,
                       2);


        /*
         * Display values
         */
        printf("\033[H\033[J");

        printf("========================================\n");
        printf("   VEHICLE INFORMATION CAN TRANSMITTER\n");
        printf("========================================\n");

        printf("Vehicle Speed       : %.1f km/h\n",
               vehicle_speed);

        printf("Engine RPM          : %d rpm\n",
               engine_rpm);

        printf("Coolant Temperature : %.1f C\n",
               coolant_temperature);

        printf("Fuel Level          : %d %%\n",
               fuel_level);

        printf("Battery Voltage     : %.2f V\n",
               battery_voltage);

        printf("Ambient Temperature : %.1f C\n",
               ambient_temperature);

        printf("----------------------------------------\n");

        printf("CAN IDs             : ");
        printf("0x100 0x101 0x102 0x103 0x104 0x105\n");

        printf("Status              : TRANSMITTING\n");

        printf("========================================\n");


        /*
         * Change values realistically.
         */

        vehicle_speed += 2.0;

        if (vehicle_speed > 120.0)
            vehicle_speed = 0.0;


        engine_rpm += 150;

        if (engine_rpm > 5000)
            engine_rpm = 800;


        coolant_temperature += 0.5;

        if (coolant_temperature > 120.0)
            coolant_temperature = 70.0;


        fuel_level -= 1;

        if (fuel_level < 0)
            fuel_level = 100;


        battery_voltage += 0.05;

        if (battery_voltage > 15.0)
            battery_voltage = 11.0;


        ambient_temperature += 0.5;

        if (ambient_temperature > 40.0)
            ambient_temperature = 20.0;


        /*
         * Transmit once every second.
         */
        sleep(1);
    }


    close(sock);

    return 0;
}
