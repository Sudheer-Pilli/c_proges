#include <stdio.h>
#include<stdlib.h>
#define size 20 
int top=-1, my_arr[size];
int i, arr_size;
void push();
void pop();
void show();
int main(void) {
  int choice;
  while(choice != 4){
  	  printf("choose your operation \n 1 push \n 2 pop \n 3 show \n 4 exit  ");
  scanf("%d", &choice);
  switch(choice){
    case 1: push();
            break;
    case 2: pop();
            break;
    case 3: show();
            break;
    case 4: exit(0);
    		break;
    default: printf("wrong choice");
      break;
  }
  }

  
//  push();  
//  pop();
//  show();
  return 0;
}
void push()
{
  printf("Enter the size of the stack: ");
  scanf("%d",&arr_size);
  for(i=1; i<arr_size;i++)
    {
      printf("insert elements into [%d]= ",i);
      scanf("%d", &my_arr[i]);
      top++;
    }
}
void pop()
{
  if (top ==-1){
  printf("Stack is empty: ");
  }
  else{
    printf("deleted elment %d", my_arr[top]);
    top=top-1;
  }
}
void show()
{
  printf("Element of the stack are \n");
  for (i=top; i>-1; i--)
    {
      printf("Elements in [%d] = %d \n",i, my_arr[i]);
    }
}
