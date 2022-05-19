/*
Name: Sudheer P
Rollno: 2147234
Subject: Data Structures
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct voters // structure for voters
{	
	int code;
	int age;
	int gender;
};
struct node 
{
	struct voters person;
	struct node *next;
};
void input(struct voters voter_count[],int num_size)
{
	int i;
	for(i=0;i<num_size;i++)
	{	
		
		printf(" %d th voter details : ",i+1);
		printf(" \n Enter the age : ");
		scanf("%d",&voter_count[i].age);
		printf(" Enter the Gender(1 or 0) : ");
		scanf("%d",&voter_count[i].gender);
		printf(" Enter the area code  : ");
		scanf("%d",&voter_count[i].code);
		printf("\n------------------------------------\n");
	}
}
void display(struct voters voter_count[],int num_size)
{
	int i;
	
	for(i=0;i<num_size;i++)
	{		
		printf("\n------------------------------------\n");
		printf(" Age : %d",voter_count[i].age );
		printf("\n Gender : %d ",voter_count[i].gender);
		printf("\n Areacode  : %d \n",voter_count[i].code);
//		printf("\n------------------------------------\n");
	}
}

//void enque(struct node **head,struct voters voter_count)
//{
//	struct node *nn;
//	nn=(struct node *)malloc(sizeof(struct node));
//	nn->person.age=voter_count.age;
//	nn->person.gender=voter_count.gender;
//	nn->person.code=voter_count.code;
//	nn->next=NULL;
//	if(*head==NULL)
//	{
//		*head=nn;
//	}
//	else
//	{
//		nn->next=*head;
//		*head=nn;		
//	}
//	printf(" enqueued successfully");
//}

//struct voters deQ(struct node **head)
//{
//	struct node *temp,*prev;
//	struct voters n;
//	struct voters vtemp;
//	if(*head->next==NULL)
//	{
//		temp=*head;
//		n.age=temp->person.age;
//		n.code=temp->person.code;
//		n.gender=temp->person.gender;
//		free(temp);
//		*head=NULL
//		return n;
//	}
//	if(*head!=NULL)
//	{
//	
//		while(temp->next!=NULL)
//		{
//			prev=temp;
//			temp=temp->next;
//		}
//		prev->next=NULL;
//		n.age=temp->person.age;
//		n.code=temp->person.code;
//		n.gender=temp->person.gender;
//		free(temp);
//		return n;
//	}	
//}



//void count_gender(struct node **head)
//{
//	struct node *temp;
//	int mcount=0,fcount=0;
//	struct voters v;
//	
//	printf("\n\tAge\tGender\t Code \n");
//	while(*head!=NULL)
//	{
//		v=deQ(head);
//		enQ(&temp,voter_count);
//		printf("\n\t%3d\t",voter_count.age);
//		if(voter_count.gender==1)
//		{
//			printf("MALE");
//			mcount++;
//		}
//		else
//		{
//			printf("FEMALE");
//			fcount++;
//		}
//		printf("\t%6d",voter_count.code);
//		
//	}
//	
//	printf("\n\n\n Males : %d Females : %d",mcount,fcount);
//	*head=temp;
//}


//void enquee_struct(struct voters num_size[],int n,struct node **head)
//{
//	int i;
//	for(i=0;i<n;i++)
//	{
//		enQ(head,num_size[i]);
//	}
//}
void main()
{
	struct voters voter_count[MAX],temp;
	struct node *head=NULL;
	int num_size,i;
	
	printf(" Give a_size : ");
	scanf("%d",&num_size);
	input(voter_count,num_size);
	display(voter_count,num_size);
//	enquee_struct(voter_count,num_size,&head);
//	count_gender(&head);
}
