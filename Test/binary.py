def binarySearch(arr,target):
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = int((low + high)/2)

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

print(binarySearch([1,2,3,4,5,6,7,8],8)+1)
