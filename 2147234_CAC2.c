/*
Name:Sudheer P
Roll no: 2147234 
Suject: C (data structures)
Assignement:C CAC2
 */

// This bst is about students of a college

#include<stdio.h>   // Headder files
#include<stdlib.h>
#include<string.h>

struct node
{
	int std_roll_no;
	char std_name[100];
	int datc;
	float m_avg;
	int marks_details[40];
	struct node *left, *right;
};

float yearly_avg[20];

void disp(int a[],int n)
{
	int i;
	printf("\nThe Order is: \n");
    printf("\n");
	for(i=0;i<n;i++) {
		printf(" %d,",a[i]);
	}
}

struct node *salesentry(struct node *m)
{
	int ch,i,j,x,c,pos=0,q=0;
	printf("\nEnter marks to be stored For the std_name: ");
	scanf("%d",&m->datc);
	if(m->datc<=100 && m->datc > 0)
	{
	
	printf("\n marks Entry\n1.Enter Marks Manually\n2.Generate marks For the std_name\nChoose: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			for(i=0;i<m->datc;i++)
			{
				printf("\nEnter Marks: ");
				scanf("%d",&m->marks_details[i]);
			}
			break;
		case 2:
			for(i=0;i<m->datc;i++)
			{
				m->marks_details[i] = rand()%50000;
			}
			break;
		default:
			printf("\nEnter Valid Option!");
			break;
	}
	printf("\nSorting Marks ");
	c = m->datc;
	for(i=0;i<c;i++)
	{
		pos = i;
		for (j=i;j<c-1;j++)
		{
			if(m->marks_details[pos]>m->marks_details[j])
			{
				pos = j;
			}
		}
		if(pos!=i)
		{
			x = m->marks_details[pos];
			m->marks_details[pos] = m->marks_details[i];
			m->marks_details[i] = x;
		}
	}
	disp(m->marks_details,c);
	
	return m;
}
else
{
	printf("\nEnter Valid Input Between 0 - 100");
	
}
}
struct node *newnode(int x){
	struct node *ptr;
	char n[20];
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->std_roll_no= x;
	printf("\nPlease Enter std_name Name:- ");
	scanf("%s",&n);
	strcpy(ptr->std_name,n);
	ptr = salesentry(ptr);
	ptr->left = ptr->right = NULL;
	return ptr;
}
void inorder(struct node* root){
	if(root!=NULL){
		int i=0;
		//traverse left
		inorder(root->left);
		
		//traverse root
	
		printf("\n Std_id: %d std_Name: %s ",root->std_roll_no,root->std_name);

		printf("\n Marks : ");
		for(i=0;i<root->datc;i++)
		{
			printf("%d,",root->marks_details[i]);
		}
		
		//traverse right
		inorder(root->right);
	}
}
struct node *input(struct node *node, int x){
	
	//return newnode if the tree is empty
	if(node == NULL)
		return newnode(x);
	if(x < node->std_roll_no)
		node->left = input(node->left, x);
	else
		node->right = input(node->right, x);
	
	return node;
}

void sminorder(struct node *root, int n) {
	if(root!=NULL)
	{
		int i=0;
		sminorder(root->left,n);
		if(n == root->std_roll_no)
		{
			printf("\nStd_id: %d std_Name: %s ",root->std_roll_no,root->std_name);
			printf("\n Marks : ");
			for(i=0;i<root->datc;i++)
			{
				printf("%d,",root->marks_details[i]);
			}
			return;
		}
		sminorder(root->right,n);
	}
	
}
 void mcal(struct node *root)
 {
 	if(root!=NULL){
		int i=0, temp = 0 ;
		
		//traverse left
		mcal(root->left);
		
		//traverse root
	
		printf("\nStd_id: %d std_nameName: %s ",root->std_roll_no,root->std_name);

		printf("\nmarks Data : ");
		for(i=0;i<root->datc;i++)
		{
			temp = temp + root->marks_details[i];
		}
		root->m_avg = (temp/root->datc);
		yearly_avg[root->std_roll_no] = root->m_avg;
		printf("\nstd marks Average: %f",root->m_avg);
		
		//traverse right
		mcal(root->right);
	}
 }
//find the inorder successor
struct node *minvalnode(struct node *node){
	struct node *current = node;
	while(current && current->left != NULL){
		current = current->left;	
	}
	return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int x) {
	int i;
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (x < root->std_roll_no)
    root->left = deleteNode(root->left, x);
  else if (x > root->std_roll_no)
    root->right = deleteNode(root->right, x);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minvalnode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->std_roll_no = temp->std_roll_no;
    root->datc = temp->datc;
    strcpy(root->std_name,temp->std_name);
    for(i=0;i<temp->datc;i++)
    {
    	root->marks_details[i]=temp->marks_details[i];
	}

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->std_roll_no);
  }
  return root;
}

void main()
{
	struct node *root = NULL;
	int choice = 0, nmon1=0,monno,nmon2=0,mondel,smon; 
	int i,j;
	float temp=0.0;
	while(choice!=6)
	{
	printf("\n Marks CALCULATOR\n1.ADD STDUENT NAME\n2.REMOVE STUDNET NAME\n3.DISPLAY ALL STUDENTMAKRS IN ORDER\n4.CHECK MARKS \n5.CALCULATE AVERAGE MARKS\n\n6.EXIT \nCHOOSE: ");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		printf("\nEnter the no of std_names want to insert: ");
  		    scanf("%d",&nmon1);
  		    if (nmon1 <= 12 && nmon1 > 0) {
  		    for(i=1;i<=nmon1;i++)
			  {
  	        		printf("\nEnter std_roll_no: ",i);
  	        		scanf("%d",&monno);
  	        		root = input(root,monno);
  	          } 
  	      }
			else {
				printf("Invalid std_name. Enter less than 12!");
			}   
    		break;
    	case 2:
    		printf("\nEnter the No. of std_names you want to delete: ");
            scanf("%d",&nmon2);
            for(j=1;j<=nmon2;j++)
			{
  	        	printf("\nEnter the %d std_name No. to be deleted: ",j);
  	        	scanf("%d",&mondel);
  	        	root = deleteNode(root,mondel);
            }  
    		break;
    	case 3:
    		printf("\nInorder traversal of std_names: ");
            inorder(root);
    		break;
    	case 4:
    		printf("Enter std_name No. To search: ");
    		scanf("%d",&smon);
    		sminorder(root,smon);
    		break;
    	case 5:
    		printf("\nCalculating Average");
    		mcal(root);
    		for(i=1;i<=12;i++)
    		{
    			temp = temp + yearly_avg[i];	
			}
			temp = (temp/(nmon1-nmon2));
    		printf("\nYearly Average : %f",temp);
    		break;
    	case 6:
    		printf("\nExiting Simulator...........");
    		exit(1);
    		break;
    	default:
    		printf("\nEnter Appropriate Choice!!!");
    		break;
	}
    
	}
}


