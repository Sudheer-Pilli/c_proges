/*
Name: sudheer
Rollno : 2147234*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE 1000

void bruteforce(char *text, char *pat, int t_size, int patSize);
void kmp(char *text, char *pat, int t_size, int patSize);
int *failureFunction(char *pat, int patSize);

int main()
{
    char text[SIZE], pat[SIZE];
    int sizeText, sizepat, choice;

    printf("Enter text : ");
    fflush(stdin);
    fgets(text, SIZE, stdin);
    sizeText = strlen(text) - 1;

    printf("Enter pat : ");
    fflush(stdin);
    fgets(pat, SIZE, stdin);
    sizepat = strlen(pat) - 1;

    printf("\n[1] : KMP");
    printf("\n[2] : Bruteforce");
    printf("\n[3] : Exit");
    printf("\n[>] : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        kmp(text, pat, sizeText, sizepat);
        break;
    case 2:
        bruteforce(text, pat, sizeText, sizepat);
        break;
    default:
        printf("Invalid choice");
        break;
    }
    getch();
    system("cls");
    main();
    return 0;
}

void bruteforce(char *text, char *pat, int t_size, int patSize)
{
    int i, j, flag;
    for (i = 0; i <= t_size - patSize; i += 1)
    {

        flag = 1;
        for (j = 0; j < patSize; j += 1)
        {
            if (text[i + j] != pat[j])
            {
                flag = 0;
                break;
            }
        }
       	if(flag != 0){
       		printf("Match found at %d",i);
       		return;
		   }
    }
    printf( "\npat Not found..!");
}

void kmp(char *text, char *pat, int t_size, int patSize)
{
    int *F = failureFunction(pat, patSize);

    int i = 0;
    int j = 0;
    int k = 0;
    printf("\nFailure function : [");
    for( k= 0; k < patSize; k += 1){
        printf("%d, ", F[k]);
    }
    printf("\b\b]\n");

    while (i < t_size)
    {
        if (text[i] == pat[j])
        {

            if (j == patSize - 1)
            {
                printf("Match found at %d ", i-j);
                return;
            }
            else
            {
                i += 1;
                j += 1;
            }
        }
        else
        {
            if (j > 0)
            {
                j = F[j - 1];
            }
            else
            {
                i += 1;
            }
        }
    }
    printf("No match");
}

int *failureFunction(char *pat, int patSize)
{
    int *F = malloc(sizeof(int) * patSize);
    if (F == NULL)
    {
        printf("\nMemory Allocation Failed.");
        exit(1);
    }
    else
    {
        F[0] = 0;
        int i = 1, j = 0;
        while (i < patSize)
        {
            if (pat[i] == pat[j])
            {
                F[i] = j + 1;
                i += 1;
                j += 1;
            }
            else if (j > 0)
            {
                j = F[j - 1];
            }
            else
            {
                F[i] = 0;
                i += 1;
            }
        }
    }
    return(F);
}
