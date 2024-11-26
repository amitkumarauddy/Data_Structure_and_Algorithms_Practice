#include<stdio.h>

int main() {
    int numElements, firstTerm = 0, secondTerm = 1, nextTerm, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &numElements);
    
    printf("Fibonacci Series: %d %d ", firstTerm, secondTerm);
    
    for (i = 3; i <= numElements; i++) {
        nextTerm = firstTerm + secondTerm;
        printf("%d ", nextTerm);
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
    return 0;
}
