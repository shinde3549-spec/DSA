#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    printf("Enqueued: %d\n", value);
}
void dequeue(Queue* q) {
     Node* temp = q->front;
	if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
   
    printf("Dequeued: %d\n", temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}
void displayQueue(Queue* q) {
    Node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    return 0;
}

