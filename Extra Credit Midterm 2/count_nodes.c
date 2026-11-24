/*
count_nodes.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description: 
    Count the nodes containing strictly positive values.
*/

#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

int count_positives(struct node *list) {
    int count = 0;

    /* Traverse the list and count only strictly positive values. */
    while (list != NULL) {
        if (list->data > 0) {
            count++;
        }
        list = list->next;
    }

    return count;
}