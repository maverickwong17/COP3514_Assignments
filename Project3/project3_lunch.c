/*
project3_lunch.c
Due Date: September 25, 2026   
Name:       Maverick Wong
NetID:      U16095228
Description:
    The school cafeteria records the lunch choice of each student. Each lunch option is represented by a number from 1 to 5.

Write a program that determines which lunch option(s) were selected by the greatest number of students. The program first reads the number of students who ordered lunch. It then reads each student's lunch choice. The program must continue reading lunch choices until the total number of lunch orders entered matches the number of students. After all lunch choices have been entered, the program displays the most popular lunch option(s). If multiple lunch options have the same highest number of selections, display all of those lunch options in ascending order.

The program first reads the number of students who ordered lunch, and then reads each student's lunch choice.
Enter number of lunch orders: 10
Enter lunch selections: 2 1 3 2 4 2 1 5 2 3
Most popular lunch option(s): 2
 */

#include <stdio.h> // Include the standard input/output library

void popularLunch(int lunches[], int n);

int main()
{
    int numberOfStudents; 
    printf("Enter number of lunch orders: ");
    scanf("%d", &numberOfStudents);
    while (numberOfStudents <= 0)
    {
        printf("Invalid number of lunch orders. The numberof orders must be greater than 0.\n");
        printf("Enter number of lunch orders: ");
        scanf("%d", &numberOfStudents);
    }
    int lunches[numberOfStudents];
    int ordersEntered = 0;
    int lunchSelection;
    printf("Enter lunch selections: ");
    while (ordersEntered < numberOfStudents)
    {
        scanf("%d", &lunchSelection);
        if (lunchSelection >= 1 && lunchSelection <= 5)
        {
            lunches[ordersEntered] = lunchSelection;
            ordersEntered++;
        }
        else
        {
            printf("Invalid lunch selection - %d. Lunch selection must be between 1 and 5.\n", lunchSelection);
        }
    }
    popularLunch(lunches, numberOfStudents);
    return 0;
}

void popularLunch(int lunches[], int n)
{
    int counts[5] = {0}; // Array to hold counts for lunch options 1-5
    for (int i = 0; i < n; i++)
    {
        counts[lunches[i] - 1]++;
    }

    int maxCount = 0;
    for (int i = 0; i < 5; i++)
    {
        if (counts[i] > maxCount)
        {
            maxCount = counts[i];
        }
    }

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