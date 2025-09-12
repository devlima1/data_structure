#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
