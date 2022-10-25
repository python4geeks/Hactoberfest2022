from math import *

print("ax^2 + bx + c = 0")

while True:
    try:
        a = int(input("Enter Value Of a: "))
        b = int(input("Enter Value of b: "))
        c = int(input("Enter Value of c: "))
        break
    except:
        print("INVALID INPUT...(Please Enter Only Integers)")

d = (b ** 2) - (4 * a * c)

if (d) > 0:
    root1 = (-b+sqrt(d)) / (2*a)
    root2 = (-b-sqrt(d)) / (2*a)
    print(f"\nTwo Distinct Real Roots Exists:\nFirst Root = {root1}\nSecond Root = {root2}\n")
elif (d) < 0:
    print(f"\nNo Real Roots Exists\n")
elif (d) == 0:
    root1 = root2 = -b / (2 * a)
    print(f"\nTwo Equal and Real Roots Exists:\nRoot = {root1}\n")


# --------------------------------------------------------



# from math import *
# print("ax^2 + bx + c = 0")
# a = int(input("Enter Value Of a: "))
# b = int(input("Enter Value Of b: "))
# c = int(input("Enter Value Of c: "))

# # formula = -b +- underroot(b^2 - 4ac) / 2a

# final1 = (-b + sqrt((b*b) - (4*a*c))) / 2*a
# final2 = (-b - sqrt((b*b) - (4*a*c))) / 2*a

# print(f"Roots are {final1} and {final2}")
