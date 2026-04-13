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
    int points;         // --- NEW: Added points for the leaderboard ---
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
void insertFirst(int *L, VirtualList *R, Player elem);
void insertLast(int *L, VirtualList *R, Player elem);
void insertPos(int *L, VirtualList *R, Player elem);
void insertSorted(int *L, VirtualList *R, Player elem);
void deleteNode(int *L, VirtualList *R, String ID);
void deleteAllOccurrence(int *L, VirtualList *R, String ID);
void display(int L, VirtualList R);

int main() {
        VirtualList R;
        raceList RL;
    
        initList(&R);
        RL.LIST = -1;
        RL.count = 0;
    
        Player p1;
        strcpy(p1.account.ID, "0001");
        strcpy(p1.account.name, "Toad");
        p1.points = 15;

        Player p2;
        strcpy(p2.account.ID, "0002");
        strcpy(p2.account.name, "Daisy");
        p2.points = 12;

        Player p3;
        strcpy(p3.account.ID, "0003");
        strcpy(p3.account.name, "Waluigi");
        p3.points = 10;
        
        insertSorted(&RL.LIST, &R, p2);
        insertSorted(&RL.LIST, &R, p1);
        insertSorted(&RL.LIST, &R, p3);
        
        display(RL.LIST, R);
    
        return 0;
}

void initList(VirtualList *R) {
    int i;

    for(i = 0; i < MAX - 1; i++) {
        R->R[i].next = i + 1;
    }
    R->R[MAX - 1].next = -1;
    R->Avail = 0;
}

int allocSpace(VirtualList *R) {
    int Ndex;

    if(R->Avail == -1) {
        return -1;
    }
    Ndex = R->Avail;
    R->Avail = R->R[Ndex].next;
    R->R[Ndex].next = -1;

    return Ndex;
}

void deallocSpace(VirtualList *R, int Ndex) {
    R->R[Ndex].next = R->Avail;
    R->Avail = Ndex;
}

void insertFirst(int *L, VirtualList *R,  Player elem) {
    int Ndex = allocSpace(R);

    if(Ndex != -1) {
        R->R[Ndex].racer = elem;
        R->R[Ndex].next = *L;
        *L = Ndex;
    }
}

void insertLast(int *L, VirtualList *R, Player elem) {
    int Ndex = allocSpace(R);
    
    if(Ndex != -1) {
        R->R[Ndex].racer = elem;
        R->R[Ndex].next = -1;

        if(*L == -1) {
            *L = Ndex;
        } else{
            int i = *L;

            while(R->R[i].next != -1) {
                i = R->R[i].next;
            }
            R->R[i].next = Ndex;
        }
    }
}

void insertPos(int *L, VirtualList *R, Player elem) {
    int Ndex = allocSpace(R);

    if(Ndex != -1) {
        R->R[Ndex].racer = elem;

        if(*L == -1 || R->R[*L].racer.currCoins  >= elem.currCoins) {
            R->R[Ndex].next = *L;
            *L = Ndex;
        } else{
            int i = *L;

            while(R->R[i].next != -1 && R->R[R->R[i].next].racer.currCoins < elem.currCoins) {
                i = R->R[i].next;
            }
            R->R[Ndex].next = R->R[i].next;
            R->R[i].next = Ndex;
        }
    }
}

void insertSorted(int *L, VirtualList *R, Player elem) {
    int Ndex = allocSpace(R);

    if(Ndex != -1) {
        R->R[Ndex].racer = elem;
        
        if(*L == -1 || R->R[*L].racer.points < elem.points) {
            R->R[Ndex].next = *L;
            *L = Ndex;
        } else{
            int i = *L;
            
            while(R->R[i].next != -1 && R->R[R->R[i].next].racer.points >= elem.points) {
                i = R->R[i].next;
            }
            R->R[Ndex].next = R->R[i].next;
            R->R[i].next = Ndex;
        }
    }
}

void deleteNode(int *L, VirtualList *R, String ID) {
    int *trav;

    for(trav = L; *trav != -1 && strcmp(R->R[*trav].racer.account.ID, ID) != 0; trav = &(R->R[*trav].next)) {}
    if(*trav != -1) {
        int temp = *trav;

        *trav = R->R[temp].next;
        deallocSpace(R, temp);
    }
}

void deleteAllOccurrence(int *L, VirtualList *R, String ID) {
    int *trav = L;

    while(*trav != -1) {
        if(strcmp(R->R[*trav].racer.account.ID, ID) == 0) {
            int temp = *trav;

            *trav = R->R[temp].next;
            deallocSpace(R, temp);
        } else{
            trav = &R->R[*trav].next;
        }
    }
}

void display(int L, VirtualList R) {
    int trav;
    int position = 1;

    printf("\n--- Mario Kart Final Leaderboard ---\n");
    printf("Pos | %-12s | Points\n", "Character");
    printf("------------------------------------\n");
    
    for(trav = L; trav != -1; trav = R.R[trav].next) {
        printf(" %2d | %-12s | %2d\n", 
            position++, 
            R.R[trav].racer.account.name, 
            R.R[trav].racer.points);
    }
    printf("------------------------------------\n");
}
