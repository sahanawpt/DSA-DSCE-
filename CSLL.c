#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Insert at beginning
struct node* insert_begin(struct node *start, int data) {
    struct node *temp, *curr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (start == NULL) {
        temp->next = temp;
        start = temp;
        return start;
    }

    curr = start;
    while (curr->next != start)
        curr = curr->next;

    temp->next = start;
    curr->next = temp;
    start = temp;

    return start;
}

// Insert at end
struct node* insert_end(struct node *start, int data) {
    struct node *temp, *curr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;

    if (start == NULL) {
        temp->next = temp;
        start = temp;
        return start;
    }

    curr = start;
    while (curr->next != start)
        curr = curr->next;

    curr->next = temp;
    temp->next = start;

    return start;
}

// Delete a node
struct node* delete_node(struct node *start, int key) {
    struct node *curr = start, *prev = NULL;

    if (start == NULL)
        return start;

    // Single node case
    if (start->data == key && start->next == start) {
        free(start);
        return NULL;
    }

    // If first node is to be deleted
    if (start->data == key) {
        curr = start;
        while (curr->next != start)
            curr = curr->next;

        curr->next = start->next;
        free(start);
        start = curr->next;
        return start;
    }

    prev = start;
    curr = start->next;

    while (curr != start && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == start) {
        printf("Element not found\n");
        return start;
    }

    prev->next = curr->next;
    free(curr);
    return start;
}

// Display the list
void display(struct node *start) {
    struct node *curr = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d ", curr->data);
        curr = curr->next;
    } while (curr != start);
    printf("\n");
}

// Main function
int main() {
    struct node *start = NULL;
    int choice, value;

    printf("---- Circular Singly Linked List ----\n");
    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                start = insert_begin(start, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");gcc
                scanf("%d", &value);
                start = insert_end(start, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                start = delete_node(start, value);
                break;
            case 4:
                display(start);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}