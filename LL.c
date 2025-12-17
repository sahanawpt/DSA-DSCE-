#include <stdio.h>
#define SIZE 5 // Maximum size of queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is Full! (Overflow)\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to delete element
void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty! (Underflow)\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

// Function to display queue elements
void display() {
    if (front == -1 || front > rear)
        printf("Queue is Empty!\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    printf("---- Linear Queue Operations ----\n");
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}