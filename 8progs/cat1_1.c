/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_AREA_LEN 1000
typedef struct person
{
    int age;
    char gender;
    char area[MAX_AREA_LEN];
} person;

void menu();
void insertPerson(person *array, int index);
void removePerson(person *array, int index);
void printList(person *array, int cSize);

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
        printf("Insert number of records : ");
        scanf("%d", &size);
    }
    person *array = malloc(size * sizeof(person));
printMenu:
    system("cls");
    printf("\n[1] : Insert a new person");
    printf("\n[2] : Print List");
    printf("\n[3] : Exit");
    printf("\n[>] : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (cSize < size)
        {
            insertPerson(array, cSize);
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

void printList(person *array, int cSize)
{
    int i;
    if (cSize == 0)
    {
        printf("\nEmpty array. Insert some data first.\n");
        return;
    }
    printf("\n---------------------------------------");
    printf("\n     age          gender          area ");
    printf("\n---------------------------------------");
    for (i = 0; i < cSize; i += 1)
    {
        printf("\n     %d             %c           %s", array[i].age, array[i].gender, array[i].area);
    }
    printf("\n---------------------------------------");

}

void insertPerson(person *array, int index)
{

    array[index].age = 0;
    int flag = 0;

    while (array[index].age <= 0 || array[index].age >= 100)
    {
        if (flag)
        {
            printf("\nPlease enter age between 1 and 100\n");
        }
        printf("Enter age : ");
        fflush(stdin);
        scanf("%d", &(array[index].age));
        flag = 1;
    }

    flag = 0;
    array[index].gender = 'g';
    while (array[index].gender != 'm' && array[index].gender != 'f')
    {
        if (flag)
        {
            printf("\nPlease enter m for male and f for female\n");
        }
        fflush(stdin);
        printf("Enter gender : ");
        scanf("%c", &(array[index].gender));
        flag = 1;
    }

    printf("Enter area : ");
    fflush(stdin);
    fgets(array[index].area, MAX_AREA_LEN, stdin);
}
