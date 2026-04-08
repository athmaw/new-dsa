#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 15
typedef char String[50];

typedef struct{
    String name;
    String ID;
} IGN;

typedef struct{
    float speed;
    float acceleration;
    float weight;
    float handling;
    float traction;
} Stats;

typedef struct{
    String charName;
    float weight;
} Character;

typedef struct{
    String name;
    String desc;
} Item;

typedef struct{
    Stats body;
    Stats wheel;
    Stats glider;
    Stats total;
} Car;

typedef struct{
    IGN account;
    Character Selected;
    Car Chosen;
    int currCoins;
    int maxCoins;
    Item heldItems[3];
} Player;

typedef struct{
    Player racer;
    int next;
} racerNode;

typedef struct{
    racerNode R[MAX];
    int Avail;
} VirtualList;

typedef struct{
    int LIST;
    int count;
} raceList;

void initList(VirtualList *R);
int allocSpace(VirtualList *R);
void deallocSpace(VirtualList *R, int Ndex);
void insertFirst(int *L, VirtualList *R, int elem);
void insertLast(int *L, VirtualList *R, int elem);
void insertPos(int *L, VirtualList *R, int elem);
void insertSorted(int *L, VirtualList *R, int elem);
void delete(int *L, VirtualList *R, int elem);
void deleteAllOccurrence(int *L, VirtualList *R, int elem);
void display(int L, VirtualList R);

int main() {
    
    return 0;
}

void initList(VirtualList *R) {
    
}

int allocSpace(VirtualList *R) {
    
}

void deallocSpace(VirtualList *R, int Ndex) {
    
}

void insertFirst(int *L, VirtualList *R, int elem) {
    
}

void insertLast(int *L, VirtualList *R, int elem) {
    
}

void insertPos(int *L, VirtualList *R, int elem) {
    
}

void insertSorted(int *L, VirtualList *R, int elem) {
    
}

void delete(int *L, VirtualList *R, int elem) {
    
}

void deleteAllOccurrence(int *L, VirtualList *R, int elem) {
    
}

void display(int L, VirtualList R) {
    
}
