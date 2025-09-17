#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StringNode {
    char* str;
    struct StringNode *next;
};

struct ListNode {
    struct StringNode *sublist;
    struct ListNode *next;
};

struct StringNode* createStringNode(const char* text) {
    struct StringNode* newNode = malloc(sizeof *newNode);
    newNode->str = malloc(strlen(text) + 1);
    strcpy(newNode->str, text);
    newNode->next = NULL;
    return newNode;
}

void pushStringBack(struct StringNode** head, const char* text) {
    struct StringNode* newNode = createStringNode(text);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct StringNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void pushStringsArray(struct StringNode** head, const char* arr[], int size) {
    for (int i = 0; i < size; i++)
        pushStringBack(head, arr[i]);
}

struct ListNode* createListNode(struct StringNode* sublist) {
    struct ListNode* newNode = malloc(sizeof *newNode);
    newNode->sublist = sublist;
    newNode->next = NULL;
    return newNode;
}

void pushListBack(struct ListNode** head, struct StringNode* sublist) {
    struct ListNode* newNode = createListNode(sublist);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void pushListsArray(struct ListNode** head, struct StringNode* sublists[], int size) {
    for (int i = 0; i < size; i++)
        pushListBack(head, sublists[i]);
}

void printListOfLists(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        struct StringNode* sub = temp->sublist;
        printf("[ ");
        while (sub != NULL) {
            printf("\"%s\", ", sub->str);
            sub = sub->next;
        }
        printf("]\n");
        temp = temp->next;
    }
}



int main(int argc, char const *argv[]) {
    int numberOfInformation = 6;
    int numberOfBooks = 7;

    struct StringNode* list1 = NULL;
    const char* book1[] = {"Harry Potter and the Philosopher`s Stone", "10$", "223", "Ukranian", "500", "1997"};
    pushStringsArray(&list1, book1, numberOfInformation);

    struct StringNode* list2 = NULL;
    const char* book2[] = {"Harry Potter and the Chamber of Secrets", "12$", "251", "Ukranian", "550", "1998"};
    pushStringsArray(&list2, book2, numberOfInformation);

    struct StringNode* list3 = NULL;
    const char* book3[] = {"Harry Potter and the Prisoner of Azkaban", "15$", "317", "Ukrainian", "600", "1999"};
    pushStringsArray(&list3, book3, numberOfInformation);

    struct StringNode* list4 = NULL;
    const char* book4[] = {"Harry Potter and the Goblet of Fire", "18$", "636", "Ukrainian", "1000", "2000"};
    pushStringsArray(&list4, book4, numberOfInformation);

    struct StringNode* list5 = NULL;
    const char* book5[] = {"Harry Potter and the Order of the Phoenix", "20$", "766", "Ukrainian", "1100", "2003"};
    pushStringsArray(&list5, book5, numberOfInformation);

    struct StringNode* list6 = NULL;
    const char* book6[] = {"Harry Potter and the Half-Blood Prince", "20$", "607", "Ukrainian", "950", "2005"};
    pushStringsArray(&list6, book6, numberOfInformation);

    struct StringNode* list7 = NULL;
    const char* book7[] = {"Harry Potter and the Deathly Hallows", "22$", "759", "Ukrainian", "1200", "2007"};
    pushStringsArray(&list7, book7, numberOfInformation);

    struct ListNode* bigList = NULL;
    struct StringNode* lists[] = {list1, list2, list3, list4, list5, list6, list7};
    pushListsArray(&bigList, lists, numberOfBooks); 

    printListOfLists(bigList);
    return 0;
}


