def twoSum(arr, target):
    dict = {}

    for i, num in enumerate(arr):
        complement = target - num
        if complement in arr:
            return [arr[complement], i]
        arr[num] = i
