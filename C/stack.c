//* stack using array

#include <stdio.h>
#include <stdlib.h>
#define size 50
int top=-1, input_array[size];
void push();
void pop();
void show();
void push()
{
    int x;
    if (top==size-1)
    {
        printf("Oh! No stack is full");
    }
    else{
        printf("Input data to be pushed:");
        scanf("%d",&x);
        top+=1;
        input_array[top]=x;

    }
    printf("Hurrah:%d inserted succesfully into stack",input_array[top]);
    
}
//*  pop 
void pop()
{
    if (top==-1)
    {
        printf("Sorry, stackis underflow");
    }
    else
    {
        printf("Popped element from stack:%d",input_array[top]);
        top=top-1;

    }
    
}
//* show
void show()
{
    if (top==-1)
    {
        printf("Oh! No, stack is empty");

    }
    else
    {
        for ( int i = top; i >=0; --i)
        {
            printf("%d\n",input_array[i]);
        }
        
    }
    
}
//! now using int main
int main()
{
	int choice;
	
	while(1)	
	{
		printf("\nOperations performed by Stack");
		printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: show();
					break;
			case 4: exit(0);
			
			default: printf("\nInvalid choice!!");
		}
	}
    return 0;
}