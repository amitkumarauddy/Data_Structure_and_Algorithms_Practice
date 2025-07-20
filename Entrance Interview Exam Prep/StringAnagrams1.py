def areAnagrams(a, b):
    return sorted(a) == sorted(b)

print(areAnagrams("TEA","EAT"))