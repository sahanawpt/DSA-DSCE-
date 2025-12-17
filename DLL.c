#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Insert at beginning
struct node* insert_begin(struct node *start, int data) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->prev = NULL;
    temp->next = start;

    if (start != NULL)
        start->prev = temp;

    start = temp;
    return start;
}

// Insert at end
struct node* insert_end(struct node *start, int data) {
    struct node *temp, *curr;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (start == NULL) {
        temp->prev = NULL;
        start = temp;
        return start;
    }

    curr = start;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;

    return start;
}

// Delete a node
struct node* delete_node(struct node *start, int key) {
    struct node *curr = start;

    if (curr != NULL && curr->data == key) {
        start = curr->next;
        if (start != NULL)
            start->prev = NULL;

        free(curr);
        return start;
    }

    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) {
        printf("Element not found\n");
        return start;
    }

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    free(curr);
    return start;
}

// Search element
int search(struct node *start, int key) {
    struct node *curr = start;
    while (curr != NULL) {
        if (curr->data == key)
            return 1;
        curr = curr->next;
    }
    return 0;
}

// Count nodes
int count_nodes(struct node *start) {
    int count = 0;
    struct node *curr = start;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Display list (forward)
void display(struct node *start) {
    struct node *curr = start;
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// -------- Main Program --------
int main() {
    struct node *start = NULL;

    start = insert_end(start, 10);
    start = insert_end(start, 20);
    start = insert_end(start, 30);
    start = insert_begin(start, 5);

    printf("Doubly Linked List:\n");
    display(start);

    printf("Search 20: %d\n", search(start, 20));
    printf("Total nodes: %d\n", count_nodes(start));

    start = delete_node(start, 20);
    printf("After deleting 20:\n");
    display(start);

    return 0;
}