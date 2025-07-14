def maxArea(H) -> int:
    start, last = 0, len(H)-1
    area = 0
    result = 0
    while(start < last):
        if H[start] <= H[last]:
            area = H[start] * (last - start)
            start+= 1
        elif H[start] >= H[last]:
            area = H[last] * (last - start)
            last-= 1
        
        if result < area:
            result = area

    return result

print(maxArea([1,8,6,2,5,4,8,3,7]))
