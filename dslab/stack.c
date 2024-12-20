#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};

struct node *top = NULL;


void push(int value)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next = NULL;
	if(top != NULL) 
	{
		newnode->next=top;
	}
	top=newnode;
	printf("%d pushed onto the stack\n",value);
 }
void pop()
{
	if(top==NULL)
    	{
		printf("stack underflow\n");
		return ;
	}
	struct node*temp=top;
	top=temp->next;
	printf("%d popped from the stack\n",temp->data);
	free(temp);
}
void display()
{
	if(top==NULL)
    	{
		printf("stack is empty\n");
		return ;
        }
	printf("stack elements:\n");
	struct node*temp=top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void search(int value)
{
	struct node*temp=top;
	int position=1;
  	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			printf("%d found at position %d\n",value,position);
			return ;
		}
		temp=temp->next;
		position++;
	}
	printf("%d not found in the stack\n",value);
}
int main()
{
	struct node*stack=NULL;
	int choice,value;
	while(1)
	{
		printf("choose an option\n");
	   	printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.search\n");
		printf("5.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
	switch(choice)
	{
		case 1: 
			printf("Enter a value: \n");
			scanf("%d",&value);
			push(value);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("enter the number you need to find\n");
			scanf("%d",&value);
			search(value);
			break;
		case 5:
			printf("exiting program\n");
			exit(0);
		default :
		printf("invalid choice,Please try again\n");
	}
}
return 0;
}
