/*
template.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description:

*/

// Include the standard library
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for item name and color
#define MAX_NAME_LEN 50

struct item
{
    char name[MAX_NAME_LEN+1];
    char color[MAX_NAME_LEN+1];
    double unit_price;
    int quantity;
    struct item *next;
};

typedef struct item Item;

//function prototypes
Item *add_to_ordered_list(Item *list);
Item *delete_from_list(Item *list);
void print_list(Item *list);
void clear_list(Item *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    Item *item_list = NULL;
    printf("Operation Code:\n"
           "a = add item\n"
           "r = remove stock\n"
           "p = print inventory\n"
           "q = quit\n\n");
    for (;;){
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code){
            case 'a':
                item_list = add_to_ordered_list(item_list);
                break;
            case 'r':
                item_list = delete_from_list(item_list);
                break;
            case 'p':
                print_list(item_list);
                break;
            case 'q':
                clear_list(item_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

/* 
 * add_to_ordered_list: add a new item to the list in order. If the item already exists, update the quantity. 
 */
Item *add_to_ordered_list(Item *list){
    // Allocate memory for a new item node
    Item *node = malloc(sizeof *node);
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return list;
    }
    // Read item details from the user
    printf("Enter item name: ");
    read_line(node->name, MAX_NAME_LEN);
    printf("Enter color: ");
    read_line(node->color, MAX_NAME_LEN);
    printf("Unit price $ ");
    scanf("%lf", &node->unit_price);
    printf("Enter quantity: ");
    scanf("%d", &node->quantity);
    node->next = NULL;
    // Use a pointer to pointer to traverse the list and find the correct position for the new node
    Item **position = &list;
    while (*position != NULL) {
        // Compare the new node with the current node to determine the order
        int name_order = strcmp((*position)->name, node->name);
        int color_order = strcmp((*position)->color, node->color);
        // If the item already exists, update the quantity and free the new node
        if (name_order == 0 && color_order == 0 && (*position)->unit_price == node->unit_price) {
            (*position)->quantity += node->quantity;
            // Free the newly created node since we are not adding it to the list
            free(node);
            return list;
        }
        // Determine if the new node should be inserted before the current node
        if (name_order > 0 || (name_order == 0 && color_order > 0) || (name_order == 0 && color_order == 0 && (*position)->unit_price > node->unit_price)) {
            break;
        }
        // Move to the next position in the list
        position = &(*position)->next;
    }
    // Insert the new node at the correct position in the list
    node->next = *position;
    *position = node;
    return list;
}

/* 
 * delete_from_list: delete an item from the list based on the name, color, and quantity. If the item is found and has enough quantity, reduce the quantity or remove the item if quantity becomes zero.
 */
Item *delete_from_list(Item *list){
    // Allocate memory for the item details to be read from the user
    char name[MAX_NAME_LEN + 1];
    char color[MAX_NAME_LEN + 1];
    int quantity;
    // Prompt the user for item details
    printf("Enter item name: ");
    read_line(name, MAX_NAME_LEN);
    printf("Enter color: ");
    read_line(color, MAX_NAME_LEN);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    // Initialize variables to track if the item is found and to keep track of the cheapest match
    int found_item = 0;
    // Use a pointer to pointer to traverse the list and find the item
    Item **cheapest_match = NULL;
    Item **position = &list;
    // Traverse the list to find the item with the specified name and color
    while (*position != NULL) {
        // Check if the current item matches the specified name and color
        if (strcmp((*position)->name, name) == 0 && strcmp((*position)->color, color) == 0) {
            // Mark that the item has been found
            found_item = 1;
            // Check if the current item has enough quantity and is cheaper than any previously found match
            if ((*position)->quantity >= quantity && (cheapest_match == NULL || (*position)->unit_price < (*cheapest_match)->unit_price)) {
                // Update the cheapest match to the current position
                cheapest_match = position;
            }
        }
        // Move to the next position in the list
        position = &(*position)->next;
    }
    // If the item was not found, print a message and return the list
    if (!found_item) {
        printf("item not found\n");
        return list;
    }
    // If no item with enough quantity was found, print a message and return the list
    if (cheapest_match == NULL) {
        printf("not enough quantity found\n");
        return list;
    }
    // If a suitable item was found, reduce its quantity and remove it from the list if the quantity becomes zero
    Item *item = *cheapest_match;
    item->quantity -= quantity;
    // If the quantity becomes zero, remove the item from the list and free its memory
    if (item->quantity == 0) {
        *cheapest_match = item->next;
        free(item);
        printf("item deleted\n");
    }

    return list;
}

/*
 * print_list: print the item name, color, unit price, and 
 *             quantity in the list from the head to the end.
 */
void print_list(Item *list){
    Item *p;
    printf("%-32s%-15s%10s%11s\n", "Item Name", "Color", "Unit Price", "Quantity");
    for (p = list; p != NULL; p = p->next)
    printf("%-32s%-15s%10.2f%11d\n", p->name, p->color, p->unit_price, p->quantity);
}

/*
 * clear_list: deallocate all the memory allocated for the 
 *             linked list.
 */
void clear_list(Item *list){
    Item *p;
    while (list != NULL){
        p = list;
        list = list->next;
        if (p != NULL)
            free(p);
    }
}

/*
 * read_line: read a line of text from the user.
 */
int read_line(char str[], int n){
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;

    str[i++] = ch;
    while ((ch = getchar()) != '\n'){
        if (i < n)
            str[i++] = ch;
    }

    str[i] = '\0';
    return i;
}