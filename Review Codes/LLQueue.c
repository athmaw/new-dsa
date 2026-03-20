#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *Q);
bool isFull(Queue *Q);
bool isEmpty(Queue *Q);
void enqueue(Queue *Q, int val);
int dequeue(Queue *Q);
int front(Queue *Q);
int rear(Queue *Q);
void display(Queue *Q);

int main() {
    Queue Q;
    initQueue(&Q);
    enqueue(&Q, 5);
    enqueue(&Q, 10);
    enqueue(&Q, 15);

    printf("Queue after enqueuing: ");
    display(&Q);

    int dequeued = dequeue(&Q);
    printf("Dequeued element: %d \n", dequeued);

    printf("Queue after dequeuing: ");
    display(&Q);

    int frontElement = front(&Q);
    printf("Front element: %d \n", frontElement);

    int rearElement = rear(&Q);
    printf("Rear element: %d \n", rearElement);

    return 0;
}

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

bool isFull(Queue *Q) {
    return false;
}

bool isEmpty(Queue *Q) {
    return Q->front == NULL;
}

void enqueue(Queue *Q, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(isEmpty(Q)) {
        Q->front = newNode;
    } else{
        Q->rear->next = newNode;
    }
    Q->rear = newNode;
}

int dequeue(Queue *Q) {
    if(!isEmpty(Q)) {
        Node *temp = Q->front;
        int val = temp->data;
        Q->front = Q->front->next;
        free(temp);

        return val;
    } else{
        printf("Queue is empty. Cannot dequeue.\n");
    }
}

int front(Queue *Q) {
    if(!isEmpty(Q)) {
        return Q->front->data;
    } else{
        printf("Queue is empty. Cannot access front.\n");
    }
}

int rear(Queue *Q) {
    if(!isEmpty(Q)) {
        return Q->rear->data;
    } else{
        printf("Queue is empty. Cannot access rear.\n");
    }
}

void display(Queue *Q) {
    if(!isEmpty(Q)) {
        Node *curr = Q->front;

        while(curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    } else{
        printf("Queue is empty. Nothing to display.\n");
    }
}