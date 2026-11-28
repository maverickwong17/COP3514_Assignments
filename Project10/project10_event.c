/*
project10_event.c
Due Date:   11/28/2026
Name:       Maverick Wong
NetID:      U16095228
Description:
    This program reads customer records from a CSV file, sorts them by the number of purchases in ascending order, and writes the sorted records to a new CSV file. It uses the qsort() function from the C standard library to perform the sorting, and implements a comparison function to compare customer records based on their purchase counts.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 100
#define MAX_TEXT 100
#define MAX_LINE 256

struct customer {
    char email[MAX_TEXT];
    int purchases;
    char name[MAX_TEXT];
};

int compare_customers(const void *p, const void *q);

int main(void)
{
    struct customer customers[MAX_CUSTOMERS];
    char filename[MAX_TEXT], line[MAX_LINE];
    FILE *input, *output;
    int n = 0, i;

    printf("Enter the file name: ");
    if (scanf("%99s", filename) != 1)
        return 1;

    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    /* Read the customer records (provided). */
    while (n < MAX_CUSTOMERS && fgets(line, sizeof(line), input) != NULL) {
        if (sscanf(line, "%99[^,], %d, %99[^\r\n]",
                   customers[n].email, &customers[n].purchases,
                   customers[n].name) == 3) {
            n++;
        }
    }
    fclose(input);

    /* TODO 1: Call qsort() to sort customers by purchases in ascending order.
       Use compare_customers as the comparison function. */
    qsort(customers, n, sizeof(struct customer), compare_customers);

    /* Write the sorted records to result.csv (provided). */
    output = fopen("result.csv", "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        fprintf(output, "%s, %d, %s\n", customers[i].email,
                customers[i].purchases, customers[i].name);
    }
    fclose(output);
    return 0;
}

/* Compare two customer records by number of purchases. */
int compare_customers(const void *p, const void *q)
{
    // Cast the void pointers to customer pointers for comparison
    const struct customer *customer1 = p;
    const struct customer *customer2 = q;
    // Compare the number of purchases and return the appropriate value
    if (customer1->purchases < customer2->purchases)
        return -1;
    if (customer1->purchases > customer2->purchases)
        return 1;
    return 0;
}
