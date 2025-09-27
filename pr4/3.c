#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Task variant №10 */

char* inputString(const char* prompt);
int isDigit(const char c);
int countDigit(const char* string);

int main(void) {
    char* string = inputString("Enter your string:\n");
    int count = countDigit(string);
    printf("Number of digits: %d\n", count);
    
    free(string);

    return 0;
}

char* inputString(const char* prompt) {
    char buffer[1024];
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    char* result = malloc(strlen(buffer) + 1);

    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    
    strcpy(result, buffer);

    return result;
}

int isDigit(const char c) {
    return c >= '0' && c <= '9';
}

int countDigit(const char* string) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isDigit(string[i])) {
            count++;
        }
    }
    
    return count;
}
