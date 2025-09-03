#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void insert_at_beginning(){
    struct node *new_node = NULL;
    struct node *head = NULL;

    new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data u want to insert: ");
    scanf("%d", &new_node->data);

    if(head == NULL) {
        head = new_node; 
    } else {
        new_node->next = head;
        head = new_node; 
    }
}
void insert_at_end(){}
void insert_after_a_giver_locate(){}

int main() {
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;
    int choice = 1;
    int count = 0;

    while (choice != 0) {
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
    insert_at_beginning();    

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nSize: %d", count);

    free(new_node);
    new_node = NULL;

    return 0;
}
