def maxConsecutive(nums, k):
    left = 0
    zero_ctr = 0
    maxlen = 0

    for right in range(len(nums)):
        if nums[right] == 0:
            zero_ctr += 1

        while zero_ctr > k:
            if nums[left] == 0:
                zero_ctr -= 1
            left += 1

        maxlen = max(maxlen, right - left + 1)

    return maxlen

print(maxConsecutive([1,1,1,0,0,0,1,1,1,1,0],2))
