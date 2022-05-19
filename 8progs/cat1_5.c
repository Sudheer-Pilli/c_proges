/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
#define M_A_L 1000
typedef struct person
{
    int P_age;
    char gender;
    char area[M_A_L];
    struct person *next;
} person;

void menu();
void insertPerson(person **head);
void printList(person **head);

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
    person *head = NULL;
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
        insertPerson(&head);
        break;
    case 2:
        printList(&head);
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

void printList(person **head)
{
    if (head == NULL)
    {
        printf("Insert some data");
        return;
    }
    person *temp = *head;
    printf("\n---------------------------------------------");
    printf("\n     P_age          gender          area                                                                       |");
    printf("\n---------------------------------------------");
    while (temp->next != NULL)
    {
        printf("\n   %d            %c           %s ", temp->P_age, temp->gender, temp->area);
        temp = temp->next;
    }
    printf("\n     %d            %c             %s ", temp->P_age, temp->gender, temp->area);
    printf("\n---------------------------------------------");
}

void insertPerson(person **head)
{

    person *new_Person = malloc(sizeof(person));
    int flag = 0;
    new_Person->P_age = -1;
    if(new_Person == NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    new_Person->next = NULL;
    while (new_Person->P_age <= 0|| new_Person->P_age >= 100)
    {
        if (flag)
        {
            printf("\nPlease enter P_age between 1 and 100\n");
        }
        printf("Enter P_age : ");
        scanf("%d", &new_Person->P_age);

        flag = 1;
    }

    flag = 0;
    new_Person->gender = 'g';
    fflush(stdin);

    while (new_Person->gender != 'm' && new_Person->gender != 'f')
    {
        if (flag)
        {
            printf("\nPlease enter m for male and f for female\n");
        }
        fflush(stdin);
        printf("Enter gender : ");
        scanf("%c", &new_Person->gender);
        flag = 1;
    }

    printf("Enter area : ");
    fflush(stdin);
    fgets(&new_Person->gender, 1000, stdin);
    if (*head == NULL)
    {
        *head = new_Person;
    }
    else
    {
        person *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_Person;
    }
}