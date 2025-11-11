#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char text[100];
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(char* line);
void insertEnd(char* line);
void insertAtPos(char* line, int pos);
void deleteFront();
void deleteEnd();
void deleteAtPos(int pos);
void display();
void reverseList();
int getLength();

int getLength() {
    int count = 0;
    struct Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertFront(char* line) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->text, line);
    newNode->next = head;
    head = newNode;
}

void insertEnd(char* line) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->text, line);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertAtPos(char* line, int pos) {
    int len = getLength(),i; 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node* temp = head;
	
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position! Valid range: 1 to %d\n", len + 1);
        return;
    }

  
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->text, line);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront() {
	struct Node* temp = head;
    if (head == NULL) {
        printf("List Underflow!\n");
        return;
    }
    
    head = head->next;
    free(temp);
}

void deleteEnd() {
	struct Node* temp = head;
    if (head == NULL) {
        printf("List Underflow!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPos(int pos) {
    int len = getLength(),i;
	struct Node* temp = head;
	struct Node* delNode = temp->next;
    if (pos < 1 || pos > len) {
        printf("Invalid position! Valid range: 1 to %d\n", len);
        return;
    }

    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

   
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    temp->next = delNode->next;
    free(delNode);
}

void display() {
	struct Node* temp = head;
    int lineNum = 1;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d: %s\n", lineNum++, temp->text);
        temp = temp->next;
    }
}


   void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully.\n");
    display();
}


int main() {
    int choice, pos,choice1,choice2,choice3,i;
    char line[100];

    while (1) {
        printf("\n--- Text Editor using Singly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
				 	printf("1. Insert at Front\n");
			        printf("2. Insert at End\n");
			        printf("3. Insert at Position\n");
					printf("Enter your choice: ");
        			scanf("%d", &choice1);
					getchar();
			switch (choice1) {
            case 1:	   
                printf("Enter text: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                insertFront(line);
                break;
            case 2:
                printf("Enter text: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                insertEnd(line);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                getchar();
                printf("Enter text: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = 0;
                insertAtPos(line, pos);
                break;
			 default:
                printf("Invalid choice!\n");
				
			}
			break;
            case 2:
				 printf("1. Delete from Front\n");
			     printf("2. Delete from End\n");
			     printf("3. Delete from Position\n");
				 printf("Enter your choice: ");
        	 	 scanf("%d", &choice2);
				 getchar();
			switch (choice2) {	    
			case 1:
                deleteFront();
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
		   default:
                printf("Invalid choice!\n");	   
			}
			break;
			case 3:
				printf("1. Display (Normal)\n");
       		    printf("2. Reverse Entire List\n");	  
				printf("Enter your choice: ");
        	 	 scanf("%d", &choice3);
				 getchar();
			switch (choice3) {	    	   
			
            case 1:
                display();
                break;
        
            case 2:
                reverseList();
                break;
		    default:
                printf("Invalid choice!\n");
				}
			break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

