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
        printf("Overflow: Circular queue is full. Unable to insert %d.\n", value);
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

// Function to delete an element from the circular queue
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Underflow: Circular queue is empty. Unable to delete.\n");
        return -1; // Indicate that deletion was unsuccessful
    }

    int value = q->items[q->front]; // Get the value to be deleted

    // If the queue has only one element, reset the queue
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        // Update the front index circularly
        q->front = (q->front + 1) % MAX;
    }

    printf("%d has been deleted from the circular queue.\n", value);
    return value; // Return the deleted value
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

    // Demonstrate overflow
    printf("Demonstrating Overflow:\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    // This should cause an overflow
    enqueue(q, 60);

    // Display the queue
    display(q);

    // Demonstrate underflow
    printf("\nDemonstrating Underflow:\n");
    dequeue(q); // Should remove 10
    dequeue(q); // Should remove 20
    dequeue(q); // Should remove 30
    dequeue(q); // Should remove 40
    dequeue(q); // Should remove 50
    // This should cause an underflow
    dequeue(q);

    // Attempt to delete from an empty queue
    dequeue(q);

    return 0;
}