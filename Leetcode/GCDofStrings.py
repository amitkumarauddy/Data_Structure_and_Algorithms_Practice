def GCDofStrings(str1, str2) ->str:
    if str1 + str2 != str2 + str1:
        return "no gcd"
    if len(str1) == len(str2):
        return str1
    if len(str1) > len(str2):
        return GCDofStrings(str1[len(str2):], str2)
    return GCDofStrings(str1, str2[len(str1):]) 

print(GCDofStrings("ABABAB","ABAB"))