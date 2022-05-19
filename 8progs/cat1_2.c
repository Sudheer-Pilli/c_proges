/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
#define M_A_L
typedef struct num
{
    int data;
    int index;
} num;

void menu();
void insertnum(num *array, int index);
void printList(num *array, int cSize);

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}

void menu()
{
    int size = -1, choice, cSize = 0;
    while (size <= 0)
    {
        printf("Insert num of records : ");
        scanf("%d", &size);
    }
    num *array = malloc(size * sizeof(num));
printMenu:
    system("cls");
    printf("\n[1] : Insert a new num");
    printf("\n[2] : Print List");
    printf("\n[3] : Exit");
    printf("\n[>] : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (cSize < size)
        {
            insertnum(array, cSize);
            cSize += 1;
        }
        else
            printf("Array is full");
        break;
    case 2:
        printList(array, cSize);
        printf("\npress any key to continue");
        getch();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Invalid choice.");
        break;
    }
    goto printMenu;
}

void printList(num *array, int cSize)
{
    int i;
    if (cSize == 0)
    {
        printf("\nEmpty array. Insert some data first.\n");
        return;
    }
    printf("\n--------------------------");
    printf("\n    data        index    ");
    printf("\n--------------------------");
    for (i = 0; i < cSize; i += 1)
    {
        printf("\n     %d             %d       ", array[i].data, array[i].index);
    }
    printf("\n--------------------------");
}

void insertnum(num *array, int index)
{

    printf("Enter data : ");
    scanf("%d", &(array[index].data));
    
    printf("Enter index : ");
    scanf("%d", &(array[index].index));
}
