//gcd or hcf
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
    //*************//*brute force
    int ans=0,a=5,b=10;
    for(int i=1;i<=min(a,b);i++)
{
    if(a%i == 0 && b%i == 0)
    ans=i;
}
cout<<ans;
/**************************/

	int a = 4, b = 8;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);
}

//*************************************************************
