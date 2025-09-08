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

void delete_from_beginning(struct node **head){
    struct node *temp = *head;
    
    if(*head == NULL) {
        printf("List is empty.");
    } else {
        *head = temp->next;

        free(temp);
        temp = NULL;

        printf("Node deleted.");
    }
}

void delete_from_end(){}
void delete_from_specified_position(){}

void display(struct node **head){
    struct node *temp = *head;
    
    if (temp == NULL) {
        printf("List is empty.");
    } else {
        printf("List: ");

        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void size(struct node **head){
    struct node *temp = *head;
    int count = 0;

    if(temp == NULL) {
        printf("List is empty.");
    } else {
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        printf("Size: %d", count);
    }
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
        printf("4. Deleted from beginning\n");
        printf("5. Deleted from end\n");
        printf("6. Deleted from specified position\n");
        printf("7. List elements\n");
        printf("8. Count elements\n");
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
                delete_from_beginning(&head);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                display(&head);
                break;
            case 8:
                size(&head);
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
