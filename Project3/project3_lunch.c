/*
project3_lunch.c
Due Date: September 25, 2026   
Name:       Maverick Wong
NetID:      U16095228
Description:
    Determine how many students in lunch line. Record the lunch choice of each student. Use arrays to hold the data. Determine which lunch option(s) were selected by the greatest number of students. If multiple lunch options have the same highest number of selections, display all of those lunch options in ascending order. 
 */

#include <stdio.h> // Include the standard input/output library

void search(int lunches[], int n); // Function definition

int main()
{
    // Prompt the user to enter the number of lunch orders and validate the input
    int numberOfStudents; 
    printf("Enter number of lunch orders: ");
    scanf("%d", &numberOfStudents);
    // Validate that the number of lunch orders is greater than 0
    while (numberOfStudents <= 0)
    {
        // If the number of lunch orders is invalid, display an error message and prompt again
        printf("Invalid number of lunch orders. The number of orders must be greater than 0.\n");
        printf("Enter number of lunch orders: ");
        scanf("%d", &numberOfStudents); 
    }
    // Prompt the user to enter lunch selections for each student and validate the input
    int lunches[numberOfStudents];
    printf("Enter lunch selections: ");
    // Track the number of valid lunch orders entered by the user
    int ordersEntered = 0;
    int lunchSelection;
    // Loop to read lunch selections until the required number of valid orders is entered
    while (ordersEntered < numberOfStudents)
    {
        scanf("%d", &lunchSelection);
        // Validate that the lunch selection is between 1 and 5
        if (lunchSelection >= 1 && lunchSelection <= 5)
        {
            // If the lunch selection is valid, store it in the lunches array and increment the count of valid orders
            lunches[ordersEntered] = lunchSelection;
            ordersEntered++;
        }
        else
        {
            // If the lunch selection is invalid, display an error message
            printf("Invalid lunch selection - %d. Lunch selection must be between 1 and 5.\n", lunchSelection);
        }
    }
    // Call the search function to determine and display the most popular lunch option(s)
    search(lunches, numberOfStudents);
    return 0;
}

void search(int lunches[], int n)
{
    // Array to hold counts for lunch options 1-5
    int counts[5] = {0}; 
    // Loop through the lunches array to count the occurrences of each lunch option
    for (int i = 0; i < n; i++)
    {
        counts[lunches[i] - 1]++;
    }
    // Determine the maximum count of lunch selections
    int maxCount = 0;
    for (int i = 0; i < 5; i++)
    {
        if (counts[i] > maxCount)
        {
            maxCount = counts[i];
        }
    }
    // Display the most popular lunch option(s) based on the maximum count
    printf("Most popular lunch option(s): ");
    for (int i = 0; i < 5; i++)
    {
        if (counts[i] == maxCount)
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}