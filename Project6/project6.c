/*
project6.c
Due Date: October 24, 2026  
Name:       Maverick Wong
NetID:      U16095228
Description:
    Command Line Interface (CLI) program that reads a text file and splits it into multiple smaller text files.
*/

// Include the standard input/output library
#include <stdio.h> 
#include <stdlib.h>

// Define constants for maximum filename size and read chunk size
#define MAX_SIZE_FILENAME 64
#define READ_CHUNK_SIZE 128

int main(int argc, char *argv[]) {
    
    // Check the number of command-line arguments
    if (argc != 3) {
        printf("Usage: ./a.out <input filename> <output file size>\n");
        return 1;
    }
    
    // Declare file pointers for input and output files
    FILE *in = NULL;
    FILE *out = NULL;
    // Declare a buffer to hold lines read from the input file
    char buffer[READ_CHUNK_SIZE];
    // Declare a variable to hold the output file name
    char out_name[MAX_SIZE_FILENAME];
    // Declare variables to track the number of lines in the current chunk and the chunk number
    int lines_in_chunk = 0;
    int chunk_num = 0;
    // Convert the second command-line argument to an integer for output file size
    int output_file_size = atoi(argv[2]);

    // Error 1: wrong number of arguments
    if (argc != 3) {
        printf("Usage: ./a.out <input filename> <output file size>\n");
        return 1;
    }

    // Error 2: second argument must be a positive integer
    if (output_file_size <= 0) {
        printf("Error: 2nd argument must be a positive integer.\n");
        return 2;
    }

    // Error 3: cannot open input file
    in = fopen(argv[1], "r");
    if (in == NULL) {
        printf("Error opening input file '%s'\n", argv[1]);
        return 3;
    }

    // Process the buffer and write to output files
    while(fgets(buffer, READ_CHUNK_SIZE, in) != NULL) {
        // Create a new output file if necessary
        if(out == NULL) {
            // Increment the chunk number and create a new output file name
            chunk_num++;
            // Create the output file name using snprintf
            snprintf(out_name, MAX_SIZE_FILENAME, "chunk_%d.txt", chunk_num);
            // Open the output file for writing
            out = fopen(out_name, "w");
            if (out== NULL) {
                // Error 4: cannot create output file
                printf("Error creating output file: %s\n", out_name);
                // Close the input file before returning
                fclose(in);
                return 4;
            }
            // Reset the line count for the new chunk
            lines_in_chunk = 0;
        }
        // Write the buffer to the output file and increment the line count
        fputs(buffer, out);
        // Increment the line count for the current chunk
        lines_in_chunk++;
        // Close the output file if the line count reaches the specified output file size
        if (lines_in_chunk >= output_file_size) {
            // Close the output file and reset the pointer to NULL
            fclose(out);
            out = NULL;
        }   
    }
    // Close the output file if it is still open after processing all lines
    if(out != NULL) {
        fclose(out);
    }
    // Close the input file before exiting the program
    fclose(in);
    return 0;
}