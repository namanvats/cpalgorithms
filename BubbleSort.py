a = [16, 19, 11, 15, 10, 12, 14]

for j in range(len(a)):
    swapped = False
    i = 0
    while i<len(a)-1:
        if a[i]>a[i+1]:
            a[i],a[i+1] = a[i+1],a[i]
            swapped = True
        i = i+1
    if swapped == False:
        break
print (a)