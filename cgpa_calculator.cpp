#include<stdio.h>
#include<stdlib.h>
struct node{
	float grade;
	float credit;
	struct node *next;
}*head=NULL,temp;int count=0;
float calculate();
int create();
void remove();
void reset();
void display();
int gradee();
int main()
{
	int ch;
	do{
		printf("\n1.add subject\n2.remove subject\n3.calculate\n4.reset\n5.display\n6.exit\n");
		printf("\nEnter the choise:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();break;
			case 2:remove();break;
			case 3:calculate();break;
			case 4:reset();break;	
		    case 5:display();break;
			case 6:return(0);break;
		    default:printf("\nINVALID CHOOSE!!!\n");break;
		}
		
	}while(ch<7);
}
int create()
{
	count++;
    float grade;
	float credit;
	struct node *newnode,*temp1;
	temp1=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("\n enter the %d subject grade:\n",count);
	grade=gradee();
	printf("\n enter the %d subject credit(if RA credit is 0):\n",count);
	
	scanf("%f",&credit);
	newnode->grade=grade;
	newnode->credit=credit;
	newnode->next=NULL;
    
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		 while(temp1->next!=NULL)
		 {
		    temp1=temp1->next;
		 }
		 temp1->next=newnode;
	}  

}
void remove()
{
	struct node *temp2=head,*temp3;int num=1;
	int position;
    printf("\nWhich subject is you to remove?\n");
	scanf("%d",&position);
	if(head==NULL)
	{
	  printf("\nNo Subject is enter:\n");
	}
	else
	{
		if(position==1)
	    {
	    	head=NULL;
	    	free(temp2);count--;
		}
		else
		{
			while(temp2!=NULL&&position!=++num)
			{
				temp2=temp2->next;
			}
			temp3=temp2->next;
			temp2->next=temp3->next;
			free(temp3);count--;
		}
		}
	}
void reset()
{
	struct node *temp4=head,*temp5;
	if(head==NULL)
	{
		printf("\nAll subject is already empty!!!\n ");
	}
	else
	{
		while(temp4!=NULL)
		{
			temp5=temp4;
			temp4=temp4->next;
			free(temp5);
			temp5=NULL;
		}
		head=NULL;count=0;
	}
}
float calculate()
{
	float totcred=0,totalmark=0;float gpa=0;
	struct node *temp6=head,temp7;
	if(head==NULL)
	printf("\nENTER THE MARKS!!!\n");
	else{
		while(temp6!=NULL)
		{
		 totcred+=temp6->credit;
		 totalmark+=temp6->grade*temp6->credit;
		  temp6=temp6->next;
 	    }
 	    gpa=totalmark/totcred;
 	    printf("\ncgpa is =%5.3f\n",gpa);
	}
}
void display()
{
	struct node *temp8=head;int con=1;
	if(head==NULL)
	printf("\nNo subject is entered!!\n");
	else{
		while(temp8!=NULL)
		{
			printf("\nsubject %d\n",con);
			printf("grade:=>%f\n",temp8->grade);
			printf("credit:=>%f\n",temp8->credit);
			con++;
			temp8=temp8->next;
		}
	}
}
int gradee()
{
	char g[3];int i=1;
	scanf("%s",&g);
	if(*g=='O')
	  return 10;
	else if(g[i]=='+')
	{
		if(*g=='A')
		  return 9;
		else 
		  return 7;
	}
	else if(*g=='A')
	  return 8;
	else if(*g=='B')
      return 6;
    else if (g[i]=='A')
    {
	  return 0;	
     }
	
}
