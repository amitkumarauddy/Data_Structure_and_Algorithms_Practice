/*
Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000
*/

#include<stdio.h>

void concatArray(int* nums, int n, int* ans){
    for(int i = 0; i < n; i++){
        ans[i] = nums[i];
        ans[n+i] = nums[i];
    }
}

int main(){
    int n,nums[1000],ans[2000],i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter Elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    concatArray(nums,n,ans);

    printf("Concatenated Elements are:\n");
    for(i = 0; i < 2 * n; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}