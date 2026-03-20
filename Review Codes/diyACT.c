#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char STRING[50];

typedef struct{
    STRING studName;
    STRING course;
    int year;
    int ID;
} Student_Type;

typedef struct node{
    Student_Type data;
    struct node *next;
} Node_Type, *Node_Ptr;

void initList(Node_Ptr *list);
void insertFront(Node_Ptr *list);
void insertRear(Node_Ptr *list);
void insertAt(Node_Ptr *list, int pos);
void deleteFront(Node_Ptr *list);
void deleteRear(Node_Ptr *list);
void deleteAt(Node_Ptr *list, int pos);
void display(Node_Ptr list);

int main() {
    Node_Ptr studentList;
    initList(&studentList);

    insertRear(&studentList);
    insertRear(&studentList);
    insertRear(&studentList);

    printf("Student List after inserting 3 students at rear: \n");
    display(studentList);
    printf("\n");

    deleteAt(&studentList, 1);
    printf("Student List after deleting student at position 1: \n");
    display(studentList);

    insertAt(&studentList, 1);
    printf("Student List after inserting a student at position 1: \n");
    display(studentList);

    return 0;
}

void initList(Node_Ptr *list) {
    *list = NULL;
}

void insertFront(Node_Ptr *list) {
    Node_Ptr newNode = (Node_Ptr)malloc(sizeof(Node_Type));

    printf("Enter student name: ");
    fgets(newNode->data.studName, sizeof(newNode->data.studName), stdin);
    newNode->data.studName[strcspn(newNode->data.studName, "\n")] = '\0';

    printf("Enter course: ");
    fgets(newNode->data.course, sizeof(newNode->data.course), stdin);
    newNode->data.course[strcspn(newNode->data.course, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &newNode->data.year);

    printf("Enter ID: ");
    scanf("%d", &newNode->data.ID);

    newNode->next = *list;
    *list = newNode;
}

void insertRear(Node_Ptr *list) {
    Node_Ptr newNode = (Node_Ptr)malloc(sizeof(Node_Type));

    printf("Enter student name: ");
    fgets(newNode->data.studName, sizeof(newNode->data.studName), stdin);
    newNode->data.studName[strcspn(newNode->data.studName, "\n")] = '\0';

    printf("Enter course: ");
    fgets(newNode->data.course, sizeof(newNode->data.course), stdin);
    newNode->data.course[strcspn(newNode->data.course, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &newNode->data.year);

    printf("Enter ID: ");
    scanf("%d", &newNode->data.ID);

    newNode->next = NULL;

    if(*list == NULL) {
        *list = newNode;
    } else{
        Node_Ptr temp = *list;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAt(Node_Ptr *list, int pos) {
    Node_Ptr newNode = (Node_Ptr)malloc(sizeof(Node_Type));

    printf("Enter student name: ");
    fgets(newNode->data.studName, sizeof(newNode->data.studName), stdin);
    newNode->data.studName[strcspn(newNode->data.studName, "\n")] = '\0';

    printf("Enter course: ");
    fgets(newNode->data.course, sizeof(newNode->data.course), stdin);
    newNode->data.course[strcspn(newNode->data.course, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &newNode->data.year);

    printf("Enter ID: ");
    scanf("%d", &newNode->data.ID);

    if(pos == 0) {
        insertFront(list);
    } else{
        Node_Ptr temp = *list;
        int i;

        for(i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if(temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else{
            printf("Position out of bounds. Inserting at rear.\n");
            insertRear(list);
        }
    }
}

void deleteFront(Node_Ptr *list) {
    if(*list != NULL) {
        Node_Ptr temp = *list;
        *list = (*list)->next;
        free(temp);
    }
}

void deleteRear(Node_Ptr *list) {
    if(*list != NULL) {
        if((*list)->next == NULL) {
            deleteFront(list);
        } else{
            Node_Ptr temp = *list;

            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            Node_Ptr toDelete = temp->next;
            temp->next = NULL;

            free(toDelete);
        }
    }
}

void deleteAt(Node_Ptr *list, int pos) {
    if(*list != NULL) {
        if(pos == 0) {
            deleteFront(list);
        } else{
            Node_Ptr temp = *list;
            int i;

            for(i = 0; i < pos - 1 && temp->next != NULL; i++) {
                temp = temp->next;
            }

            if(temp->next != NULL) {
                Node_Ptr toDelete = temp->next;
                temp->next = temp->next->next;

                free(toDelete);
            } else{
                printf("Position out of bounds. Cannot delete.\n");
            }
        }
    }
}

void display(Node_Ptr list) {
    Node_Ptr temp = list;

    while(temp != NULL) {
        printf("Name: %s, Course: %s\n", temp->data.studName, temp->data.course);
        temp = temp->next;
    }
    printf("\n");
}