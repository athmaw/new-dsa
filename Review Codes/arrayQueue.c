#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int count;
} List;

typedef struct{
    List L;
    int front;
    int rear;
} Queue;

Queue Q;

void initQueue(Queue *Q);
bool isFull(Queue *Q);
bool isEmpty(Queue *Q);
void enqueue(Queue *Q, int val);
int dequeue(Queue *Q);
int front(Queue *Q);
int rear(Queue *Q);
void display(Queue *Q);

int main() {
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
    Q->front = 1;
    Q->rear = 0;
    Q->L.count = 0;
}

bool isFull(Queue *Q) {
    return Q->L.count == MAX;
}

bool isEmpty(Queue *Q) {
    return Q->L.count == 0;
}

void enqueue(Queue *Q, int val) {
    if(!isFull(Q)) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->L.items[Q->rear] = val;
        Q->L.count++;
    } else{
        printf("Queue is full. Can't enqueue.\n");
    }
}

int dequeue(Queue *Q) {
    if(!isEmpty(Q)) {
        int val = Q->L.items[Q->front];
        Q->front = (Q->front + 1) % MAX;
        Q->L.count--;

        return val;
    } else{
        printf("Queue is empty. Can't dequeue.\n");
    }
}

int front(Queue *Q) {
    if(!isEmpty(Q)) {
        return Q->L.items[Q->front];
    } else{
        printf("Queue is empty. No front element.\n");
    }
}

int rear(Queue *Q) {
    if(!isEmpty(Q)) {
        return Q->L.items[Q->rear];
    } else{
        printf("Queue is empty. No rear element.\n");
    }
}

void display(Queue *Q) {
    if(!isEmpty(Q)) {
        int i = Q->front;
        int count = Q->L.count;

        while(count > 0) {
            printf("%d ", Q->L.items[i]);
            i = (i + 1) % MAX;
            count--;
        }
        printf("\n");
    } else{
        printf("Queue is empty. Nothing to display.\n");
    }
}