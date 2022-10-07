def binary_Search(arr,ele,low,high):

    while(low<=high):
        mid=int(low+(high-low)/2)
        if(arr[mid]==ele):
            return mid
        elif arr[mid]>ele:
            high=mid-1
        else:
            low=mid+1
    return -1
if __name__=="__main__":
    arr=[1,2,3,4,5]
    ele=int(input("Enter the element to be Searched:"))
    arr.sort()
    a=binary_Search(arr,ele,0,len(arr)-1)
    if a==-1:
        print("Element Not Present")
    else:
        print("Element at index {}".format(a))

#Contributed by Aryan
