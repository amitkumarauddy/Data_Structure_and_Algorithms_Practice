def fibonacci(n):
    if(n == 0):
        return 0
    if(n ==1):
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

n = 10
print(f"The {n}th fibonacci number is: {fibonacci(n)}")