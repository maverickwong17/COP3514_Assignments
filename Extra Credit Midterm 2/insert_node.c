/*
insert_node.c
Due Date:   
Name:       Maverick Wong
NetID:      U16095228
Description: 
    Insert a student node into a linked list sorted by student number.
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
    int snumber;
    char firstname[50];
    char lastname[50];
    struct student *next;
};

struct student *insert_node(struct student *list) {
    // Allocate and initialize the node before finding its sorted position.
    struct student *new_node = malloc(sizeof(struct student));
    if (new_node == NULL) {
        return list;
    }

    scanf("%d %49s %49s", &new_node->snumber, new_node->firstname, new_node->lastname);
    new_node->next = NULL;

    // Insert before the head when the new student number is the smallest.
    if (list == NULL || new_node->snumber < list->snumber) {
        new_node->next = list;
        return new_node;
    }

    // Otherwise, find the node that should come immediately before the new node.
    struct student *current = list;
    while (current->next != NULL && current->next->snumber < new_node->snumber) 
    {
        current = current->next;
    }
    // Insert the new node after the current node.
    new_node->next = current->next;
    current->next = new_node;

    return list;
}