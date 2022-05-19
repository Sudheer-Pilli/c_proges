//Name:- Sudheer P
//Register number:- 2147234
//Program:- Implementation of enqueue and dequeue


//including the header files:-->
#include<stdio.h>
#include<stdlib.h>

//creating a structure node:-->
struct  node
{
    int data;
    struct node *next;
};


//creating a pointer pointing to front and rear
struct node *front = NULL;
struct node *rear;


//function declaration:-->
void enqueue();
void dequeue();
void display();


//making the main function for the program:-->
void main()
{
    int choice;
    while (choice!=4)
    {
        printf("\t\tImplementation of enqueue and dequeue concept");
        printf("\nPROGRAM MENU");
        printf("\n1.Insert or enqueue an element\n2.Dequeue an element\n3.Display the queue\n4.Exit\n");
        printf("\n=============================================================================================");
        printf("\nEnter your choice:- ");
        scanf("%d",&choice);


        //using the switch to switch between opeartions:-->
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nSorry it was an invalid request.\nInput a valid entry.");
            break;
        }
    }
}



//defining the function for enqueue:-->
void enqueue()
{
    struct node *ptr;
    int item;

    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOverflow");
        return;
    }
    else
    {
        printf("\nEnter value:\t ");
        scanf("%d",&item);
        ptr ->data = item;
        if (front==NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else{
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }   
    }
}


//defining the function for dequeue:-->
void dequeue()
{
    struct node *ptr;
    if (front==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}


//defining the display function;-->
void display()
{
    struct node *ptr=NULL;
    ptr = front;
    if(front==NULL)
    {
        printf("\nEmpty queue\n");
    }
    else{
        printf("\nPrinting the values......\n");
        while(ptr!=NULL)
        {
            printf("\n%d\n",ptr->data);
            ptr = ptr->next;
        }
    }
}



