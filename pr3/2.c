#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string_node {
    char *str;
    struct string_node *next;
};

struct list_node {
    struct string_node *sublist;
    struct list_node *next;
};

struct string_node* create_string_node(const char *text) {
    struct string_node *new_node = malloc(sizeof(*new_node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->str = malloc(strlen(text) + 1);
    if (!new_node->str) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->str, text);

    new_node->next = NULL;
    return new_node;
}

void push_string_back(struct string_node **head, const char *text) {
    struct string_node *new_node = create_string_node(text);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct string_node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void push_strings_array(struct string_node **head, const char *arr[], int size) {
    for (int i = 0; i < size; i++) {
        push_string_back(head, arr[i]);
    }
}

void free_string_list(struct string_node *head) {
    while (head) {
        struct string_node *next = head->next;
        free(head->str);
        free(head);
        head = next;
    }
}

struct list_node* create_list_node(struct string_node *sublist) {
    struct list_node *new_node = malloc(sizeof(*new_node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->sublist = sublist;
    new_node->next = NULL;
    return new_node;
}

void push_list_back(struct list_node **head, struct string_node *sublist) {
    struct list_node *new_node = create_list_node(sublist);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct list_node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void push_lists_array(struct list_node **head, struct string_node *sublists[], int size) {
    for (int i = 0; i < size; i++) {
        push_list_back(head, sublists[i]);
    }
}

void free_list_of_lists(struct list_node *head) {
    while (head) {
        struct list_node *next = head->next;
        free_string_list(head->sublist);
        free(head);
        head = next;
    }
}

void print_book(const struct list_node *head, int number_of_book) {
    const char *book_info[] = {
        "Name of book: ",
        "Price: ",
        "Number of pages: ",
        "Language: ",
        "Weight: ",
        "Year: "
    };

    int n = sizeof(book_info) / sizeof(book_info[0]);

    const struct list_node *temp = head;
    for (int i = 1; i < number_of_book; i++) {
        if (temp == NULL) {
            printf("Error: no such book\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: no such book\n");
        return;
    }

    const struct string_node *sub = temp->sublist;
    printf("\n");
    for (int j = 0; j < n && sub != NULL; j++) {
        printf("%s%s\n", book_info[j], sub->str);
        sub = sub->next;
    }
}

int input_number_of_book(const char *prompt, int number_of_books) {
    int number;
    while (1) {
        printf("%s\n", prompt);
        if (scanf("%d", &number) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (number >= 1 && number <= number_of_books) {
            return number;
        }
        printf("Error: this book isn’t real\n");
    }
}

int main(void) {
    const int number_of_information = 6;
    const int number_of_books = 7;

    struct string_node *lists[number_of_books];
    memset(lists, 0, sizeof(lists));

    const char *book1[] = {"Harry Potter and the Philosopher`s Stone", "10$", "223", "Ukrainian", "500", "1997"};
    const char *book2[] = {"Harry Potter and the Chamber of Secrets", "12$", "251", "Ukrainian", "550", "1998"};
    const char *book3[] = {"Harry Potter and the Prisoner of Azkaban", "15$", "317", "Ukrainian", "600", "1999"};
    const char *book4[] = {"Harry Potter and the Goblet of Fire", "18$", "636", "Ukrainian", "1000", "2000"};
    const char *book5[] = {"Harry Potter and the Order of the Phoenix", "20$", "766", "Ukrainian", "1100", "2003"};
    const char *book6[] = {"Harry Potter and the Half-Blood Prince", "20$", "607", "Ukrainian", "950", "2005"};
    const char *book7[] = {"Harry Potter and the Deathly Hallows", "22$", "759", "Ukrainian", "1200", "2007"};

    push_strings_array(&lists[0], book1, number_of_information);
    push_strings_array(&lists[1], book2, number_of_information);
    push_strings_array(&lists[2], book3, number_of_information);
    push_strings_array(&lists[3], book4, number_of_information);
    push_strings_array(&lists[4], book5, number_of_information);
    push_strings_array(&lists[5], book6, number_of_information);
    push_strings_array(&lists[6], book7, number_of_information);

    struct list_node *big_list = NULL;
    push_lists_array(&big_list, lists, number_of_books);

    int number = input_number_of_book("Enter number of book about Harry Potter:", number_of_books);
    print_book(big_list, number);

    free_list_of_lists(big_list);
    return 0;
}
