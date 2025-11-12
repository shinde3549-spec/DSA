#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    int severity; 
} Patient;

Patient queue[MAX];
int size = 0;

void insertPatient(Patient p) {
	int i;
    if (size == MAX) {
        printf("Queue is full!\n");
        return;
    }

    i = size - 1;
    while (i >= 0 && queue[i].severity < p.severity) {
        queue[i + 1] = queue[i];
        i--;
    }
    queue[i + 1] = p;
    size++;
}

void displayQueue() {
	int i;
    if (size == 0) {
        printf("No patients in queue.\n");
        return;
    }

    printf("\n--- Emergency Queue ---\n");
    for (i = 0; i < size; i++) {
        printf("Name: %s | Age: %d | Severity: %d\n", queue[i].name, queue[i].age, queue[i].severity);
    }
}

void treatPatient() {
	int i;
    if (size == 0) {
        printf("No patients to treat.\n");
        return;
    }

    printf("\nTreating patient: %s (Severity: %d)\n", queue[0].name, queue[0].severity);
    for ( i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
    }
    size--;
}

int main() {
    int choice;
    Patient p;

    while (1) {
        printf("\n1. Add Patient\n2. Display Queue\n3. Treat Patient\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = '\0';
                printf("Enter age: ");
                scanf("%d", &p.age);
                printf("Enter severity (1-10): ");
                scanf("%d", &p.severity);
                insertPatient(p);
                break;
            case 2:
                displayQueue();
                break;
            case 3:
                treatPatient();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

