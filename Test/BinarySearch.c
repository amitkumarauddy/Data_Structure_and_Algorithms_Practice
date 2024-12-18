#include<stdio.h>

int binarySearch(int array[], int size, int target){

    int low = 0;
    int high = size - 1;
    
    while(low <= high){
        int mid = (low + high)/2;

        if(array[mid] == target){
            return mid;
        }
        else if(array[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){

    int n,target;

    printf("Enter the size of array: ");
    scanf("%d",&n);

    int array[n];
    printf("Enter Array Elements in Ascending Order: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&array[i]);
    }

    printf("Enter target value to be searched: ");
    scanf("%d", &target);

    int result = binarySearch(array,n,target);

    if(result != -1){
        printf("Target Element %d found at %d\n", target, result+1);
    }
    else{
        printf("Target Element %d not found\n", target);
    }
    return 0;
}