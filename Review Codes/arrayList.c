#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
} List;

List L;

void initList(List *L);
void insertPos(List *L, int data, int pos);
void deletePos(List *L, int pos);
int locate(List *L, int data);
void insertSorted(List *L, int data);
void display(List *L);

int main() {
    initList(&L);
    insertPos(&L, 5, 0);
    insertPos(&L, 10, 1);
    insertPos(&L, 15, 2);

    printf("List after inserting 5, 10, 15: ");
    display(&L);
    deletePos(&L, 1);

    printf("List after deleting position 1: ");
    display(&L);
    int pos = locate(&L, 15);

    if(pos != -1) {
        printf("Element 15 found at position: %d \n", pos);
    } else {
        printf("Element 15 not found in the list. ");
    }

    insertSorted(&L, 20);
    printf("List after inserting 20 in sorted order: ");
    display(&L);

    return 0;
}

void initList(List *L) {
    L->count = 0;
}

void insertPos(List *L, int data, int pos) {
    if(pos <= L->count && L->count != MAX) {
        int i;

        for(i = L->count - 1; i >= pos; i--) {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[pos] = data;
        L->count++;
    }
}

void deletePos(List *L, int pos) {
    if(pos >= 0 && pos < L->count) {
        int i;

        for(i = pos; i < L->count - 1; i++) {
            L->elem[i] = L->elem[i + 1];
        }
        L->count--;
    }
}

int locate(List *L, int data) {
    int i;

    for(i = 0; i < L->count; i++) {
        if(L->elem[i] == data) {
            return i;
        }
    }
    return -1;
}

void insertSorted(List *L, int data) {
    if(L->count != MAX) {
        int i;

        for(i = L->count - 1; i >= 0 && L->elem[i] > data; i--) {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[i + 1] = data;
        L->count++;
    }
}

void display(List *L) {
    int i;

    for(i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}