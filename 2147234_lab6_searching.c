/*
Name: Sudheer P
Rollno: 2147234
Subject: C
*/

#include <stdio.h>
#include <stdlib.h>
#define GARBAGE = -999;

int *createArray();
int *createHashTable();
int partition(int *a, int lb, int ub);
void sort(int *a, int lb, int ub);
int binarySearch(int *a, int size, int searchEle);
void swap(int *a, int *b);
int linearSearch(int *a, int size, int searchEle);
void printArray(int *a, int size);

int main(void)
{
	int x, searchEle;
	int *a = createArray();
	int size = a[0];
	a = a + 1;
	printArray(a, size);
	printf("\nEnter element to search : ");
	scanf("%d", &searchEle);

	x = linearSearch(a, 10, searchEle);

	if (x > -1)
		printf("Element found at index : %d\n", x);
	else
		printf("Element not found.\n");
	
	printArray(a, size);
	printf("\n");
	sort(a, 0, size-1);
	printArray(a, size);

	printf("\nEnter element to search : ");
	scanf("%d", &searchEle);

	x = binarySearch(a, size, searchEle);

	if (x > -1)
		printf("Element found at index : %d\n", x);
	else
		printf("Element not found.\n");

	return 0;
}

int *createArray()
{
	int size, i, index, num;
	printf("Enter size of the array : ");
	scanf("%d", &size);
	int *a = malloc(size * sizeof(int));
	if (a != NULL)
	{
		a[0] = size;
		i = 1;
		while (i <= a[0])
		{
			printf("Enter the element : ");
			scanf("%d", a + i);
			i += 1;
		}
		printf("\nArray Created\n");
		return a;
	}
	else
	{
		printf("\nMemory allocation failed.");
		exit(0);
	}
}

int binarySearch(int *a, int size, int searchEle)
{
	int left = 0, mid;
	int right = size - 1;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (a[mid] == searchEle)
		{
			return mid;
		}
		else if (a[mid] < searchEle)
		{
			left = mid + 1;
		}
		else if (searchEle < a[mid])
		{
			right = mid - 1;
		}
	}
	return -1;
}
int linearSearch(int *a, int size, int searchEle)
{
	int i;
	for (i = 0; i < size; i += 1)
	{
		if (a[i] == searchEle)
		{
			return i;
		}
	}
	return -1;
}

void sort(int *a, int lb, int ub)
{
	if (lb < ub)
	{
		int loc = partition(a, lb, ub);
		sort(a, lb, loc - 1);
		sort(a, loc + 1, ub);
	}
}

int partition(int *a, int lb, int ub)
{
	int start = lb;
	int end = ub;
	int pivot = a[lb];
	while (start < end)
	{
		while (a[start] <= pivot & start < ub)
		{
			start++;
		}
		while (a[end] >= pivot & end > lb)
		{
			end--;
		}
		if (start < end)
		{
			swap(a + start, a + end);
		}
	}
	swap(a + lb, a + end);
	return end;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *a, int size)
{
	int i;
	for (i = 0; i < size; i += 1)
	{
		printf("%d, ", a[i]);
	}
}
