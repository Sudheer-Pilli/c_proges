#include <stdio.h>
int n,count=1,n_arr[100];
int main(void)
{
  printf("Enter your arrya size: ");
  scanf("%d",&n);
  p_array(n);
}
int p_array(int n){
    while(count<=n)
    { 
      printf("Enter element no [%d]",count);
      scanf("%d",&n_arr[n]);
      count++; 
    }
}