#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};
struct node * top=NULL;

void push(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=x;

    if(top==NULL){
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}

void pop(){
    struct node * current=top;
    if(top!=NULL)
    {
        top=current->next;
        free(current);
    }
    else   printf("no elements");
}

void display(){
    struct node * current=top;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}

void main(){
    int option=0;
    int d;
    while(1){
        printf("\n1.push\t2.pop\t3.show\t0.exit:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("data:");scanf("%d",&d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;   
        case 0:
            exit(0);     
        default:
            break;
        }
    }
}
