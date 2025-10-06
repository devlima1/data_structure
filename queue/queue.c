#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool is_full(int *rear) {
    if(*rear == MAX_SIZE - 1) {
        return true;
    }
    return false;
}

bool is_empty(int *front, int *rear) {
    if(*front == -1 && *rear == -1) {
        return true;
    }
    return false;
}
    
void enqueue(int queue[], int *front, int *rear, int data) {
    if(is_full(rear)) {
        printf("Overflow\n");
    } else if(*front == -1 && *rear == -1) {
        *front = *rear = 0;
        queue[*rear] = data;
    } else {
        (*rear)++;
        queue[*rear] = data;
    }
}

void dequeue(int queue[], int *front, int *rear) {
    if(is_empty(front, rear)) {
        printf("Underflow\n");
    } else if (*front == *rear){
        *front = *rear = -1;
    } else {
        (*front)++;
    }
}

void peek(int queue[], int *front, int *rear) {
    if(is_empty(front, rear)) {
        printf("List is empty\n");
    } else {
        printf("%d\n", queue[*front]);
    }
}

void display(int queue[], int *front, int *rear) {
    if(is_empty(front, rear)) {
        printf("Queue is empty\n");
    } else {
        for(int i = *front; i < (*rear) + 1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int data;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(queue, &front, &rear, data);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;   
            case 3:
                peek(queue, &front, &rear);
                break;
            case 4:
                display(queue, &front, &rear);
                break;
            case 0:
                printf("Bye");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);

    return 0;
}
