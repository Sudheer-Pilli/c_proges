/*
Name: Sudheer P
Rollno: 2147234
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct number
{
    int Data;
    int index;
    struct number *next;
} number;

void Menu();
void insertNumber(number **head);
void print_List(number **head);

int main(int argc, char const *argv[])
{
    Menu();
    return 0;
}

void Menu()
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
        print_List(&head);
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

void print_List(number **head)
{
    if (head == NULL)
    {
        printf("Insert some Data");
        return;
    }
    number *temp = *head;
    printf("\n-------------------");
    printf("\n  Data     Index  ");
    printf("\n-------------------");
    while (temp->next != NULL)
    {
        printf("\n    %d        %d    ", temp->Data, temp->index);
        temp = temp->next;
    }
    printf("\n    %d        %d    ", temp->Data, temp->index);
    printf("\n--------------------");
}

void insertNumber(number **head)
{

    number *new_number = malloc(sizeof(number));
    int flag = 0;
    if (new_number == NULL)
    {
        printf("Memory allocation Failed");
        exit(1);
    }
    new_number->next = NULL;

    printf("Enter Data : ");
    scanf("%d", &new_number->Data);
    fflush(stdin);
    printf("Enter index : ");
    scanf("%d", &new_number->index);

    if (*head == NULL)
    {
        *head = new_number;
    }
    else
    {
        number *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_number;
    }
}