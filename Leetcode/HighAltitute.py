def highAltitude(gain):
    h_alt = 0
    sum = 0
    for i in range(len(gain)):
        sum += gain[i]
        h_alt = max(h_alt, sum)
    return h_alt

print(highAltitude([-5,1,5,0,-7]))