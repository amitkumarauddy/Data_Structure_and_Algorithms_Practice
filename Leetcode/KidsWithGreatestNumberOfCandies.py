def kidsWithCandies(kids_candies, extra_candies):
    max_candies = max(kids_candies)

    result =[]

    for i in range(len(kids_candies)):
        if kids_candies[i] + extra_candies >= max_candies:
            result.append("True")
        else:
            result.append("False")
    return result

print(kidsWithCandies([12,1,12],10))
