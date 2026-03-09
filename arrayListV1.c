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
} List;

List L;

List initList(List L);
List insertPos(List L, Person p, int pos);
List deletePos(List L, int pos);
int search(List L, char lname[]);
List insertSorted(List L, Person p);
void display(List L);

int main() {
    List L;
    L = initList(L);

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

List initList(List L) {
    L.count = 0;
    return L;
}

List insertPos(List L, Person p, int pos) {
    if(L.count >= MAX || pos < 0 || pos > L.count) {
        printf("[ERROR] List is Full or Invalid Position.\n");
        return L;
    }

    int i;
    for(i = L.count; i > pos; i--) {
        L.personInfo[i] = L.personInfo[i - 1];
    }
    L.personInfo[pos] = p;
    L.count++;

    return L;
}

List deletePos(List L, int pos) {
    if(pos < 0 || pos >= L.count) {
        printf("[ERROR] List is Empty or Invalid Position.\n");
        return L;
    }

    int i;
    for(i = pos; i < L.count - 1; i++) {
        L.personInfo[i] = L.personInfo[i + 1];
    }
    L.count--;

    return L;
}

int search(List L, char lname[]) {
    int i;

    for(i = 0; i < L.count; i++) {
        if(strcmp(L.personInfo[i].lname, lname) == 0) {
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, Person p) {
    if(L.count >= MAX) {
        printf("[ERROR] List is Full.\n");
        return L;
    }

    int i = 0;
    while(i < L.count && strcmp(L.personInfo[i].lname, p.lname) < 0) {
        i++;
    }
    return insertPos(L, p, i);
}

void display(List L) {
    int i;

    for(i = 0; i < L.count; i++) {
        printf("Name: %s %c. %s, Age: %d\n", L.personInfo[i].fname, L.personInfo[i].MI, L.personInfo[i].lname, L.personInfo[i].age);
    }
}