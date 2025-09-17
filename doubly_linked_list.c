#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *tail = NULL;

void create(struct node **head, struct node **tail) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d", &new_node->data);
    new_node->prev = NULL;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}

void display(struct node **head, struct node **temp) {
    *temp = *head;

    while(*temp != NULL) {
        printf("%d", (*temp)->data);
        *temp = (*temp)->next;
    }
}

void insert_at_beginning(struct node **head, struct node **tail) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    
    printf("Enter data:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if(*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node;
    }
}

void inset_at_end(struct node **head, struct node **tail) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->prev = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}
