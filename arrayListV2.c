#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    char fname[24];
    char lname[16];
    char MI;
    int age;
} Person;

typedef struct{
    Person personInfo[MAX];
    int count;
} Etype, *EPtr;

EPtr initList();
bool insertPos(EPtr L, Person p, int pos);
bool deletePos(EPtr L, int pos);
int search(EPtr L, char lname[]);
bool insertSorted(EPtr L, Person p);
void display(EPtr L);

int main() {
    EPtr L = initList();

    Person p1 = {"Maryjed", "Divinagracia", 'A', 24};
    Person p2 = {"Elaine", "LLanos", 'B', 21};
    Person p3 = {"Anya", "Sungahid", 'C', 19};

    insertSorted(L, p1);
    insertSorted(L, p2);
    insertSorted(L, p3);

    printf("--- List after Inserting Sorted ---\n");
    display(L);

    printf("\n--- List after Deleting Position 1 ---\n");
    deletePos(L, 0);
    display(L);

    printf("\n--- Searching for 'LLanos' ---\n");
    int pos = search(L, "LLanos");
    if(pos != -1) {
        printf("Found at position: %d\n", pos);
    } else {
        printf("Not Found.\n");
    }

    printf("\n--- Inserting 'Ella Wu' at Position 1 ---\n");
    Person p4 = {"Ella", "Wu", 'D', 20};
    insertPos(L, p4, 1);
    display(L);

    return 0;
}

EPtr initList() {
    EPtr L = (EPtr)malloc(sizeof(Etype));
    
    if(L != NULL) {
        L->count = 0;
    } else{
        printf("[ERROR] Memory Allocation Failed.\n");
    }
    return L;
}

bool insertPos(EPtr L, Person p, int pos) {
    bool success = false;

    if(L->count < MAX && pos >= 0 && pos <= L->count) {
        int i;

        for(i = L->count; i > pos; i--) {
            L->personInfo[i] = L->personInfo[i - 1];
        }

        L->personInfo[pos] = p;
        L->count++;
        success = true;
    } else{
        printf("[ERROR] List is Full or Invalid Position.\n");
    }
    return success;
}

bool deletePos(EPtr L, int pos) {
    bool success = false;

    if(pos >= 0 && pos < L->count) {
        int i;

        for(i = pos; i < L->count - 1; i++) {
            L->personInfo[i] = L->personInfo[i + 1];
        }

        L->count--;
        success = true;
    } else{
        printf("[ERROR] Invalid Position.\n");
    }
    return success;
}

int search(EPtr L, char lname[]) {
    int i = 0;
    int foundPos = -1;

    if(L != NULL) {
        while(i < L->count && foundPos == -1) {
            if(strcmp(L->personInfo[i].lname, lname) == 0) {
                foundPos = i;
            } else{
                i++;
            }
        }
    }
    return foundPos;
}

bool insertSorted(EPtr L, Person p) {
    bool success = false;

    if(L->count < MAX) {
        int i = 0;

        while(i < L->count && strcmp(L->personInfo[i].lname, p.lname) < 0) {
            i++;
        }
        success = insertPos(L, p, i);
    } else{
        printf("[ERROR] List is Full.\n");
    }
    return success;
}

void display(EPtr L) {
    if(L != NULL) {
        int i = 0;

        while(i < L->count) {
            printf("Name: %s %s %c, Age: %d\n", 
                L->personInfo[i].fname, 
                L->personInfo[i].lname, 
                L->personInfo[i].MI, 
                L->personInfo[i].age);
            i++;
        }
    } else{
        printf("[ERROR] List is Empty.\n");
    }
}