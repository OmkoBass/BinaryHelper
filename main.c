#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 8

void printMainScreen();
void choose(int n);
void toBinary();
void toDecimal();
int *NOT();
int *OR();
int *binaryNumber();
void printBinary(int *array);

void toBinary()
{
    int i;
    int num;
    int *binary = malloc(sizeof(int) * SIZE);

    char help = '^';

    printf("-----------------------------------------------------------------------------------\n");
    printf("We divide the entered number by two and the remainder of it is the bit that counts.\n");
    printf("We then write the bits backwads.\n");
    printf("-----------------------------------------------------------------------------------\n");

    printf("Enter a number from 0 to 255: ");
    scanf("%d", &num);

    if(num > -1 && num < 256)
    {
        for(i = SIZE-1; i >= 0; i--)
        {
            printf("%d : 2 = %d %c\n", num, num % 2, help);
            binary[i] = num % 2;
            num = num / 2;
            help = '|';
        }
    }

    printf("The number is: "); printBinary(binary);
}

void toDecimal()
{
    int i;
    int decimal = 0;
    int *binary = binaryNumber();

    if(!binary)
        return;
    printf("------------------------------------------------------\n");
    printf("The two's exponent is key here.\nFirst(zero) digit is the power of zero.\n");
    printf("The second(one) digit is the power of one and so on.\n");
    printf("We add all of these numbers and get our decimal number.\n");
    printf("------------------------------------------------------\n");
    
    for(int i = 0; i < SIZE; i++)
    {
        if(binary[i] == 1)
            decimal += pow(2, i);
    }

    printf("The number is: %d\n", decimal);
}

int *binaryNumber()
{
    int i;
    int *array = malloc(sizeof(int) * SIZE);

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter [%d] bit: ", i + 1);
        scanf("%d", &array[i]);
        //TODO if statement for zeros and ones
    }
    printf("\n");

    return array;
}

int *NOT()
{
    int i;
    int *array = binaryNumber();

    printf("-------------------------------\n");
    printf("NOT Logic gate invers the bits.\n");
    printf("1 is 0 and 0 is 1.\n");
    printf("-------------------------------\n");

    for(int i = 0; i < SIZE; i++)
    {
        array[i] = (array[i] + 1) % 2;
    }

    printBinary(array);

    return array;
}

int *OR()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *OR = malloc(sizeof(int) * SIZE);

    printf("----------------------------------------------------------------------------\n");
    printf("OR Logic gate compares two bits and if one of them is 1 the ouput will be 1.\n");
    printf("0 output is only if both are 0.\n");
    printf("----------------------------------------------------------------------------\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(first[i] == 1 || second[i] == 1)
            *(OR + i) = 1;
        else if(first[i] == 0 && second[i] == 0)
            *(OR + i) = 0;
    }

    printBinary(first);
    printBinary(second);
    printf("--------OR\n");
    printBinary(OR);

    return OR;
}

void printBinary(int *array)
{
    int i = 0;
    for(i = 0; i < SIZE; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

void mainScreen()
{
    printf("~~~BINARY GATES PROGRAM~~~\n");
    printf("Choose what you want to do\n");
    printf("1. Convert a number to binary.\n");
    printf("2. Convert a binary number to decimal\n");
    printf("3. Logical NOT on two binary numbers.\n");
    printf("4. Logical OR on two binary numbers.\n");
    printf("5. Logical AND on two binary numbers.\n");
    printf("6. Logical NOR on two binary numbers.\n");
    printf("7. Logical NAND on two binary numbers.\n");
    printf("8. Logical XOR on two binary numbers.\n");
    printf("9. Exit.\n");
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
            NOT();
            break;
        case 4:
            OR();
            break;
        case 5:
            //AND
            break;
        case 6:
            //NOR
            break;
        case 7:
            //NAND
            break;
        case 8:
            //XOR
            break;
        case 9:
            exit(0);
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