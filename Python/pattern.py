ch = int(input("Enter choice 1/2/3 : "))
n = int(input("Enter no of rows : "))

if ch==1:
  for i in range(n):
    print("*" * (i+1))
elif ch==2:
  for i in range(n):
    print(" " * (n-i-1),end="")
    print("*" * (i+1))
elif ch==3:
  for i in range(0,n):
    print(" "*(n-i+1),end="")
    print("*"*(2*i+1))
else:
  print("Invalid choice")
