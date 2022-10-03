
def linearSearch(array, x):
    if x in array:
        return array.index(x)
    return -1


print("Enter array:")
array = list(map(int, input().split()))
x=int(input())
result = linearSearch(array, x)
if(result == -1):
    print("Element not found")
else:
    print("Element found at index: ", result)
