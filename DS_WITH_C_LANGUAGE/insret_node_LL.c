#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the k-th position
void insertAtKthPosition(struct Node** head, int data, int k) {
    struct Node* newNode = createNode(data);
    
    // If inserting at the head (position 0)
    if (k == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    int count = 0;

    // Traverse the list to find the (k-1)-th position
    while (current != NULL && count < k - 1) {
        current = current->next;
        count++;
    }

    // If current is NULL, k is out of bounds
    if (current == NULL) {
        printf("Position %d is out of bounds.\n", k);
        free(newNode); // Free allocated memory for new node
        return;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the insertion
int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertAtKthPosition(&head, 10, 0); // Insert 10 at position 0
    insertAtKthPosition(&head, 20, 1); // Insert 20 at position 1
    insertAtKthPosition(&head, 30, 2); // Insert 30 at position 2

    printf("Linked List after insertions:\n");
    printList(head);

    // Inserting a new node at position 1
    insertAtKthPosition(&head, 15, 1);
    printf("Linked List after inserting 15 at position 1:\n");
    printList(head);

    // Attempt to insert at an out-of-bounds position
    insertAtKthPosition(&head, 25, 10); // Position 10 is out of bounds

    return 0;
}
