
def uniqueOccurrences(arr):
    arr.sort()
    unique_set = set()

    count = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[i - 1]:
            count += 1
        else:
            if count in unique_set:
                return False

            unique_set.add(count)
            count = 1

    if count in unique_set:
        return False

    return True

print(uniqueOccurrences([1,2,2,1,1,4]))