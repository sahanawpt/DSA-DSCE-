#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
        printf("Queue is Full! (Overflow)\n");
    } else {
        if (front == -1) // First element
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to delete element
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty! (Underflow)\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

// Function to display elements
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    printf("---- Circular Queue Operations ----\n");
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