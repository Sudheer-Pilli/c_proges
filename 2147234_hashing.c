/*
Name: Sudheer 
Rollno: 2147234
*/
#include <stdio.h>
#define GARBAGE -69420
#include <stdlib.h>
#define e_space 5

int *createArray();
int G_hash(int element, int size);
void printArray(int *array, int size);
void search(int *array,int size);

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter size no: ");
    scanf("%d", &size);
    int *array = createArray(size);
    search(array, size);
    printArray(array, size);
    return 0;
}

int *createArray(int size)
{
    int i, *array, index, element, count;

    array = malloc(size * sizeof(int) * e_space);
    if(array == NULL){
        printf("Memory Allocation Failed!!");
        exit(1);
    }
    for (i = 0; i < size * e_space; i += 1)
    {
        array[i] = GARBAGE;
    }
    for (i = 0; i < size +2; i += 1)
    {
    takeIn:
        count = 0;
        printf("Enter element : ");
        scanf("%d", &element);
        index = G_hash(element, size);
        while (array[index] != GARBAGE && count < e_space)
        {
            index += 1;
            count += 1;
        }
        if (count == e_space)
        {
            printf("\nNo space for element (Extra space full).. Try another element.\n");
            goto takeIn;
        }
        else
        {
            array[index] = element;
        }
    }
    return array;
}

void printArray(int *array, int size)
{
    int i;
    printf("\n[");
    for (i = 0; i < size * e_space; i += 1)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b]\n");
}

void search(int *array, int size)
{
    int searchelement, index, count;
    printf("Enter search element : ");
    scanf("%d", &searchelement);
    index = G_hash(searchelement, size);
    if (array[index] == searchelement)
    {
        printf("elementment Found");
    }
    else if (array[index] == GARBAGE)
    {
        printf("elementment does not exist");
    }
    else
    {
        int count = 0;
        while (array[index] != GARBAGE && count < e_space && array[index] != searchelement)
        {
            index += 1;
            count += 1;
        }
        if (array[index] == searchelement)
        {
            printf("elementmet found at index in hashed list : %d", index);
        }
        else
        {
            printf("elementment does not exist");
        }
    }
}

int G_hash(int element, int size)
{
    int hash = (element % size) * e_space;
    return (hash);
}
