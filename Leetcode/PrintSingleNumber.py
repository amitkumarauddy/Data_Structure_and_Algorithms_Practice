def singleNumber(nums):
    res = 0
    for i in nums:
        res ^= i
    return res

print(singleNumber([2,2,5,6,7,6,7]))