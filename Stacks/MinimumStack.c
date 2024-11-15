/*
Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in O(1) time.

Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1
Constraints:

-2^31 <= val <= 2^31 - 1.
pop, top and getMin will always be called on non-empty stacks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int val) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = val;
    }
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return INT_MIN; // Return a sentinel value for empty stack
}

int top(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return INT_MIN; // Return a sentinel value for empty stack
}

typedef struct {
    Stack stack;
    Stack minStack;
} MinStack;

MinStack* createMinStack() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    initStack(&minStack->stack);
    initStack(&minStack->minStack);
    return minStack;
}

void minStackPush(MinStack* obj, int val) {
    push(&obj->stack, val);
    if (isEmpty(&obj->minStack) || val <= top(&obj->minStack)) {
        push(&obj->minStack, val);
    }
}

void minStackPop(MinStack* obj) {
    if (top(&obj->stack) == top(&obj->minStack)) {
        pop(&obj->minStack);
    }
    pop(&obj->stack);
}

int minStackTop(MinStack* obj) {
    return top(&obj->stack);
}

int minStackGetMin(MinStack* obj) {
    return top(&obj->minStack);
}

int main() {
    MinStack* minStack = createMinStack();
    
    minStackPush(minStack, 1);
    minStackPush(minStack, 2);
    minStackPush(minStack, 0);
    printf("getMin: %d\n", minStackGetMin(minStack)); // Output: 0
    minStackPop(minStack);
    printf("top: %d\n", minStackTop(minStack)); // Output: 2
    printf("getMin: %d\n", minStackGetMin(minStack)); // Output: 1

    return 0;
}
