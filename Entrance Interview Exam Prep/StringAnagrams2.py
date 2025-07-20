from collections import Counter
def areAnagram(a, b):
    return Counter(a) == Counter(b)

print(areAnagram("EAT","TEA"))