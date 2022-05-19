/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct STD
{
    char name[50];
    int regNum;
} STD;

void insertSTD(STD *array, int index);
void printList(STD *array, int cSize);
void menu();

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
        printf("Insert number of STDs : ");
        scanf("%d", &size);
    }
    STD *array = malloc(size * sizeof(STD));
printMenu:
    system("cls");
    printf("\n[1] : Insert a new STD");
    printf("\n[2] : Print List");
    printf("\n[3] : Exit");
    printf("\n[>] : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (cSize < size)
        {
            insertSTD(array, cSize);
            cSize += 1;
        }
        else
            printf("Array is full");
        break;
    case 2:
        printList(array, cSize);
        printf("\nClick any key to continue");
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

void printList(STD *array, int cSize)
{
    int i;
    if (cSize == 0)
    {
        printf("\nEmpty array. Insert some data first.\n");
        return;
    }
    printf("\n-------------------------------------------------");
    printf("\n    regNum         name                          ");
    printf("\n-------------------------------------------------");
    for (i = 0; i < cSize; i += 1)
    {
        printf("\n   %d          %s         ", array[i].regNum, array[i].name);
    }
    printf("\n-------------------------------------------------");
}

void insertSTD(STD *array, int index)
{

    printf("Enter RegNo : ");
    scanf("%d", &(array[index].regNum));
    
    printf("Enter First_name : ");
    fflush(stdin);
    fgets(array[index].name, 50, stdin);
    fflush(stdin);
}