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

typedef struct{
    Node *head;
    int count;
} List, *ListPtr;

ListPtr initList();
bool insertPos(ListPtr L, Person p, int pos);
bool deletePos(ListPtr L, int pos);
int search(ListPtr L, char fname[]);
bool insertSorted(ListPtr L, Person p);
void display(ListPtr L);

int main() {
    ListPtr L = initList();

    Person p1 = {"Maryjed", "Divinagracia", 'A', 24};
    Person p2 = {"Elaine", "LLanos", 'B', 21};
    Person p3 = {"Anya", "Sungahid", 'C', 19};

    insertSorted(L, p1);
    insertSorted(L, p2);
    insertSorted(L, p3);

    printf("--- List after Inserting Sorted ---\n");
    display(L);

    printf("\n--- List after Deleting Position 2 ---\n");
    deletePos(L, 2);
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
    insertPos(L, p4, 2);
    display(L);

    return 0;
}

ListPtr initList() {
    ListPtr L = (ListPtr)malloc(sizeof(List));
    
    if(L != NULL) {
        L->head = NULL;
        L->count = 0;
    } else{
        printf("[ERROR] Memory Allocation Failed.\n");
    }
    return L;
}

bool insertPos(ListPtr L, Person p, int pos) {
    bool success = false;

    if(pos >= 0 && pos <= L->count) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        
        if(newNode != NULL) {
            newNode->personInfo = p;
            newNode->next = NULL;

            if(pos == 0) {
                newNode->next = L->head;
                L->head = newNode;
            } else{
                Node *curr = L->head;
                int i;

                for(i = 0; i < pos - 1; i++) {
                    curr = curr->next;
                }

                newNode->next = curr->next;
                curr->next = newNode;
            }
            L->count++;
            success = true;
        } else{
            printf("[ERROR] Memory Allocation Failed.\n");
        }
    } else{
        printf("[ERROR] Invalid Position.\n");
    }
    return success;
}

bool deletePos(ListPtr L, int pos) {
    bool success = false;

    if(pos >= 0 && pos < L->count) {
        Node *temp;

        if(pos == 0) {
            temp = L->head;
            L->head = L->head->next;
            free(temp);
        } else{
            Node *curr = L->head;
            int i;

            for(i = 0; i < pos - 1; i++) {
                curr = curr->next;
            }

            temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        }
        L->count--;
        success = true;
    } else{
        printf("[ERROR] Invalid Position.\n");
    }
    return success;
}

int search(ListPtr L, char fname[]) {
    int pos = 0;
    int foundPos = -1;
    Node *curr = L->head;

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

bool insertSorted(ListPtr L, Person p) {
    bool success = false;
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL) {
        newNode->personInfo = p;
        newNode->next = NULL;

        if(L->head == NULL || strcmp(L->head->personInfo.lname, p.lname) >= 0) {
            newNode->next = L->head;
            L->head = newNode;
        } else{
             Node *curr = L->head;

            while(curr->next != NULL && strcmp(curr->next->personInfo.lname, p.lname) < 0) {
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }
        L->count++;
        success = true;
    } else{
        printf("[ERROR] Memory Allocation Failed.\n");
    }
    return success;
}

void display(ListPtr L) {
    if(L != NULL) {
        Node *curr = L->head;
        int i = 0;

        while(curr != NULL) {
            printf("Name: %s %s %c, Age: %d\n", 
                curr->personInfo.fname, 
                curr->personInfo.lname, 
                curr->personInfo.MI, 
                curr->personInfo.age);
            curr = curr->next;
            i++;
        }
    } else{
        printf("[ERROR] Invalid Position or List is Empty.\n");
    }
}