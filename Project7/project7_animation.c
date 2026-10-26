/*
project7_animation.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description:
    Reads animation movie data from a CSV file, searches for all animations released in or after a user-entered year, and writes all matching records to an output CSV file. 
*/

// Include the standard input/output library
#include <stdio.h> 
#include <stdlib.h>

#define MAX_RECORDS 500
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500
#define input_filename "animation.csv"
#define output_filename "result.csv"

typedef struct {
    char title[MAX_TITLE_LENGTH + 1];
    int year;
    char description[MAX_DESCRIPTION_LENGTH + 1];
} Animation;

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
    static Animation animations[MAX_RECORDS];
    static Animation results[MAX_RECORDS];    
    
    int animation_count = 0;    
    
    FILE *input = fopen(input_filename, "r");
    if (input == NULL) {
        printf("Error opening input file '%s'\n", input_filename);
        return 1;
    }

    fscanf(input, "%*[^\n]\n");
    while (animation_count < MAX_RECORDS && fscanf(input, "%100[^,],%d,%500[^\n]\n", animations[animation_count].title, &animations[animation_count].year, animations[animation_count].description) == 3) {
        animation_count++;
    }
    fclose(input);
    int release_year;
    printf("Enter release year: ");
    scanf("%d", &release_year);
    search(animations, animation_count, release_year, results);
    
    FILE *output = fopen(output_filename, "w");
    if (output == NULL) {
        printf("Error opening output file '%s'\n", output_filename);
        return 1;
    }
    
    fprintf(output, "title,year,description\n");
    for (int i = 0; i < animation_count; i++) {
        if (results[i].year >= release_year) {
            fprintf(output, "%s,%d,%s\n", results[i].title, results[i].year, results[i].description);
        }
    }

    fclose(output);
    return 0;
}