#include <stdbool.h>
#include <stdio.h>

#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() { return (rear + 1) % SIZE == front; }

bool isEmpty() { return front == -1; }

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // indicating an error value
    } else {
        int value = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return value;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // indicating an error value
    } else {
        return queue[front];
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int n, data, c = 0;
    printf("Number of elements you want to enter in the queue: ");
    scanf("%d", &n);
    int i = n;
    while (n--) {
        printf("Enter data for position %d: ", c);
        scanf("%d", &data);
        enqueue(data);
        c++;
    }

    printf("Queue after data enqueued:\n");
    display();

    printf("Queue after data dequeued:\n");
    dequeue();
    display();

    int peekValue = peek();
    if (peekValue != -1) {
        printf("Data peeked: %d\n", peekValue);
    }

    return 0;
}


