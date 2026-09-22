/*
project3_transportation.c
Due Date:   September 25, 2026
Name:       Maverick Wong
NetID:      U16095228
Description:
  Transportation calculator to find out how much to charge for different vehicle types, passenger count, and distance traveled.
    - refactor project1_transportation to use arrays to hold the data rather than hard coding the values in a switch statement.
  */
#include <stdio.h> // Include the standard input/output library

// Define the distance threshold for the base fee
#define BASE_FEE_DISTANCE 10 

int main()
{
    // Define vehicle data for maximum passengers, base fee, and additional rate
    int maximumPassengersByVehicle[4] = {3, 4, 8, 12};
    double baseFeeByVehicle[4] = {15.00, 25.00, 35.00, 60.00};
    double additionalRateByVehicle[4] = {2.00, 2.50, 3.00, 4.00};
    // Define variables for vehicle selection, passenger count, and maximum passengers allowed
    int inputVehicle, passengers, maximumPassengers;
    // Define variables for distance traveled, base fee, additional rate, and total charge
    double distance, baseFee, additionalRate, charge;

    printf("Please select from four vehicle types: 1, 2, 3, and 4\n");
    printf("Enter selection: ");
    // Read the user's vehicle selection
    scanf("%d", &inputVehicle); 

    // Validate the vehicle selection before using it as an array index
    if (inputVehicle < 1 || inputVehicle > 4)
    {
        // Handle invalid vehicle selection
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    // Get the selected vehicle's passenger limit and pricing from the arrays
    maximumPassengers = maximumPassengersByVehicle[inputVehicle - 1];
    baseFee = baseFeeByVehicle[inputVehicle - 1];
    additionalRate = additionalRateByVehicle[inputVehicle - 1];

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