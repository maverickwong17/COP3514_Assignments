/*
project7_animation.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description:
    Reads animation movie data from a CSV file, searches for all animations released in or after a user-entered year, and writes all matching records to an output CSV file. 
*/

// Include the standard library
#include <stdio.h> 
#include <stdlib.h>

// Define constants for maximum records, title length, description length, and file names
#define MAX_RECORDS 500
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500
#define input_filename "animation.csv"
#define output_filename "result.csv"

// Define a structure to hold animation movie data
typedef struct {
    char title[MAX_TITLE_LENGTH + 1];
    int year;
    char description[MAX_DESCRIPTION_LENGTH + 1];
} Animation;

/**
 * Searches for animations released in or after a specified year.
 * @param list Array of Animation structures to search.
 * @param length Number of elements in the list.
 * @param year The minimum release year to include.
 * @param result Array to store matching Animation structures.
 * @return The number of matching animations found.
 */
int search(Animation *list, int length, int year, Animation *result) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (list[i].year >= year) {
            result[count] = list[i];
            count++;
        }
    }
    return count;
}

int main() {
    // Declare static arrays to hold animations and search results
    static Animation animations[MAX_RECORDS];
    static Animation results[MAX_RECORDS];    

    // Variable to keep track of the number of animations read from the input file
    int animation_count = 0;    
    
    // Open the input CSV file for reading
    FILE *input = fopen(input_filename, "r");
    if (input == NULL) {
        printf("Error opening input file '%s'\n", input_filename);
        return 1;
    }

    // Skip the header line of the CSV file
    fscanf(input, "%*[^\n]\n");

    // Read animation records from the input file until the maximum number of records is reached or the end of the file is encountered
    while (animation_count < MAX_RECORDS && fscanf(input, "%100[^,],%d,%500[^\n]\n", animations[animation_count].title, &animations[animation_count].year, animations[animation_count].description) == 3) {
        // Increment the count of animations read
        animation_count++;
    }
    
    // Close the input file after reading all records
    fclose(input);

    // Prompt the user to enter a release year and read the input
    int release_year;
    printf("Enter release year: ");
    scanf("%d", &release_year);

    // Call the search function to find animations released in or after the specified year and store the results
    int result_count = search(animations, animation_count, release_year, results);
    
    // Open the output CSV file for writing the search results
    FILE *output = fopen(output_filename, "w");
    if (output == NULL) {
        printf("Error opening output file '%s'\n", output_filename);
        return 1;
    }
    
    // Write the header line to the output file and then write each matching animation record
    fprintf(output, "title,year,description\n");
    
    // Loop through the results and write each animation's title, year, and description to the output file
    for (int i = 0; i < result_count; i++) {
        fprintf(output, "%s,%d,%s\n", results[i].title, results[i].year, results[i].description);
    }

    // Close the output file after writing all results
    fclose(output);

    return 0;
}