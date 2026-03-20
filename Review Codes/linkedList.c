#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    int count;
} List;

List *initList();
void empty(List *L);
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void insertPos(List *L, int data, int Ndex);
void deleteStart(List *L);
void deleteLast(List *L);
void deletePos(List *L, int Ndex);
int retrieve(List *L, int Ndex);
int locate(List *L, int data);
void display(List *L);

int main() {
    List *L = initList();
    insertLast(L, 5);
    insertLast(L, 10);
    insertLast(L, 15);

    printf("List after inserting 5, 10, 15: ");
    display(L);

    deletePos(L, 1);

    printf("List after deleting position 1: ");
    display(L);

    int pos = locate(L, 15);

    if(pos != -1) {
        printf("Element 15 found at position: %d \n", pos);
    } else {
        printf("Element 15 not found in the list. ");
    }

    insertPos(L, 20, pos + 1);
    printf("List after inserting 20 in sorted order: ");
    display(L);

    empty(L);

    free(L);

    return 0;
}

List *initList() {
    List *L = (List*)malloc(sizeof(List));

    if(L == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    L->head = NULL;
    L->count = 0;

    return L;
}

void empty(List *L) {
    Node *current = L->head;
    Node *temp;

    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    L->head = NULL;
    L->count = 0;
}

void insertFirst(List *L, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = L->head;
    L->head = newNode;
    L->count++;
}

void insertLast(List *L, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(L->head == NULL) {
        L->head = newNode;
    } else{
        Node *curr = L->head;
        
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    L->count++;
}

void insertPos(List *L, int data, int Ndex) {
    if(Ndex <= L->count) {
        if(Ndex == 0) {
            insertFirst(L, data);
        } else{
            Node *newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            Node *curr = L->head;
            int i;

            for(i = 0; i < Ndex - 1; i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
            L->count++;
        }
    }
}

void deleteStart(List *L) {
    Node *temp = L->head;

    if(temp != NULL) {
        L->head = temp->next;
        free(temp);
        L->count--;
    }
}

void deleteLast(List *L) {
    if(L->head != NULL) {
        if(L->head->next == NULL) {
            deleteStart(L);
        } else{
            Node *curr = L->head;

            while(curr->next->next != NULL) {
                curr = curr->next;
            }
            Node *temp = curr->next;
            curr->next = NULL;
            free(temp);
            L->count--;
        }
    }
}

void deletePos(List *L, int Ndex) {
    if(Ndex < L->count) {
        if(Ndex == 0) {
            deleteStart(L);
        } else{
            Node *curr = L->head;
            int i;

            for(i = 0; i < Ndex - 1; i++) {
                curr = curr->next;
            }
            Node *temp = curr->next;
            curr->next = curr->next->next;
            free(temp);

            L->count--;
        }
    }
}

int retrieve(List *L, int Ndex) {
    if(Ndex < L->count) {
        Node *curr = L->head;
        int i;

        for(i = 0; i < Ndex; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
    return -1;
}

int locate(List *L, int data) {
    if(L->head != NULL) {
        Node *curr = L->head;
        int Ndex = 0;

        for(; curr != NULL; curr = curr->next) {
            if(curr->data == data) {
                return Ndex;
            }
            Ndex++;
        }
    }
    return -1;
}

void display(List *L) {
    if(L->head != NULL) {
        Node *curr = L->head;

        while(curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}