#Linear Search in Python 

#List of Numbers
arr=[1,2,3,4,5]

#Number to be Searched
num=int(input("Enter the Element to be Searched:"))

#Linear Search Implementation
n=len(arr)
index=-1
for i in range(n):
    if num==arr[i]:
        index=i        
        break
if index!=-1:
    print("Element at index {}".format(index))
else:
    print("Element Not present")
