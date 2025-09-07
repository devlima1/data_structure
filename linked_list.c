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

void insert_after_a_giver_locate(struct node **head){
    struct node *temp = *head;
    int pos;
    int count;
    int i = 1;

    while(temp != NULL) {
        temp = temp->next;
        count++;
    }

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > count) {
        printf("Invalid position");
    } else {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &new_node->data);

      if(pos == 0) {
            new_node->next = *head;
            *head = new_node;
        } else {
            temp = *head;

            while(i < pos) {
                temp = temp->next;
                i++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void list_elements(struct node **head){
    struct node *i = *head;

    printf("List of all the elements: ");
    while(i != NULL) {
        printf("%d ", i->data);
        i = i->next;
    }
}

void count_elements(struct node **head){
    struct node *temp = *head;

    int count = 0;

    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    printf("Size: %d\n", count);
}

int main() {
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;
    int choice;
    int count = 0;

    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a giver location\n");
        printf("4. List elements\n");
        printf("5. Count elements\n");
        printf("0. Left\n");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("tchau");
                break;
            case 1:
                insert_at_beginning(&head);
                break;
            case 2:
                insert_at_end(&head, &temp);
                break;
            case 3:
                insert_after_a_giver_locate(&head);
                break;
            case 4:
                list_elements(&head);
                break;
            case 5:
                count_elements(&head);
                break;
            default:
                printf("Invalid choice");
                break;
        }
        /*
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
    */
    } while(choice != 0);
    /*insert_at_beginning(&head);    
    insert_at_end(&head, &temp);
    list_elements(&head);
    count_elements(&head);*/
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
