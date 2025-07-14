def wordsAppend(word1: str, word2:str) -> str:
    merged = []
    i = 0
    len1, len2 = len(word1), len(word2)

    while i< len1 and i< len2:
        merged.append(word1[i])
        merged.append(word2[i])
        i += 1
    
    merged.append(word1[i:])
    merged.append(word2[i:])

    return ''.join(merged)

print(wordsAppend("Amit","Delta"))