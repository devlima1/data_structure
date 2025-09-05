#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data u want to insert at beginning: ");
    scanf("%d", &new_node->data);

    if(*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        *head = new_node; 
    }
}

void insert_at_end(struct node **head, struct node **temp){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data u want to insert at end: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
    } else {
        *temp = *head;
        while((*temp)->next != NULL) {
            *temp = (*temp)->next;
        }
        (*temp)->next = new_node; 
    }
}

void insert_after_a_giver_locate(){}

void list_elements(struct node **head){
    struct node *i = *head;

    while(i != NULL) {
        printf("%d ", i->data);
        i = i->next;
    }
}

void count_elements(struct node **head){
    struct node *j = *head;

    int count = 0;

    while(j != NULL) {
        j = j->next;
        count++;
    }
    printf("Size: %d", count);
}

int main() {
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;
    int choice = 1;
    int count = 0;

    while (choice == 1) {
        new_node = (struct node *) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &new_node->data);

        new_node->next = NULL;

        if (head == NULL) {
            head = temp = new_node; 
        } else {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Do you want continue(0, 1)? ");
        scanf("%d", &choice);
        count++;
    }
    insert_at_beginning(&head);    
    insert_at_end(&head, &temp);
    list_elements(&head);
    count_elements(&head);
    /*temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nSize: %d", count);
    */
    free(new_node);
    free(head);
    new_node = NULL;

    return 0;
}
