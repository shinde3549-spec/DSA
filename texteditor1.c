#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Node {
    char line[MAX_LEN];
    struct Node *next;
} Node;

Node *head = NULL;

void insertLine(const char *text) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->line, text);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteLine(int pos) {
	int i;
    Node *temp = head;
	Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    if (head == NULL) {
        printf("Editor is empty.\n");
        return;
    }

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for ( i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid line number.\n");
        return;
    }

}

void displayNormal() {
    Node *temp = head;
    int lineNum = 1;
    printf("\n--- Text (Normal) ---\n");
    while (temp != NULL) {
        printf("%d: %s\n", lineNum, temp->line);
        temp = temp->next;
        lineNum++;
    }
}

void displayReverse(Node *node, int lineNum) {
    if (node == NULL) {
        return;
    }
    displayReverse(node->next, lineNum + 1);
    printf("%d: %s\n", lineNum, node->line);
}

void reverseList() {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed.\n");
}
void clearEditor() {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;
    char buffer[MAX_LEN];
    int lineNum;

    do {
        printf("\n--- Text Editor Menu ---\n");
        printf("1. Insert line\n");
        printf("2. Delete line\n");
        printf("3. Display (Normal)\n");
        printf("4. Display (Reverse)\n");
        printf("5. Reverse list\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                printf("Enter line: ");
                fgets(buffer, MAX_LEN, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                insertLine(buffer);
                break;
            }

            case 2: {
                printf("Enter line number to delete: ");
                scanf("%d", &lineNum);
                deleteLine(lineNum);
                break;
            }

            case 3: {
                displayNormal();
                break;
            }

            case 4: {
                printf("\n--- Text (Reverse) ---\n");
                displayReverse(head, 1);
                break;
            }

            case 5: {
                reverseList();
                break;
            }

            case 6: {
                clearEditor();
                printf("Exiting editor...\n");
                break;
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
