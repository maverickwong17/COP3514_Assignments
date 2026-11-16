#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 * add comments 
 */
Item *add_to_ordered_list(Item *list){

    // write your own code

}

/* 
 * add comments
 */
Item *delete_from_list(Item *list){

    // write your own code
    
}

/*
 * print_list: print the item name, color, unit price, and 
 *             quantity in the list from the head to the end.
 */
void print_list(Item *list){
    Item *p;
    printf("\nItem Name\t\t\tColor\t\tUnit Price\t\tQuantity\n");
    for (p = list; p != NULL; p = p->next)
        printf("%-40s%-12s%13.2f%8d\n");
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