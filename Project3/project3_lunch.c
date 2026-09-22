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

int popularLunch(int lunches[], int n);

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
    printf("Enter lunch selections: ");
    for (int i = 0; i < numberOfStudents; i++)
    {
        scanf("%d", &lunches[i]);
    }
    popularLunch(lunches, numberOfStudents);
    return 0;
}

int popularLunch(int lunches[], int n)
{
    int counts[5] = {0}; // Array to hold counts for lunch options 1-5
    for (int i = 0; i < n; i++)
    {
        if (lunches[i] >= 1 && lunches[i] <= 5)
        {
            counts[lunches[i] - 1]++;
        }else{
            printf("Invalid lunch selection - %d. Lunch selections must be between 1 and 5.\n", lunches[i]);
        }
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
    return 0;
}