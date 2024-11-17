/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from list1 and list2.

Example 1:



Input: list1 = [1,2,4], list2 = [1,3,5]

Output: [1,1,2,3,4,5]
Example 2:

Input: list1 = [], list2 = [1,2]

Output: [1,2]
Example 3:

Input: list1 = [], list2 = []

Output: []
Constraints:

0 <= The length of the each list <= 100.
-100 <= Node.val <= 100

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

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to act as the start of the merged list
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append remaining nodes from either list
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create a linked list from user input
struct Node* createList() {
    int n, val;
    struct Node *head = NULL, *temp = NULL;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter the elements in sorted order:\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (head == NULL) {
                head = newNode;
                temp = head;
            } else {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }
    return head;
}

// Main function
int main() {
    struct Node *list1, *list2, *mergedList;

    printf("Create first sorted list:\n");
    list1 = createList();

    printf("Create second sorted list:\n");
    list2 = createList();

    mergedList = mergeLists(list1, list2);

    printf("Merged sorted list: ");
    printList(mergedList);

    return 0;
}
