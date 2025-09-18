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

int size(struct node **head) {
    struct node *temp = *head;
    int size = 0;

    while(temp != NULL) {
        temp = temp->next;
        size++;
    }

    return size;
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

void insert_at_position(struct node **head, struct node **tail) {
    int pos;

    printf("Enter position:");
    scanf("%d", &pos);

    int list_size = size(head);

    if(pos < 1 || pos > list_size) {
        printf("Invalid position");
    } else if (pos == 1) {
        insert_at_beginning(head, tail);
    } else {
        struct node *new_node = (struct node *) malloc(sizeof(struct node)); 

        printf("Enter data:");
        scanf("%d", &new_node->data);
        
        struct node *temp = *head;
        int i = 1;

        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }

        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }
}
