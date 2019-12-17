#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void toBinary()
{
    int i;
    int *tempArray = malloc(sizeof(int) * 8);
    int num;

    printf("Enter a number you want to convert to binary: ");

    scanf("%d", &num);

    if(num < 0 || num > 255)
    {
        printf("Not in the range of 8 bits. \n");
        return;
    }

    printf("We divide out number with the number 2. The remainder is either 0 or 1.\n");
    printf("We need that remainder to know if the bit is 1 or 0.\nWhen we look at the the sequence of bits we are looking backwards.\n");
    printf("That's why the for loop is going backwards.\n");

    for(i = 7; i > -1; i--)
    {
        *(tempArray + i) = num % 2;
        num = num / 2;
        printf("%d / 2 = %d\n", num, *(tempArray + i));
    }

    printBinaryArray(tempArray);

    return;
}

void toDecimal()
{
    int i;
    int decimal = 0;
    int *binary = binaryNumber();

    printf("The power of 2 is the key here. Each bit has it's exponent.\nFor example: the 0th bit has the exponent of 0.\n");
    printf("The 1st bit has the exponent of 1.\nSo that means that we should just add their exponents.\n");
    printf("The maximum number is 255 because of that. If we add all of the two's exponents we will get 255.\n");

    for(i = 0; i < 8; i++)
    {
        if(*(binary + i) != 0)
        {
            printf("%d + %d(2 to the power of %d)", decimal, pow(2, (float)i), i);
            decimal += pow(2, (float)i);
        }
    }

    printf("The number we got is %d.\n", decimal);
    return;
}

int *binaryNumber()
{
    int i = 0;
    int j = 7;
    int *tempArray = malloc(sizeof(int) * 8);
    do
    {
        printf("Enter the %d bit", ++j);
        scanf("%d", (&tempArray + i));
        i++; j--;
    } while (i < 8);

    return tempArray;   
}

void printBinaryArray(int *array)
{
    if(array)
    {
        printf("\n");
        for(int i = 0; i < 8; i++)
        {
            printf("%d", *(array + i));
        }
        printf("\n\n");    
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
            toBinary();
            break;
        case 2:
            toDecimal();
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