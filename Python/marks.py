m1=int(input("enter marks of M1="))
pps=int(input("enter marks of PPS="))
bee=int(input("enter marks of BEE="))
erg=int(input("enter marks of ERG="))
phy=int(input("enter marks of PHY="))
if(m1<40 or pps<40 or bee<40 or erg<40 or phy<40):
    print("FAIL")
else:
    total=m1+pps+bee+erg+phy
    print("total=",total)
    average=total/5
    print("average=",average)

    if(average>=75):
        print("grade=distinction")
    elif(average>=60 and average<75):
        print("grade=first class")
    elif(average>=50 and average<60):
        print("grade=second class")
    elif(average>=40 and average<50):
        print("grade=third class")
    else:
        print("FAIL")
     
