#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool is_full(int *top) {
   if(*top == MAX_SIZE-1) {
        return true;
    } 
    return false;
}

bool is_empty(int *top) {
    if(*top == -1) {
        return true;
    }
    return false;
}

void push(int stack[], int *top, int data) {
    if(is_full(top)) {
        printf("Overflow\n");
    } else {
        (*top)++;
        stack[*top] = data;
    }
}

void pop(int stack[], int *top) {
    if(is_empty(top)) {
        printf("Underflow\n");
    } else {
        (*top)--;
    }
}

void peek(int stack[], int *top) {
    if(is_empty(top)) {
        printf("Stack is empty\n");
    } else {
        printf("%d\n", stack[*top]);
    }
}

void display(int stack[], int *top) {
    if(is_empty(top)) {
        printf("Stack is empty\n");
    } else {
        for(int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int data;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(stack, &top, data);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, &top);
                break;
            case 4:
                display(stack, &top);
                break;
            case 0:
                printf("Bye");
                break;
            default:
                printf("Invalid value");
        }

    } while(choice != 0);

    return 0;
}
