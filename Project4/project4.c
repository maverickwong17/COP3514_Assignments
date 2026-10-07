/*
project4.c
Due Date: October 9, 2024
Name:       Maverick Wong
NetID:      U16095228
Description:
    Reads an integer array of n length with user values. Returns a second array of paired elements by calculating the sum of elements from the two ends of the input array moving towards the center.
*/

// Include the standard input/output library
#include <stdio.h> 

// Function prototype for pair_sums.
void pair_sums(int *input, int n, int *output);

int main() {
    // Prompt the user for the length of the array
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    // Declare the output array for paired sums
    int pairedArray[(length + 1) / 2];
    // Prompt the user for the elements of the array
    int array[length];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    // Calculate the paired sums and store them in the output array
    pair_sums(array, length, pairedArray);
    
    // Print the output array containing the paired sums
    printf("Output:");
    for (int i = 0; i < ((length + 1) / 2); i++) {
        printf(" %d", pairedArray[i]);
    }
    printf("\n");
    return 0;
}

/*
    Function to calculate paired sums of an input array.
    Parameters:
        input  - pointer to the input array
        n      - length of the input array
        output - pointer to the output array where paired sums will be stored
*/
void pair_sums(int *input, int n, int *output) {
    // Initialize pointers for the front, back, and result positions in the arrays
    int *front = input;
    int *back = input + n - 1;
    int *result = output;
    // Loop through the array, summing pairs from the front and back until the pointers meet or cross
    while (front < back){
        // Calculate the sum of the current front and back elements and store it in the result array
        *result = *front + *back;
        // Move the pointers towards the center of the array and advance the result pointer
        front++;
        back--;
        result++;
    }
    // If the array length is odd, add the middle element to the result array
    if (front == back) {
        *result = *front;
    }
}