/*
project5_text.c
Due Date:   October 17, 2024
Name:       Maverick Wong
NetID:      U16095228
Description:
    Command Line Interface (CLI) program that encrypts or decrypts an input string by shifting every character by a specified integer value. 
    Processes strings using character arrays and pointers. No functions from <string.h>.
*/

// Include the standard input/output library
#include <stdio.h> 
// Include the standard library for memory allocation and conversion functions
#include <stdlib.h> 

// Define a constant for the maximum string length
#define MAX_STR_LEN 50

// Function prototypes for string manipulation and encryption/decryption
int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
int encrypt_string(char *str, int shift);
int decrypt_string(char *str, int shift);

int main(int argc, char *argv[]) {
    // Check if the number of command line arguments is correct (should be 4)
    if (argc != 4) {
        printf("Invalid option\n");
        return EXIT_FAILURE;
    }

    // Assign command line arguments to variables for easier access
    char *option = argv[1];
    int shift = atoi(argv[2]);
    char *input = argv[3];

    // Check if the input string exceeds the maximum allowed length
    my_strlen(input);

    // Determine whether to encrypt or decrypt the input string based on the provided option
    if (my_strcmp(option, "-e") == 0) {
        // Encrypt the input string by shifting characters forward
        encrypt_string(input, shift);
    } else if(my_strcmp(option, "-d") == 0) {
        // Decrypt the input string by shifting characters backward
        decrypt_string(input, shift);
    }else{
        // If the option is neither "-e" nor "-d", print an error message and exit the program
        printf("Invalid option\n");
        return EXIT_FAILURE;
    }

    // Print the resulting string after encryption or decryption
    printf("%s\n", input);
    return EXIT_SUCCESS;
}

int my_strlen(char *str) {
    // Check if the input string is NULL
    if (str == NULL) {
        return 0;
    }
    // Calculate the length of the string by iterating through it until the null terminator is reached
    int length = 0;
    while (*str != '\0' && *str != '\n') {
        length++;
        if (length > MAX_STR_LEN) {
            // If the string exceeds the maximum allowed length, print an error message and exit the program
            printf("String too long\n");
            exit(EXIT_FAILURE);
        }
        str++;
    }
    return length;
}

int my_strcmp(char *str1, char *str2) {
    //NULL handling:
    if(str1 == NULL || str2 == NULL) {
        // If either string is NULL, return 0 if both are NULL, -1 if str1 is NULL, and 1 if str2 is NULL
        return (str1 == NULL) ? (str2 == NULL) ? 0 : -1 : 1;
    }
    while (*str1 != '\0' && *str2 != '\0') {
        // Compare the characters of both strings
        if(*str1 > *str2) {
            // String 1 is greater than string 2
            return 1; 
        }
        if(*str1 < *str2) {
            // String 1 is less than string 2
            return -1; 
        }
        str1++;
        str2++;
    }

    // If both strings are equal up to the null terminator, return 0
    return 0;
}

int encrypt_string(char *str, int shift) {
    // Check if the input string is NULL
    if (str == NULL) {
        return 0;
    }
    // Change character in the string by shifting them forward by the specified integer value
    while (*str != '\0' && *str != '\n') {
        // Shift the character and update the string
        *str = (char)(*str + shift);
        str++;
    }
    return 1;
}

int decrypt_string(char *str, int shift) {
    // Check if the input string is NULL
    if (str == NULL) {
        return 0;
    }
    // Change character in the string by shifting them backward by the specified integer value
    while (*str != '\0' && *str != '\n') {
        // Shift the character and update the string
        *str = (char)(*str - shift);
        str++;
    }
    return 1;
}