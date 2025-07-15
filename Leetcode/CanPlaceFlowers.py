def canPlaceFlowers(flowerbed, n):
    zeros = 1
    ans = 0

    for i in flowerbed:
        if i == 0:
            zeros += 1
        else:
            ans = ans + (zeros - 1) // 2
            zeros = 0
    return ans + zeros // 2 >= n

print(canPlaceFlowers([1,0,0,0,1],1))