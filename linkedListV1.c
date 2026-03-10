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
int search(LinkedList L, char fname[]);
LinkedList insertSorted(LinkedList L, Person p);
void display(LinkedList L);

int main() {
    LinkedList L = initList();

    Person p1 = {"Maryjed", "Divinagracia", 'A', 24};
    Person p2 = {"Elaine", "LLanos", 'B', 21};
    Person p3 = {"Anya", "Sungahid", 'C', 19};

    L = insertSorted(L, p1);
    L = insertSorted(L, p2);
    L = insertSorted(L, p3);

    printf("--- List after Inserting Sorted ---\n");
    display(L);

    printf("\n--- List after Deleting Position 2 ---\n");
    L = deletePos(L, 2);
    display(L);

    printf("\n--- Searching for 'Maryjed' ---\n");
    int pos = search(L, "Maryjed");
    if(pos != -1) {
        printf("Found at position: %d\n", pos);
    } else {
        printf("Not Found.\n");
    }

    printf("\n--- Inserting 'Ella Wu' at Position 2 ---\n");
    Person p4 = {"Ella", "Wu", 'D', 20};
    L = insertPos(L, p4, 2);
    display(L);

    return 0;
}

LinkedList initList() {
    LinkedList L = NULL;

    return L;
}

LinkedList insertPos(LinkedList L, Person p, int pos) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode != NULL && pos >= 0) {
        newNode->personInfo = p;
        newNode->next = NULL;

        if(pos == 0) {
            newNode->next = L;
            L = newNode;
        } else{
            Node *curr = L;
            int i = 0;

            while(i < pos - 1 && curr != NULL) {
                curr = curr->next;
                i++;
            }

            if(curr != NULL) {
                newNode->next = curr->next;
                curr->next = newNode;
            } else{
                printf("[ERROR] Invalid Position.\n");
                free(newNode);
            }
        }
    } else{
        printf("[ERROR] Memory Allocation Failed or Invalid Position.\n");
    }
    return L;
}

LinkedList deletePos(LinkedList L, int pos) {
    if(L != NULL && pos >= 0) {
        Node *temp;

        if(pos == 0) {
            temp = L;
            L = L->next;
            free(temp);
        } else{
            Node *curr = L;
            int i = 0;

            while(i < pos - 1 && curr != NULL) {
                curr = curr->next;
                i++;
            }

            if(curr != NULL && curr->next != NULL) {
                temp = curr->next;
                curr->next = temp->next;
                free(temp);
            } else{
                printf("[ERROR] Invalid Position.\n");
            }
        }
    } else{
        printf("[ERROR] Invalid Position or List is Empty.\n");
    }
    return L;
}

int search(LinkedList L, char fname[]) {
    Node *curr = L;
    int pos = 0;
    int foundPos = -1;

    while(curr != NULL && foundPos == -1) {
        if(strcmp(curr->personInfo.fname, fname) == 0) {
            foundPos = pos;
        } else{
            curr = curr->next;
            pos++;
        }
    }
    return foundPos;
}

LinkedList insertSorted(LinkedList L, Person p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode != NULL) {
        newNode->personInfo = p;
        newNode->next = NULL;

        if(L == NULL || strcmp(p.fname, L->personInfo.fname) < 0) {
            newNode->next = L;
            L = newNode;
        } else{
            Node *curr = L;

            while(curr->next != NULL && strcmp(p.fname, curr->next->personInfo.fname) >= 0) {
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }
    } else{
        printf("[ERROR] Memory Allocation Failed.\n");
    }
    return L;
}

void display(LinkedList L) {
    Node *curr = L;

    while(curr != NULL) {
        printf("Name: %s %s %c, Age: %d\n", 
            curr->personInfo.fname, 
            curr->personInfo.lname, 
            curr->personInfo.MI, 
            curr->personInfo.age);
        curr = curr->next;
    }
}