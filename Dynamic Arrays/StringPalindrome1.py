def strPalindrome(str):
    left, right = 0, len(str) - 1

    if left < right:
        if str[left] != str[right]:
            return False
        left += 1
        right -= 1

    return True

print(strPalindrome("str"))