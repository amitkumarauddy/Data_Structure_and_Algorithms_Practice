/*
Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list.

Example 1:

Input: head = [0,1,2,3]

Output: [3,2,1,0]
Example 2:

Input: head = []

Output: []
Constraints:

0 <= The length of the list <= 1000.
-1000 <= Node.val <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
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

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev to the current node
        current = next;        // Move to the next node
    }
    return prev;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int n, val;
    struct Node *head = NULL, *temp = NULL, *newNode;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter the elements of the list:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            newNode = createNode(val);
            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
