#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HistoryNode {
    char url[100];
    struct HistoryNode *next;
} HistoryNode;

HistoryNode *top = NULL;

void pushHistory(char *url) {
    HistoryNode *newNode;
    newNode = (HistoryNode *)malloc(sizeof(HistoryNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->url, url);
    newNode->next = top;
    top = newNode;
    printf("Visited: %s\n", url);
}

void popHistory() {
    HistoryNode *temp;
    if (top == NULL) {
        printf("No history to go back to.\n");
        return;
    }
    temp = top;
    printf("Going back from: %s\n", top->url);
    top = top->next;
    free(temp);
}

void displayHistory() {
    HistoryNode *current;
    if (top == NULL) {
        printf("Browser history is empty.\n");
        return;
    }
    printf("Current Browser History (Top to Bottom):\n");
    current = top;
    while (current != NULL) {
        printf("- %s\n", current->url);
        current = current->next;
    }
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser History System ---\n");
        printf("1. Visit New Page (PUSH)\n");
        printf("2. Go Back (POP)\n");
        printf("3. Show History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter URL: ");
            fgets(url, sizeof(url), stdin);
            url[strcspn(url, "\n")] = '\0';
            pushHistory(url);
        } else if (choice == 2) {
            popHistory();
        } else if (choice == 3) {
            displayHistory();
        } else if (choice == 4) {
            printf("Exiting browser history system.\n");
            exit(0);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

