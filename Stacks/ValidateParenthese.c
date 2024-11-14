/*
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true
Example 3:

Input: s = "[(])"

Output: false
Explanation: The brackets are not closed in the correct order.

Constraints:

1 <= s.length <= 1000
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char ch) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = ch;
    }
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return '\0';
}

char peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];
    }
    return '\0';
}

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

bool isClosingBracket(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValid(char *s) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(s); i++) {
        if (isOpeningBracket(s[i])) {
            push(&stack, s[i]);
        } else if (isClosingBracket(s[i])) {
            if (isEmpty(&stack) || !isMatchingPair(peek(&stack), s[i])) {
                return false;
            }
            pop(&stack);
        }        
    }
    return isEmpty(&stack);
}

int main() {
    char s[MAX];

    printf("Enter a string of brackets: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
