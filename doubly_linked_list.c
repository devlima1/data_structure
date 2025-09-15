#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *temp = NULL;

void create(struct node **head, struct node **temp) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d", &new_node->data);
    new_node->prev = NULL;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = *temp = new_node;
    } else {
        (*temp)->next = new_node;
        new_node->prev = *temp;
        *temp = new_node;
    }
}

void display(struct node **head, struct node **temp) {
    *temp = *head;

    while(*temp != NULL) {
        printf("%d", (*temp)->data);
        *temp = (*temp)->next;
    }
}
