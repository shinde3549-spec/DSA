#include <stdio.h>
#include <stdlib.h>
     
#define MAX 100


typedef struct {
    int data[MAX];
    int top;
} Stack;


typedef struct {
    int data[MAX];
    int front, rear;
} Queue;


void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int val) {
    if (!isStackFull(s)) {
        s->data[++s->top] = val;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *s) {
    if (!isStackEmpty(s)) {
        return s->data[s->top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int val) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q)) q->front = 0;
        q->data[++q->rear] = val;
    } else {
        printf("Queue Overflow\n");
    }
}

int dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        int val = q->data[q->front++];
        if (q->front > q->rear) initQueue(q);
        return val;
    } else {
        printf("Queue Underflow\n");
        return -1;
    }
}

int main() {
    Stack inputStack, outputStack;
    Queue inputQueue, outputQueue;
    int choice, val;

    initStack(&inputStack);
    initStack(&outputStack);
    initQueue(&inputQueue);
    initQueue(&outputQueue);

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Delete\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter integer to insert: ");
            scanf("%d", &val);
            push(&inputStack, val);
            enqueue(&inputQueue, val);
        } else if (choice == 2) {
            if (!isStackEmpty(&inputStack)) {
                int popped = pop(&inputStack);
                enqueue(&outputQueue, popped);
            } else {
                printf("Input Stack is empty.\n");
            }

            if (!isQueueEmpty(&inputQueue)) {
                int dequeued = dequeue(&inputQueue);
                push(&outputStack, dequeued);
            } else {
                printf("Input Queue is empty.\n");
            }

            if (isStackEmpty(&inputStack) && isQueueEmpty(&inputQueue)) {
                printf("\nProcessing complete.\n");
			
                printf("Output Stack: ");
                while (!isStackEmpty(&outputStack)) {
                    printf("%d ", pop(&outputStack));
                }
                printf("\n");

                printf("Output Queue: ");
                while (!isQueueEmpty(&outputQueue)) {
                    printf("%d ", dequeue(&outputQueue));
                }
                printf("\n");

                break;
            }
        } else if (choice == 3) {

            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

