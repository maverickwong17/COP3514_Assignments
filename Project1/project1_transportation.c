/*
project1_transportation.c
Due Date:   September 8, 2026
Name:       Maverick Wong
NetID:      U16095228
Description:
  Transportation calculator to find out how much to charge for different vehicle types, passenger count, and distance traveled.
 */
#include <stdio.h> // Include the standard input/output library

// Define the distance threshold for the base fee
#define BASE_FEE_DISTANCE 10 

int main()
{
    // Define variables for vehicle selection, passenger count, and maximum passengers allowed
    int inputVehicle,passengers, maximumPassengers; 
    // Define variables for distance traveled, base fee, additional rate, and total charge
    double distance, baseFee, additionalRate, charge; 

    printf("Please select from four vehicle types: 1, 2, 3, and 4\n");
    printf("Enter selection: ");
    // Read the user's vehicle selection
    scanf("%d", &inputVehicle); 

    // Set the maximum passengers, base fee, and additional rate based on the selected vehicle type
    switch (inputVehicle)
    {
    case 1:
        // Compact car passenger count and pricing
        maximumPassengers = 3;
        baseFee = 15.00;
        additionalRate = 2.00;
        break;
    case 2:
        // SUV passenger count and pricing
        maximumPassengers = 4;
        baseFee = 25.00;
        additionalRate = 2.50;
        break;
    case 3:
        // Minivan passenger count and pricing
        maximumPassengers = 8;
        baseFee = 35.00;
        additionalRate = 3.00;
        break;
    case 4:
        // Limousine passenger count and pricing
        maximumPassengers = 12;
        baseFee = 60.00;
        additionalRate = 4.00;
        break;
    default:
        // Handle invalid vehicle selection
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    printf("Enter passengers: ");
    // Read the number of passengers
    scanf("%d", &passengers);
    
    // Validate the passenger count
    if (passengers < 1)
    {
        printf("Invalid passenger count.\n");
        return 0;
    }

    // Validate if the number of passengers exceeds the maximum allowed for the selected vehicle
    if (passengers > maximumPassengers)
    {
        printf("Too many passengers for selected vehicle.\n");
        return 0;
    }

    printf("Enter distance: ");
    // Read the distance traveled
    scanf("%lf", &distance); 

    // Validate the distance input
    if (distance < 0)
    {
        printf("Invalid distance.\n");
        return 0;
    }

    // Calculate the total charge based on the base fee and additional rate for distance traveled
    charge = baseFee;
    // If the distance exceeds the base fee distance, calculate the additional charge
    if (distance > BASE_FEE_DISTANCE)
    {
        charge += (distance - BASE_FEE_DISTANCE) * additionalRate;
    }
    // Print the total charge formatted to two decimal places
    printf("Charge: $%.2f\n", charge);
    return 0;
}