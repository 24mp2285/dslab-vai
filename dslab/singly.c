 struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));#include<stdio.h>
#include<stdlib.h>
struct Node
	{
		int data;
		struct Node*next;
	};
struct Node*head=NULL;
struct Node*createNode(int data)
	{
		 struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
		  newNode->data=data;
		  newNode->next=NULL;
		  return newNode;
	}
void inat_beg(int data)
	{
		struct Node*newNode=createNode(data);
		newNode->next=head;
		head=newNode;

	}
void inat_end(int data)
	{
		struct Node*newNode=createNode(data);
		if(head==NULL)
			{
				head=newNode;
			}
		return; 
		struct Node*temp=head;
     		while (temp->next != NULL)
	        temp = temp->next;
	        temp->next = newNode;

	}

void inat_any(int data,int position)
	{
		if (position < 1)
			 {
       				 printf("Position should be >= 1.\n");
       				 return;
    			}
    		if (position == 1) 
			{
       				 inat_beg(data);
		       		 return;
    			}
   		 struct Node* newNode = createNode(data);
   		 struct Node* temp = head;
   		 for (int i = 1; i < position - 1 && temp != NULL; i++)
			 {
       				 temp = temp->next;
   			 }
	        if (temp == NULL)
			 {
        			printf("Position is greater than the length of the list.\n");
			        free(newNode);
   			 }
		 else
			 {
      				  newNode->next = temp->next;
       				 temp->next = newNode;
    			}
	}	
void delat_beg()
	{
		 if (head == NULL) {
	         printf("List is empty.\n");
       		 return;
    	}
   	 struct Node* temp = head;
   	 head = head->next;
   	 free(temp);
	}
void delat_end()
	{
		if (head == NULL)
			 {
    			   printf("List is empty.\n");
   			   return;
   			 }
   		 struct Node* temp = head;
 	        if (temp->next == NULL)
			 {
      				  free(temp);
     				   head = NULL;
       				 return;
   			 }
   		 struct Node* prev = NULL;
  		  while (temp->next != NULL)
			 {
  		     		 prev = temp;
       				 temp = temp->next;
   			 }
   				 prev->next = NULL;
   				 free(temp);
	}
void delat_any(int position)
	{
		if (head == NULL)
			 {
       				 printf("List is empty.\n");
      	 			 return;
   			 }
	        if (position < 1)
			 {
      				  printf("Position should be >= 1.\n");
       				 return;
   			 }
   		 if (position == 1)
			 {
    				    delat_beg();
     				   return;
    			}
 		   struct Node* temp = head;
   		   struct Node* prev = NULL;
   		 for (int i = 1; i < position && temp != NULL; i++) 
			{
       				 prev = temp;
       				 temp = temp->next;
   			 }
   		 if (temp == NULL)
			 {
       				 printf("Position is greater than the length of the list.\n");
			    }
		 else
			 {
       				 prev->next = temp->next;
        			free(temp);
    			}

	}
void display()
	{
		struct Node*temp=head;
		if(temp==NULL)
			{
				printf("this is an empty list");
			}
		else
			{
				while(temp!=NULL)
					{
						printf("%d-->",temp->data);
						temp=temp->next;
					}
			}
	}
int main()
	{	int choice,position,data;
		do
			{
				printf("1.insert at begining \n");
				printf("2.insert at end \n");
				printf("3.insert at any position \n");
				printf("4.delete at begining \n");
				printf("5.delete at end \n");
				printf("6.delete at any position \n");
				printf("7.display \n");
				printf("8.exit\n");
				printf("enter your choice\n");
				scanf("%d",&choice);
				switch(choice){
					case 1: printf("enter the value to be inserted");
						scanf("%d",&data);
						inat_beg(data);
						break ;
					case 2: printf("enter the value to be inserted");
                                                scanf("%d",&data);
						inat_end(data);
						break ;
					case 3: printf("enter the value to be inserted");
                                                scanf("%d",&data);
						printf("enter the position to be inserted");
                                                scanf("%d",&position);
						inat_any(data,position);
						break ;
					case 4: delat_beg(&head);
						break ;
					case 5: delat_end(&head);
						break ;
					case 6: printf("enter the position of the value which want to be deleted ");
                                                scanf("%d",&position);
						delat_any(position);
						break ;
					case 7: display();
						break ;
					case 8: printf("exiting programme");
						exit (0);

					default:
						printf("invalid entry,please enter a valid option");
						}
			}
	while(choice!=8);
	return 0;
	}
