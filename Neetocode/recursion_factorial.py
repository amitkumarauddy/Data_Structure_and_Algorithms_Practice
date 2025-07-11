def factorial(n):
    if(n <= 1):
      return 1
    
    return n * factorial(n-1)



number = 4
result = factorial(number)
print("factorial : "+ str(result))

#Time Complexity is O(n)