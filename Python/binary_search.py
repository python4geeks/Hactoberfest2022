def binarySearch(array, x):
    array.sort()
    low, high = 0, len(array)-1
    while(low <= high):
        mid = (low+high)//2
        if(array[mid] == x):
            return mid-1
        elif(array[mid] > x):
            high = mid-1
        else:
            low = mid+1
    else:
        return -1


print("Enter array:")
array = list(map(int, input().split()))
x = int(input())
result = binarySearch(array, x)
if(result == -1):
    print("Element not found")
else:
    print("Element found at index: ", result)
