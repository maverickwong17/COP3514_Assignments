/*
project8.c
Due Date:   11/17/2026
Name:       Maverick Wong
NetID:      U16095228
Description:
    This program implements a simple package tracking system using a linked list.
*/

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
    // Allocate a new node for the package ID.
    Node *new_node = (Node *)malloc(sizeof(Node));
    // Check if the memory allocation was successful.
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the new node with the given ID and set its next pointer to NULL.
    new_node->id = id;
    new_node->next = NULL;
    // If the list is empty, the new node becomes the head of the list.
    if (head == NULL) {
        return new_node;
    }
    // Otherwise, traverse the list to find the last node.
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Append the new node to the end of the list.
    current->next = new_node;
    // return the head of the list.
    return head;
}

/* Remove the FIRST node whose ID matches id.
   Set *removed to 1 if a node is removed, or 0 otherwise. */
Node *remove_first_match(Node *head, int id, int *removed) {
    // Check if the removed pointer is valid.
    if (removed == NULL) {
        printf("Function remove_first_match called without proper arguments\n");
        exit(EXIT_FAILURE);
    }
    // Initialize the removed flag to 0.
    *removed = 0;
    // If the list is empty, return NULL.
    if (head == NULL) {
        return NULL;
    }
    // If the head node matches the ID, remove it.
    if (head->id == id) {
        Node *temp = head;
        head = head->next;
        free(temp);
        *removed = 1;
        return head;
    }
    // Otherwise, traverse the list to find the first matching node.
    Node *current = head;
    while (current->next != NULL) {
        // Check if the next node matches the ID.
        if (current->next->id == id) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            *removed = 1;
            return head;
        }
        current = current->next;
    }
    // If no matching node is found, return the head of the list.
    return head;
}

/* Print: The linked list contains: [10][20] */
void print_list(Node *head) {
    // Print the header of the list.
    printf("The linked list contains:");
    // If the list is not empty, print a space after the header.
    if (head != NULL) {
        printf(" ");
    }
    // Traverse the list and print each node's ID.
    Node *current = head;
    while (current != NULL) {
        printf("[%d]", current->id);
        current = current->next;
    }
    printf("\n");
}

/* Free every node and set *head to NULL. */
void clear_list(Node **head) {
    // If the head pointer is NULL, do nothing.
    if (head == NULL) {
        return;
    }
    // Start from the head of the list.
    Node *current = *head;
    while (current != NULL) {
        // Store the current node in a temporary pointer.
        Node *temp = current;
        // Move to the next node.
        current = current->next;
        // Free the temporary node.
        free(temp);
    }
    // Set the head of the list to NULL.
    *head = NULL;
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
