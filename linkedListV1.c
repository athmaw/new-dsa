#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char fname[24];
    char lname[16];
    char MI;
    int age;
} Person;

typedef struct Node {
    Person personInfo;
    struct Node *next;
} Node;

typedef Node *LinkedList;

LinkedList initList();
LinkedList insertPos(LinkedList L, Person p, int pos);
LinkedList deletePos(LinkedList L, int pos);
int search(LinkedList L, char lname[]);
LinkedList insertSorted(LinkedList L, Person p);
void display(LinkedList L);

int main() {
    LinkedList L = initList();

    Person p1 = {"Maryjed", "Divinagracia", 'A', 24};
    Person p2 = {"Elaine", "Jimeno", 'B', 21};
    Person p3 = {"Anya", "Sungahid", 'C', 19};

    L = insertSorted(L, p1);
    L = insertSorted(L, p2);
    L = insertSorted(L, p3);

    printf("--- List after Inserting Sorted ---\n");
    display(L);

    printf("\n--- List after Deleting Position 1 ---\n");
    L = deletePos(L, 0);
    display(L);

    printf("\n--- Searching for 'Sungahid' ---\n");
    int pos = search(L, "Sungahid");
    if(pos != -1) {
        printf("Found at position: %d\n", pos);
    } else {
        printf("Not Found.\n");
    }

    printf("\n---Inserting 'Ella Wu' at Position 1---\n");
    Person p4 = {"Ella", "Wu", 'D', 20};
    L = insertPos(L, p4, 1);
    display(L);

    return 0;
}

LinkedList initList() {
    return NULL;
}

LinkedList insertPos(LinkedList L, Person p, int pos) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->personInfo = p;
    newNode->next = NULL;

    if(pos == 0) {
        newNode->next = L;
        return newNode;
    }

    Node *curr = L;
    int i;

    for(i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("[ERROR] Invalid Position.\n");
        free(newNode);
        return L;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return L;
}

LinkedList deletePos(LinkedList L, int pos) {
    if(L == NULL) {
        printf("[ERROR] List is Empty.\n");
        return L;
    }

    Node *temp;

    if(pos == 0) {
        temp = L;
        L = L->next;
        free(temp);
        return L;
    }

    Node *curr = L;
    int i;

    for(i = 0; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL || curr->next == NULL) {
        printf("[ERROR] Invalid Position.\n");
        return L;
    }

    temp = curr->next;
    curr->next = temp->next;
    free(temp);

    return L;
}

int search(LinkedList L, char lname[]) {
    Node *curr = L;
    int pos = 0;

    while(curr != NULL) {
        if(strcmp(curr->personInfo.lname, lname) == 0) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

LinkedList insertSorted(LinkedList L, Person p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->personInfo = p;
    newNode->next = NULL;

    if(L == NULL || strcmp(L->personInfo.lname, p.lname) >= 0) {
        newNode->next = L;
        return newNode;
    }

    Node *curr = L;
    while(curr->next != NULL && strcmp(curr->next->personInfo.lname, p.lname) < 0) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return L;
}

void display(LinkedList L) {
    Node *curr = L;

    while(curr != NULL) {
        printf("Name: %s %s %c, Age: %d\n", curr->personInfo.fname, curr->personInfo.lname, curr->personInfo.MI, curr->personInfo.age);
        curr = curr->next;
    }
}