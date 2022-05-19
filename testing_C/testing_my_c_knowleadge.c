#include<stdio.h>
int main(){
	int Age, *p;
	char Name, temp;
	
//	scanf("%c",&temp);
	printf("Age? \n");
	scanf("%d",&Age);
	printf("Name %d years old \n", Age);
	p = &Age;
	printf("%x \n", p);
	*p = 11;
	printf("%d \n", *p);
	printf("Name %d years old \n", Age);
	printf(" \n hello C");
	return 0;
}
