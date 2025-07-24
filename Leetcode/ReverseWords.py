def reverseWords(s: str) -> str:
    words = s.split()

    reversed_words = words[::-1]

    return ' '.join(reversed_words)

print(reverseWords("My name is Selta"))