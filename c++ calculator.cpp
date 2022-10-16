#include <iostream>
#include <string>
using namespace std;

float add(float a){
    float sum=a;
    float b;
    string c;
    cout<<"Enter the next numbers to add : ";
    cin>>b;
    sum+=b;
    cout<<"want to add more (y/n) - ";
    cin>>c;
    if (c=="y" or c=="Y"){
        add(sum);
        return sum;
    }
    cout<<"Ans = "<<sum<<endl;
}
float sub(float a){
    float sum=a;
    float b;
    string c;
    cout<<"Enter the next numbers to subtract : ";
    cin>>b;
    sum-=b;
    cout<<"want to subtract more (y/n) - ";
    cin>>c;
    if (c=="y" or c=="Y"){
        sub(sum);
        return sum;
    }
    cout<<"Ans = "<<sum<<endl;
}
float multiply(float a){
    float sum=a;
    float b;
    string c;
    cout<<"Enter the next numbers to multiply : ";
    cin>>b;
    sum*=b;
    cout<<"want to multiply more (y/n) - ";
    cin>>c;
    if (c=="y" or c=="Y"){
        multiply(sum);
        return sum;
    }
    cout<<"Ans = "<<sum<<endl;
}
float divide(float a){
    float sum=a;
    float b;
    string c;
    cout<<"Enter the next numbers to divide : ";
    cin>>b;
    sum/=b;
    cout<<"want to divide more (y/n) - ";
    cin>>c;
    if (c=="y" or c=="Y"){
        divide(sum);
        return sum;
    }
    cout<<"Ans = "<<sum<<endl;
}
int main(){
    while (true){
        int option;
        cout<<"Select what operation you want to do -\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Quit\nEnter the number - ";
        cin>>option;
        if (option==1){
            float a;
            cout<<"Enter the first number : ";
            cin>>a;
            add(a);
        }
        else if (option==2){
            float a;
            cout<<"Enter the first number : ";
            cin>>a;
            sub(a);
        }
        else if (option==3){
            float a;
            cout<<"Enter the first number : ";
            cin>>a;
            multiply(a);
        }
        else if (option==4){
            float a;
            cout<<"Enter the first number : ";
            cin>>a;
            divide(a);
        }
        else {
            cout<<"Quit..";
            break;
        }
    }
}
