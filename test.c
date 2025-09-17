#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
    struct node *p = head;
    printf("\n[");

    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    
    printf("]\n");

}

void insertatbegin(int data) {

    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;

    head = lk;
}

void insertatend(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    struct node *linkedlist = head;

    while(linkedlist->next != NULL) 
        linkedlist = linkedlist->next;
    
    linkedlist->next = lk;
}

int main(int argc, char const *argv[])
{
    int k = 0;
    insertatbegin(12);
    insertatbegin(22);
    insertatbegin(35);
    insertatend(52);
    printList();
    return 0;
}
