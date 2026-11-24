/*
delete_node.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description: 
    Delete the first point matching given coordinates from a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    struct point *next;
};

struct point *delete_node(struct point *head, int x, int y) {
    /* An empty list has no point to delete. */
    if (head == NULL) {
        return NULL;
    }

    /* Handle a match at the head by updating the list's starting node. */
    if (head->x == x && head->y == y) {
        struct point *removed = head;
        head = head->next;
        free(removed);
        return head;
    }

    /* Search the remaining nodes while retaining the node before each candidate. */
    struct point *current = head;
    while (current->next != NULL) {
        if (current->next->x == x && current->next->y == y) {
            struct point *removed = current->next;
            current->next = removed->next;
            free(removed);
            return head;
        }
        current = current->next;
    }

    /* No matching point was found, so leave the original list unchanged. */
    return head;
}