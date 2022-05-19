/*
Name: Sudheer P
Rollno: 2147234
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct STD
{
    int reg_no;
    char name[50];
    struct STD *next;
} STD;

void menu();
void insert_std(STD **head);
void print_List(STD **head);

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
        printf("Insert STD of records : ");
        scanf("%d", &size);
    }
    STD *head = NULL;
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
        insert_std(&head);
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

void print_List(STD **head)
{
    if (head == NULL)
    {
        printf("Insert some coefficient");
        return;
    }
    STD *temp = *head;
    printf("\n-------------------");
    printf("\n  reg_no    Name  ");
    printf("\n-------------------");
    while (temp->next != NULL)
    {
        printf("\n   %d          %s     ", temp->reg_no, temp->name);
        temp = temp->next;
    }
    printf("\n   %d          %s     ", temp->reg_no, temp->name);
    printf("\n--------------------");
}

void insert_std(STD **head)
{

    STD *newSTD = malloc(sizeof(STD));
    int flag = 0;
    if (newSTD == NULL)
    {
        printf("Memory allocation error");
        exit(1);
    }
    newSTD->next = NULL;

    printf("Enter reg_no : ");
    scanf("%d", &newSTD->reg_no);
    fflush(stdin);
    printf("Enter name : ");
    fflush(stdin);
    fgets(newSTD->name, 50, stdin);

    if (*head == NULL)
    {
        *head = newSTD;
    }
    else
    {
        STD *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newSTD;
    }
}