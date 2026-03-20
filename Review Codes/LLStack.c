#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *top;
} Stack;

void initStack(Stack *S);
bool isFull(Stack *S);
bool isEmpty(Stack *S);
void push(Stack *S, int val);
int pop(Stack *S);
int peek(Stack *S);
int top(Stack *S);
void display(Stack *S);

int main() {
    Stack S;
    initStack(&S);
    push(&S, 5);
    push(&S, 10);
    push(&S, 15);

    printf("Stack after pushing: ");
    display(&S);

    int popped = pop(&S);
    printf("Popped element: %d \n", popped);

    printf("Stack after popping: ");
    display(&S);

    int topElement = peek(&S);
    printf("Top element: %d \n", topElement);

    return 0;
}

void initStack(Stack *S) {
    S->top = NULL;
}

bool isFull(Stack *S) {
    return false;
}

bool isEmpty(Stack *S) {
    return S->top == NULL;
}

void push(Stack *S, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = S->top;
    S->top = newNode;
}

int pop(Stack *S) {
    if(!isEmpty(S)) {
        Node *temp = S->top;
        int val = temp->data;
        S->top = S->top->next;
        free(temp);

        return val;
    }
}

int peek(Stack *S) {
    if(!isEmpty(S)) {
        return S->top->data;
    }
}

int top(Stack *S) {
    return peek(S);
}

void display(Stack *S) {
    Node *curr = S->top;

    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}