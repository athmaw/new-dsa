#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
} Stack;

Stack S;

void initStack(Stack *S);
bool isFull(Stack *S);
bool isEmpty(Stack *S);
void push(Stack *S, int data);
int pop(Stack *S);
int peek(Stack *S);
int top(Stack *S);
void display(Stack *S);

int main() {
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
    S->top = -1;
}

bool isFull(Stack *S) {
    return S->top == MAX - 1;
}

bool isEmpty(Stack *S) {
    return S->top == -1;
}

void push(Stack *S, int data) {
    if(!isFull(S)) {
        S->items[++S->top] = data;
    } else{
        printf("Stack is full. Cannot push %d\n", data);
    }
}

int pop(Stack *S) {
    if(!isEmpty(S)) {
        return S->items[S->top--];
    } else{
        printf("Stack is empty. Cannot pop.\n");
    }
}

int peek(Stack *S) {
    if(!isEmpty(S)) {
        return S->items[S->top];
    } else{
        printf("Stack is empty. Cannot peek.\n");
    }
}

int top(Stack *S) {
    return peek(S);
}

void display(Stack *S) {
    if(!isEmpty(S)) {
        int i;

        for(i = S->top; i >= 0; i--) {
            printf("%d ", S->items[i]);
        }
        printf("\n");
    } else{
        printf("Stack is empty. Nothing to display.\n");
    }
}