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

    if(*head == NULL) {
        printf("List is empty");
    } else {
        while(*temp != NULL) {
            printf("%d ", (*temp)->data);
            *temp = (*temp)->next;
        }
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

void insert_at_end(struct node **head, struct node **tail) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter data:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
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

void insert_after_position(struct node **head, struct node **tail) {
    int pos;

    printf("Enter position:");
    scanf("%d", &pos);

    int list_size = size(head);

    if(pos < 1 || pos > list_size) {
        printf("Invalid position");
   } else {
        struct node *new_node = (struct node *) malloc(sizeof(struct node)); 

        printf("Enter data:");
        scanf("%d", &new_node->data);
        
        struct node *temp = *head;
        int i = 1;

        while (i < pos) {
            temp = temp->next;
            i++;
        }

        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }
}

void delete_from_beginning(struct node **head, struct node **tail) {
    if(*head == NULL) {
        printf("List is empty");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = *tail = NULL;
    } else {
        struct node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

void delete_from_end(struct node **head, struct node **tail) {
    if(*tail == NULL) {
        printf("List is empty");
    } else if ((*tail)->prev == NULL) {
        free(*tail);
        *head = *tail = NULL;
    } else {
        struct node *temp = *tail;
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        free(temp);
    }
}

void delete_from_position(struct node **head, struct node **tail) {
    int pos;

    printf("Enter pos:");
    scanf("%d", &pos);

    int list_size = size(head);

    if (pos < 1 || pos > list_size) {
        printf("Invalid position");
    } else if (pos == 1) {
        delete_from_beginning(head, tail);
    } else if (pos == list_size) {
        delete_from_end(head, tail);
    } else {
        int i = 1;
        struct node *temp = *head;

        while(i < pos) {
            temp = temp->next; 
            i++;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void reverse(struct node **head, struct node **tail) {
    struct node *current_node = *head;
    struct node *next_node = NULL;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = current_node->prev;
        current_node->prev = next_node;
        current_node = next_node;
    }
    current_node = *head;
    *head = *tail;
    *tail = current_node;
}

int main() {
    int choice;
    int list_size;

    do {
        printf("\n1. Create\n");
        printf("2. Display\n"); 
        printf("3. Size\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at end\n");
        printf("6. Insert at position\n");
        printf("7. Insert after position\n");
        printf("8. Delete from Beginning\n");
        printf("9. Delete from End\n");
        printf("10. Delete from Position\n");
        printf("11. Reverse List\n");
        printf("0. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create(&head, &tail);
                break;
            case 2:
                display(&head, &temp);
                break;
            case 3:
                list_size = size(&head);
                printf("%d", list_size);
                break;
            case 4:
                insert_at_beginning(&head, &tail);
                break;
            case 5:
                insert_at_end(&head, &tail);
                break;
            case 6:
                insert_at_position(&head, &tail);
                break;
            case 7:
                insert_after_position(&head, &tail);
                break;
            case 8:
                delete_from_beginning(&head, &tail);
                break;
            case 9:
                delete_from_end(&head, &tail);
                break;
            case 10:
                delete_from_position(&head, &tail);
                break;
            case 11:
                reverse(&head, &tail);
                break;
            default:
                printf("Invalid choice");
            case 0:
                printf("Bye");
                break;
        }
    }while(choice!=0);

    return 0;
}
