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
    Person p2 = {"Elaine", "Jimeno", 'B', 21};
    Person p3 = {"Anya", "Sungahid", 'C', 19};

    insertSorted(L, p1);
    insertSorted(L, p2);
    insertSorted(L, p3);

    printf("--- List after Inserting Sorted ---\n");
    display(L);

    printf("\n--- List after Deleting Position 1 ---\n");
    deletePos(L, 0);
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
    insertPos(L, p4, 1);
    display(L);

    return 0;
}

EPtr initList() {
    EPtr L = (EPtr)malloc(sizeof(Etype));
    L->count = 0;
    return L;
}
