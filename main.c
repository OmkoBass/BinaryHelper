#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* toBinary(int n)
{
    int i;
    int *tempArray = malloc(sizeof(int) * 8);
    int num;

    printf("Enter a number you want to convert to binary: ");
    do
    {
        scanf("%d", &num);
        for(i = 7; i > -1; i--)
        {
            *(tempArray + i) = n % 2;
            n = n / 2;
        }    
    } while (num < 256 || num > -1);
    
    return tempArray;
}

int* logicOR(int *first, int *second)
{
    if(first && second)
    {
        int *newArray = malloc(sizeof(int) * 8);
        for(int i = 0; i < 8; i++)
        {
            *(newArray + i) = *(first+i) & *(second+i);
        }
        return newArray;
    }
    else
        return NULL;
}

int toDecimal(int *array)
{
    if(array)
    {
        int i;
        int decimal = 0;
        for(i = 0; i < 8; i++)
        {
            if(*(array + i) != 0)
            {
                decimal += pow(2, (float)i);
            }
        }

        return decimal;
    }
    else
        return -1;
}

void printBinaryArray(int *array)
{
    if(array)
    {
        for(int i = 0; i < 8; i++)
        {
            printf("%d", *(array + i));
        }
        printf("\n");    
    }
    else
        printf("NULL\n");
}

void mainScreen()
{
    printf("~~~BINARY OPERATIONS PROGRAMS~~~\n");
    printf("Choose what you want to do\n");
    printf("1. Convert a number to binary.\n");
    printf("2. Convert a binary number to decimal\n");
    printf("3. Logical OR on two binary numbers.\n");
    printf("4. Logical AND on two binary numbers.\n");
    printf("5. Logical NOR on two binary numbers.\n");
    printf("6. Logical NAND on two binary numbers.\n");
    printf("7. Logical XOR on two binary numbers.\n");
    printf("8. Exit.\n");
    printf("Explenations will be given on how this works when it's executed.\n");
}

void choose(int n)
{
    switch(n)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Bad input. Choose again. . .\n");
            break;
    }
}

int main()
{
    int choice;

    for(;;)
    {
        mainScreen();
        scanf("%d", &choice);    
        choose(choice);
    }

    return 0;
}