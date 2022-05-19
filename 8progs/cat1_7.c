/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int coefficient;
    int degree;
    struct number *next;
} number;

void menu();
void insertNumber(number **head);
void printList(number **head);

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
    number *head = NULL;
printMenu:
    system("cls");
    printf("\n[1] : Insert a new number");
    printf("\n[2] : Print List");
    printf("\n[3] : Exit");
    printf("\n[>] : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertNumber(&head);
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

void printList(number **head)
{
    if (head == NULL)
    {
        printf("Insert some coefficient");
        return;
    }
    number *temp = *head;
    printf("\n-------------------");
    printf("\n  Coefficient     Degree  ");
    printf("\n-------------------");
    while (temp->next != NULL)
    {
        printf("\n    %d        %d    ", temp->coefficient, temp->degree);
        temp = temp->next;
    }
    printf("\n   %d        %d    ", temp->coefficient, temp->degree);
    printf("\n--------------------");
}

void insertNumber(number **head)
{

    number *newnumber = malloc(sizeof(number));
    int flag = 0;
    if (newnumber == NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }
    newnumber->next = NULL;

    printf("Enter coefficient : ");
    scanf("%d", &newnumber->coefficient);
    fflush(stdin);
    printf("Enter degree : ");
    scanf("%d", &newnumber->degree);

    if (*head == NULL)
    {
        *head = newnumber;
    }
    else
    {
        number *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnumber;
    }
}