def isSubsequence(str, t):
    i = 0
    for c in t:
        if i == len(str):
            return True
        if str[i] == c:
            i += 1
        
    return i == len(str)

print(isSubsequence("abc","ahbgdc"))