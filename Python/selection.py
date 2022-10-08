numbers = [12, 4, 43, 43, 21]

i = 0

while(i < len(numbers)-1):
    minIndex = i
    j = i + 1
    while(j<len(numbers)):
        if(numbers[minIndex] > numbers[j]):
            minIndex = j
        j=j+1
    if(minIndex != i):
        temp = numbers[minIndex]
        numbers[minIndex] = numbers[i]
        numbers[i] = temp
    i=i+1
for i in numbers:
        print(i)

    

