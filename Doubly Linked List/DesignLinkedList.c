/*
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
*/



/*

//USING SINGLY LINKED LIST



#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the linked list
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Definition of MyLinkedList
typedef struct {
    Node* head; // Pointer to the head node
    int size;   // Size of the linked list
} MyLinkedList;

// Function to initialize a new linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Function to get the value at the specified index
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1; // Invalid index
    }
    Node* curr = obj->head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }
    return curr->val;
}

// Function to add a node at the head of the linked list
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

// Function to add a node at the tail of the linked list
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) { // If the list is empty
        obj->head = newNode;
    } else {
        Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    obj->size++;
}

// Function to add a node at a specific index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;

        Node* curr = obj->head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        obj->size++;
    }
}

// Function to delete a node at a specific index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) { // Deleting the head
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
    obj->size--;
}

// Function to free the memory used by the linked list
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

// Function to print the linked list
void myLinkedListPrint(MyLinkedList* obj) {
    if (obj->head == NULL) { // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }
    Node* curr = obj->head;
    while (curr != NULL) {
        printf("%d -> ", curr->val); // Print the value of the current node
        curr = curr->next;           // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}


// Main function with user interaction
int main() {
    MyLinkedList* myLinkedList = myLinkedListCreate();
    int choice, value, index;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Add at Head\n");
        printf("2. Add at Tail\n");
        printf("3. Add at Index\n");
        printf("4. Get Value at Index\n");
        printf("5. Delete at Index\n");
        printf("6. Print Linked List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at head: ");
                scanf("%d", &value);
                myLinkedListAddAtHead(myLinkedList, value);
                break;

            case 2:
                printf("Enter value to add at tail: ");
                scanf("%d", &value);
                myLinkedListAddAtTail(myLinkedList, value);
                break;

            case 3:
                printf("Enter index and value to add: ");
                scanf("%d %d", &index, &value);
                myLinkedListAddAtIndex(myLinkedList, index, value);
                break;

            case 4:
                printf("Enter index to get value: ");
                scanf("%d", &index);
                value = myLinkedListGet(myLinkedList, index);
                if (value == -1) {
                    printf("Invalid index.\n");
                } else {
                    printf("Value at index %d: %d\n", index, value);
                }
                break;

            case 5:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                myLinkedListDeleteAtIndex(myLinkedList, index);
                break;

            case 6:
                printf("Linked List: ");
                myLinkedListPrint(myLinkedList);
                break;

            case 7:
                myLinkedListFree(myLinkedList);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
*/ 

//USING DOUBLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the doubly linked list
typedef struct Node {
    int val;
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
} Node;

// Definition of MyLinkedList
typedef struct {
    Node* head; // Pointer to the head node
    Node* tail; // Pointer to the tail node (optional for easier operations)
    int size;   // Size of the linked list
} MyLinkedList;

// Function to initialize a new doubly linked list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;
    return obj;
}

// Function to get the value at the specified index
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        return -1; // Invalid index
    }
    Node* curr;
    // Optimize by choosing direction of traversal
    if (index < obj->size / 2) {
        curr = obj->head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
    } else {
        curr = obj->tail;
        for (int i = obj->size - 1; i > index; --i) {
            curr = curr->prev;
        }
    }
    return curr->val;
}

// Function to add a node at the head of the doubly linked list
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    newNode->prev = NULL;

    if (obj->head != NULL) {
        obj->head->prev = newNode;
    } else { // If the list was empty, set the tail
        obj->tail = newNode;
    }
    obj->head = newNode;
    obj->size++;
}

// Function to add a node at the tail of the doubly linked list
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = obj->tail;

    if (obj->tail != NULL) {
        obj->tail->next = newNode;
    } else { // If the list was empty, set the head
        obj->head = newNode;
    }
    obj->tail = newNode;
    obj->size++;
}

// Function to add a node at a specific index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) {
        printf("Invalid index.\n");
        return;
    }
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
    } else if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = val;
        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;
        obj->size++;
    }
}

// Function to delete a node at a specific index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) {
        printf("Invalid index.\n");
        return;
    }
    Node* toDelete;

    if (index == 0) { // Deleting the head
        toDelete = obj->head;
        obj->head = obj->head->next;
        if (obj->head != NULL) {
            obj->head->prev = NULL;
        } else {
            obj->tail = NULL; // The list is now empty
        }
    } else if (index == obj->size - 1) { // Deleting the tail
        toDelete = obj->tail;
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
    } else {
        toDelete = obj->head;
        for (int i = 0; i < index; ++i) {
            toDelete = toDelete->next;
        }
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
    }

    free(toDelete);
    obj->size--;
}

// Function to free the memory used by the doubly linked list
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

// Function to print the doubly linked list
void myLinkedListPrint(MyLinkedList* obj) {
    if (obj->head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* curr = obj->head;
    while (curr != NULL) {
        printf("%d <-> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    MyLinkedList* myLinkedList = myLinkedListCreate();
    int choice, value, index;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Add at Head\n");
        printf("2. Add at Tail\n");
        printf("3. Add at Index\n");
        printf("4. Get Value at Index\n");
        printf("5. Delete at Index\n");
        printf("6. Print Linked List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at head: ");
                scanf("%d", &value);
                myLinkedListAddAtHead(myLinkedList, value);
                break;

            case 2:
                printf("Enter value to add at tail: ");
                scanf("%d", &value);
                myLinkedListAddAtTail(myLinkedList, value);
                break;

            case 3:
                printf("Enter index and value to add: ");
                scanf("%d %d", &index, &value);
                myLinkedListAddAtIndex(myLinkedList, index, value);
                break;

            case 4:
                printf("Enter index to get value: ");
                scanf("%d", &index);
                value = myLinkedListGet(myLinkedList, index);
                if (value == -1) {
                    printf("Invalid index.\n");
                } else {
                    printf("Value at index %d: %d\n", index, value);
                }
                break;

            case 5:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                myLinkedListDeleteAtIndex(myLinkedList, index);
                break;

            case 6:
                printf("Linked List: ");
                myLinkedListPrint(myLinkedList);
                break;

            case 7:
                myLinkedListFree(myLinkedList);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
