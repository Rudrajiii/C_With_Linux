#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

// Define the structure for the queue
typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Enqueue (add) an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Update front for the first element
    }

    q->rear++;
    q->arr[q->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Dequeue (remove) an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate failure
    }

    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // If there was only one element, reset the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    printf("%d dequeued from the queue.\n", value);
    return value;
}

// Peek (get the front element) of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; // Return -1 to indicate failure
    }
    return q->arr[q->front];
}

// Display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Front element is %d\n", peek(&q));

    dequeue(&q);
    dequeue(&q);
    
    display(&q);

    dequeue(&q);
    dequeue(&q); // Attempt to dequeue from an empty queue

    return 0;
}
