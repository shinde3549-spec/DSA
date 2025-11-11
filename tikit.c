#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONFIRMED 2
#define MAX_WAITING 5
#define NAME_LEN 50
struct Passenger {
 char name[NAME_LEN];
};
struct Queue {
 struct Passenger data[MAX_WAITING];
 int front;
 int rear;
 int size;
};
void initQueue(struct Queue *q) {
 q->front = 0;
 q->rear = -1;
 q->size = 0;
}
int isFull(struct Queue *q, int maxSize) {
 return q->size == maxSize;
}
int isEmpty(struct Queue *q) {
 return q->size == 0;
}
void enqueue(struct Queue *q, struct Passenger p, int maxSize) {
 if (isFull(q, maxSize)) {
 printf("Queue is full. Cannot add %s\n", p.name);
 return;
 }
 q->rear = (q->rear + 1) % maxSize;
 q->data[q->rear] = p;
 q->size++;
}
struct Passenger dequeue(struct Queue *q, int maxSize) {
 struct Passenger temp;
 strcpy(temp.name, ""); 
 if (isEmpty(q)) {
 printf("Queue is empty.\n");
 return temp;
 }
 temp = q->data[q->front];
 q->front = (q->front + 1) % maxSize;
 q->size--;
 return temp;
}
void displayQueue(struct Queue *q, int maxSize, const char *label) {
 int i, index;
 printf("%s:\n", label);
 if (isEmpty(q)) {
 printf(" [Empty]\n");
 return;
 }
 for (i = 0; i < q->size; i++) {
 index = (q->front + i) % maxSize;
 printf(" %d. %s\n", i + 1, q->data[index].name);
 }
}
int main() {
struct Queue confirmed, waiting;
struct Passenger p;
int choice, i;
char name[NAME_LEN];
initQueue(&confirmed);
initQueue(&waiting);
while (1) {
printf("\n--- Train Ticket Booking System ---\n");
printf("1. Book Ticket\n");
printf("2. Cancel Ticket\n");
printf("3. View Confirmed List\n");
printf("4. View Waiting List\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar();
if (choice == 1) {
printf("Enter passenger name: ");
fgets(name, NAME_LEN, stdin);
name[strcspn(name, "\n")] = '\0';
strcpy(p.name, name);
if (!isFull(&confirmed, MAX_CONFIRMED)) {
enqueue(&confirmed, p, MAX_CONFIRMED);
printf("Booking confirmed for %s.\n", p.name);
} else if (!isFull(&waiting, MAX_WAITING)) {
enqueue(&waiting, p, MAX_WAITING);
printf("Added to waiting list: %s.\n", p.name);
} else {
printf("Sorry, no seats available and waiting list is full.\n");
}
} else if (choice == 2) {
if (!isEmpty(&confirmed)) {
p = dequeue(&confirmed, MAX_CONFIRMED);
printf("Cancelled booking for %s.\n", p.name);
if (!isEmpty(&waiting)) {
p = dequeue(&waiting, MAX_WAITING);
enqueue(&confirmed, p, MAX_CONFIRMED);
printf("Moved %s from waiting list to confirmed.\n", p.name);
}
} else {
printf("No confirmed bookings to cancel.\n");
}
} else if (choice == 3) {
displayQueue(&confirmed, MAX_CONFIRMED, "Confirmed Bookings");
} else if (choice == 4) {
displayQueue(&waiting, MAX_WAITING, "Waiting List");
} else if (choice == 5) {
break;
} else {
printf("Invalid choice. Try again.\n");
}
}
return 0;
} 

