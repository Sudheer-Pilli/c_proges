#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node // defing structure
{
    int a;
    struct node *link; // assigning pointer
} stack_node;

void init(stack_node **stacktop);
void print(stack_node **stacktop);
bool push(stack_node **list, char datapush);
bool pop(stack_node **list, char *datapop);

int main()
{
    stack_node *stack_top; // top as pointer
    printf("Stack Operation Using Linked Lists\n\n");
    stack_top = NULL;
    init(&stack_top);
    print(&stack_top);
    pop(&stack_top, )
    return 0;
} 

void init(stack_node **stacktop)
{
    
    int charIn, nodeCount;
    bool success;
    
    printf("Generating random numbers: ");
    for (nodeCount = 0; nodeCount < 10; nodeCount++)
    {
        
        charIn = rand() % 100;
        printf("\t%d", charIn);
        success = push(stacktop, charIn);
        if (!success)
        {
            printf("Error 100: Out of Memory\n");
            exit(100);
        } 
    }     
    printf("\n");
    return;
} 

bool push(stack_node **stacktop, char charIn)
{
    stack_node *New;
    bool success;
    
    New = (stack_node *)malloc(sizeof(stack_node));
    if (!New)
        success = false;
    else
    {
        New->a = charIn;
        New->link = *stacktop;
        *stacktop = New;
        success = true;
    } 
    return success;
} 

//bool pop(stack_node **stacktop, char *charOut)
//{
//    stack_node *del;
//    bool success;
//    if (*stacktop)
//    {
//        success = true;
//        *charOut = (*stacktop)->a;
//        del = *stacktop;
//        *stacktop = (*stacktop)->link;
//        free(del);
//    } 
//    else
//        success = false;
//    return success;
//} 

void print(stack_node **stacktop)
{
    char printdata;

    printf("Stack contained: ");
    while (pop(stacktop, &printdata))
        printf("\t%d", printdata);
    return;
}
