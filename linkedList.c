#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct linkedList {
    struct Node *first;
};

void add (struct linkedList* list, int x) {
    struct Node* newPtr = malloc(sizeof(struct Node));
    newPtr -> data = x;
    newPtr -> next = NULL;
    struct Node* curr = list -> first;
    struct Node* temp = NULL;

    if (curr == NULL) {
        list -> first = newPtr;
        return;
    }

    while (curr != NULL) {
        temp = curr;
        curr = curr -> next;
    }

    temp -> next = newPtr;
}

void deleteValue(struct linkedList* list, int x) {
    struct Node* curr = list -> first;
    struct Node* temp = NULL;
    if (curr == NULL) {
        printf("deleteValue: This list is empty.\n");
    } else if (curr -> data == x) {
        list -> first = curr -> next;
        free(curr);
    } else {
        while (curr -> data != x && curr -> next != NULL) {
            temp = curr;
            curr = curr -> next;
        }

        if (curr -> next == NULL) {
            printf("%d not found.\n", x);
        } else {
            temp -> next = curr -> next;
            free(curr);
        }
    }
}

void printLinkedList (struct linkedList* list) {
    struct Node* curr = list -> first;

    if (curr == NULL) {
        printf("printLinkedList: This list is empty.");
    }

     while (curr != NULL) {
         printf("%d ", curr -> data);
         curr = curr -> next;
     }

     printf("\n");
}



int main() {
    struct linkedList* lPtr = malloc(sizeof(struct linkedList));
    lPtr -> first = NULL;
    // enter your stuff here
    // more stuff
    // even more stuff
    free(lPtr);
    return 0;
}
