/*
project1_transportation.c
Due Date:    September 8, 2026
Name:    Maverick Wong
NetID:   U16095228
Description:
  Transportation charge calculator for different vehicle types based on passenger count and distance traveled.
 */
#include <stdio.h>

#define BASE_FEE_DISTANCE 10

int main()
{
    int inputVehicle,passengers, maximumPassengers;
    double distance, baseFee, additionalRate, charge;

    printf("+----+-------------+----------+----------+------------------+\n");
    printf("| No | Vehicle     | Capacity | Base fee | Additional/mile |\n");
    printf("+----+-------------+----------+----------+------------------+\n");
    printf("| 1  | Compact car |        3 | $15.00   | $2.00            |\n");
    printf("| 2  | SUV         |        4 | $25.00   | $2.50            |\n");
    printf("| 3  | Minivan     |        8 | $35.00   | $3.00            |\n");
    printf("| 4  | Limousine   |       12 | $60.00   | $4.00            |\n");
    printf("+----+-------------+----------+----------+------------------+\n");
    printf("Select vehicle (1-4): ");
    scanf("%d", &inputVehicle);

    if (inputVehicle < 1 || inputVehicle > 4)
    {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    switch (inputVehicle)
    {
    case 1:
        maximumPassengers = 3;
        baseFee = 15.00;
        additionalRate = 2.00;
        break;
    case 2:
        maximumPassengers = 4;
        baseFee = 25.00;
        additionalRate = 2.50;
        break;
    case 3:
        maximumPassengers = 8;
        baseFee = 35.00;
        additionalRate = 3.00;
        break;
    default:
        maximumPassengers = 12;
        baseFee = 60.00;
        additionalRate = 4.00;
        break;
    }

    printf("Enter passengers: ");
    scanf("%d", &passengers);

    if (passengers < 1)
    {
        printf("Invalid passenger count.\n");
        return 0;
    }

    if (passengers > maximumPassengers)
    {
        printf("Too many passengers for selected vehicle.\n");
        return 0;
    }

    printf("Enter distance: ");     
    scanf("%lf", &distance);

    if (distance < 0)
    {
        printf("Invalid distance.\n");
        return 0;
    }

    charge = baseFee;
    if (distance > BASE_FEE_DISTANCE)
    {
        charge += (distance - BASE_FEE_DISTANCE) * additionalRate;
    }

    printf("Charge: $%.2f\n", charge);
    return 0;
}