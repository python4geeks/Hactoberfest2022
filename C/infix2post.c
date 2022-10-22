#include<stdio.h>

#define size 100
char arr[size];
top= -1;
  
void push(char x){
    top++;
    arr[top]=x;
}
void pop(){
    if(arr[top]!='(')
        printf("%c",arr[top]);
    top--;
}

int pr(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/' || c=='%'){
        return 2;
    }
    else
        return -1;
}
int isalnum(char c){
    if((c>='a' && c<='z')||(c>='A' && c<='B')|| (c>='1' && c<='9'))
        return 1;
    else
        return 0;    
}
int main(){

    char a[size];
    printf("exp:");
    scanf("%s",a);
    for(int i=0; a[i]!= '\0';i++){
        if(isalnum(a[i])){
            printf("%c",a[i]);
        }
        else{
            if(top==-1 || a[i]=='(')
                push(a[i]);
            else if(a[i]==')'){
                while(arr[top]!='('){
                    pop();
                }
            }
            else    {
                while(pr(a[i])<=pr(arr[top]) && top>=0 && pr(a[i])!=-1){
                    pop();
                }
                push(a[i]);
            }
        }
    }
    while (top>=0)
    {
        pop();
    }
    
    return 0;
}