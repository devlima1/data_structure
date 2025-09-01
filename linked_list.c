#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *new_node = NULL;
    struct node *head = NULL;
    struct node *temp = NULL;
    int choice = 1;
    int count = 0;

    while (choice == 1) {
        new_node = (struct node *) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &new_node->data);

        new_node->next = 0;

        if (head == NULL) {
            head = temp = new_node;
        } else {
            temp->next = new_node; 
            temp = new_node;
        }

        printf("Do you want to continue(0, 1)? ");
        scanf("%d", &choice);
        count++;
    }
    
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("Size: %d", count);
    
    free(new_node);
    new_node = NULL;
    return 0;
}
