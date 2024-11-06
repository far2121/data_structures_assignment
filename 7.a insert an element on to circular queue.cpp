#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5 // Maximum size of the circular queue

typedef struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to create and initialize a circular queue
CircularQueue* createQueue() {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the circular queue is full
bool isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Function to check if the circular queue is empty
bool isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Function to insert an element into the circular queue
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Circular queue is full. Unable to insert %d.\n", value);
        return;
    }

    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if queue was empty
    }

    // Update the rear index circularly
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value; // Insert the new element
    printf("%d has been inserted into the circular queue.\n", value);
}

// Function to display the elements of the circular queue
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = q->front;
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX; // Move circularly
    }
    printf("\n");
}

int main() {
    CircularQueue* q = createQueue();

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Attempt to enqueue into a full queue
    enqueue(q, 60);

    // Display the queue
    display(q);

    return 0;
}