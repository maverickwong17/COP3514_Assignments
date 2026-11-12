#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256
#define COMMAND_SIZE 32
#define ARG_SIZE 128

/* -------------------------------------------------
   Linked-list node: each node stores one package ID.
   ------------------------------------------------- */
typedef struct Node {
    int id;
    struct Node *next;
} Node;

/* -------------------------------------------------
   STUDENT FUNCTIONS: Complete these four functions.
   Do not change their names or parameter lists.
   ------------------------------------------------- */

/* Append a new package ID at the end of the list. */
Node *add_end(Node *head, int id) {
    /* TODO: Allocate a node and append it to the list.
       If malloc fails, terminate with exit(EXIT_FAILURE). */
    return head; /* Placeholder: replace this statement. */
}

/* Remove the FIRST node whose ID matches id.
   Set *removed to 1 if a node is removed, or 0 otherwise. */
Node *remove_first_match(Node *head, int id, int *removed) {
    /* TODO: If removed is NULL, print:
       Function remove_first_match called without proper arguments
       and terminate with exit(EXIT_FAILURE).
       Otherwise, find and free the first matching node. */
    return head; /* Placeholder: replace this statement. */
}

/* Print: The linked list contains: [10][20] */
void print_list(Node *head) {
    printf("The linked list contains:");
    /* TODO: Print every ID as [id], without spaces. */
    printf("\n");
}

/* Free every node and set *head to NULL. */
void clear_list(Node **head) {
    /* TODO: Release all allocated nodes.
       If head is NULL, safely do nothing. */
}

/* -------------------------------------------------
   PROVIDED FUNCTIONS: Do not modify anything below.
   ------------------------------------------------- */

/* Parse exactly one decimal integer ID in the range 1..9999. */
int parse_package_id(const char *s, int *out) {
    char *endptr = NULL;
    long value;

    if (s == NULL || s[0] == '\0' || out == NULL) {
        return 0;
    }
    value = strtol(s, &endptr, 10);
    if (*endptr != '\0' || value < 1 || value > 9999) {
        return 0;
    }
    *out = (int)value;
    return 1;
}

int main(void) {
    Node *list = NULL;
    char line[LINE_SIZE];
    char command[COMMAND_SIZE];
    char argument[ARG_SIZE];
    char extra[ARG_SIZE];
    int count;

    printf("Welcome to the Package Tracking System!\n");

    for (;;) {
        printf("\nEnter a command: ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        /* Discard any characters that do not fit in the input buffer. */
        if (strchr(line, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                /* discard */
            }
        }

        count = sscanf(line, "%31s %127s %127s", command, argument, extra);
        if (count < 1) {
            printf("--> ERROR: Invalid Command\n");
            continue;
        }

        if (strcmp(command, "exit") == 0 && count == 1) {
            printf("\nThank you for using the Package Tracking System!\n");
            break;
        }

        if (strcmp(command, "add") == 0 || strcmp(command, "cancel") == 0) {
            int id;
            if (count != 2 || !parse_package_id(argument, &id)) {
                printf("--> ERROR: Invalid Package ID\n");
                continue;
            }

            if (strcmp(command, "add") == 0) {
                list = add_end(list, id);
                print_list(list);
            } else {
                int removed = 0;
                list = remove_first_match(list, id, &removed);
                if (removed) {
                    printf("Package %d removed.\n", id);
                    print_list(list);
                } else {
                    printf("--> ERROR: Package %d not found\n", id);
                }
            }
            continue;
        }

        if (strcmp(command, "list") == 0 && count == 1) {
            print_list(list);
            continue;
        }

        if (strcmp(command, "clear") == 0 && count == 1) {
            clear_list(&list);
            printf("All packages removed.\n");
            print_list(list);
            continue;
        }

        printf("--> ERROR: Invalid Command\n");
    }

    clear_list(&list);
    return EXIT_SUCCESS;
}
