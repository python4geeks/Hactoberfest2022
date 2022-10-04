//* stack implementation using linkedlist

#include<stdio.h>
#include<stdlib.h>
//defining the structure
struct node
{
	int data;
	struct node *next;
}*head;
//push opearation
void push()
{
	int data;
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		puts("No memory allocated");
	}
	else
	{
		printf("Input data to push::");
		scanf("%d",&data);
		if(head==NULL)
		{
			ptr->data=data;
			ptr->next=NULL;
			head=ptr;
		}
		else
		{
			ptr->data=data;
			ptr->next=head;
			head=ptr;
		}
	}
	printf("Hurrah! value inserted into stack successfully");
}
//pop
void pop()
{
	int item;
	struct node *temp;
	if(head==NULL)
	{
		printf("Stack is underflowed\n");
	}
	else
	{
		item=head->data;
		temp=head;
		head=head->next;
		free(temp);
		printf("Popped out element:%d\n",item);
        item=item+1;
	}
}

//display
void display()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("Nothing to show\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int i;
	int choice;
	while(1)
	{

		printf("\n1. PUSH::\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Your choice::");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
				break;
		}
	}
	return 0;
}