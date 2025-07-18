def differenceArrays(arr1, arr2):
    s1 = set(arr1)
    s2 = set(arr2)

    return list(s1 - s2), list(s2 - s1)

print(differenceArrays([1, 2, 3], [2, 4, 6]))  