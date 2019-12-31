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
int *AND();
int *NOR();
int *NAND();
int *XOR();
int *FirstComplement();
int *SecondComplement();
int *binaryNumber();
void printBinary(int *array);

void toBinary()
{
    system("cls");
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
    printf("\n");
}

void toDecimal()
{
    system("cls");
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
    printf("\n");
}

int *NOT()
{
    int i;
    int *array = binaryNumber();

    if(!array)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("-------------------------------\tX\tY\t\n");
    printf("NOT Logic gate invers the bits.\t0\t1\n");
    printf("1 is 0 and 0 is 1.\t\t1\t0\n");
    printf("-------------------------------\n");

    for(int i = 0; i < SIZE; i++)
    {
        array[i] = (array[i] + 1) % 2;
    }

    printBinary(array);
    printf("\n");

    return array;
}

int *OR()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *OR = malloc(sizeof(int) * SIZE);

    if(!first || !second)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("----------------------------------------------------------------------------\tX\tY\tZ\n");
    printf("OR Logic gate compares two bits and if one of them is 1 the ouput will be 1.\t0\t0\t0\n");
    printf("Output 0 is only if both are 0.\t\t\t\t\t\t\t0\t1\t1\n");
    printf("----------------------------------------------------------------------------\t1\t0\t1\n");
    printf("\t\t\t\t\t\t\t\t\t\t1\t1\t1\n");

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
    printf("\n");

    return OR;
}

int *AND()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *AND = malloc(sizeof(int) * SIZE);

    if(!first || !second)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("----------------------------------------------------------------------------\tX\tY\tZ\n");
    printf("AND Logic gate compares two bits and if one of them is 0 the ouput will be 0.\t0\t0\t0\n");
    printf("Output 1 is only if both are 1.\t\t\t\t\t\t\t0\t1\t0\n");
    printf("----------------------------------------------------------------------------\t1\t0\t0\n");
    printf("\t\t\t\t\t\t\t\t\t\t1\t1\t1\n");

    for(i = 0; i < SIZE; i++)
    {
        if(first[i] == 0 || second[i] == 0)
            *(AND + i) = 0;
        else if(first[i] == 1 && second[i] == 1)
            *(AND + i) = 1;
    }

    printBinary(first);
    printBinary(second);
    printf("--------AND\n");
    printBinary(AND);
    printf("\n");

    return AND;
}

int *NOR()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *NOR = malloc(sizeof(int) * SIZE);

    if(!first || !second)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("---------------------------------------------------------\tX\tY\tZ\n");
    printf("If you didn't do NOT, OR and AND go back to them.\t\t0\t0\t1\n");
    printf("NOR Logic gate works like OR with NOT applied at the end.\t0\t1\t0\n");
    printf("---------------------------------------------------------\t1\t0\t0\n");
    printf("\t\t\t\t\t\t\t\t1\t1\t0\n");

    for(i = 0 ; i < SIZE; i++)
    {
        if(first[i] == 1 || second[i] == 1)
            *(NOR + i) = (1 + 1) % 2;
        else if(first[i] == 0 && second[i] == 0)
            *(NOR + i) = (0 + 1) % 2;
    }

    printBinary(first);
    printBinary(second);
    printf("--------NOR\n");
    printBinary(NOR);
    printf("\n");

    return NOR;
}

int *NAND()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *NAND = malloc(sizeof(int) * SIZE);

    if(!first || !second)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("---------------------------------------------------------\tX\tY\tZ\n");
    printf("If you didn't do NOT, OR and AND go back to them.\t\t0\t0\t1\n");
    printf("NAND Logic gate works like AND with NOT applied at the end.\t0\t1\t1\n");
    printf("---------------------------------------------------------\t1\t0\t1\n");
    printf("\t\t\t\t\t\t\t\t1\t1\t0\n");

    for(i = 0 ; i < SIZE; i++)
    {
        if(first[i] == 0 || second[i] == 0)
            *(NAND + i) = (0 + 1) % 2;
        else if(first[i] == 1 && second[i] == 1)
            *(NAND + i) = (1 + 1) % 2;
    }

    printBinary(first);
    printBinary(second);
    printf("--------NAND\n");
    printBinary(NAND);
    printf("\n");

    return NAND;
}

int *XOR()
{
    int i;
    int *first = binaryNumber();
    int *second = binaryNumber();
    int *XOR = malloc(sizeof(int) * SIZE);

    if(!first || !second)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }
    
    printf("---------------------------------------------------------\tX\tY\tZ\n");
    printf("If you didn't do NOT, OR and AND go back to them.\t\t0\t0\t0\n");
    printf("XOR Logic gate if bits are the same it's 0. Not same is 1. \t0\t1\t1\n");
    printf("---------------------------------------------------------\t1\t0\t1\n");
    printf("\t\t\t\t\t\t\t\t1\t1\t0\n");

    for(i = 0; i < SIZE; i++)
    {
        if(first[i] == second[i])
            XOR[i] = 0;
        else
            XOR[i] = 1;
    }

    printBinary(first);
    printBinary(second);
    printf("--------XOR\n");
    printBinary(XOR);
    printf("\n");

    return XOR;
}

int *FirstComplement()
{
    int i;
    int *first = binaryNumber();

    if(!first)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("First complement adds 1 at the beggining of our binary number.\n");

    for(i = 0; i < SIZE; i++)
    {
        if(i == 7)
            if(first[i] == 1)
                first[i] = 0;
            else
                first[i] = 1;
    }

    printBinary(first);
    printf("\n");

    return first;
}

int *SecondComplement()
{
    int i;
    int *first = binaryNumber();

    if(!first)
    {
        printf("You messed up. . .\n");
        system("cls");
        return NULL;
    }

    printf("Second complement inverts the binary number(NOT) then adds 1 at the beggining.\n");

    //TODO: first = NOT(first);
    //TODO: first = FirstComplement(first)

    printBinary(first);
    printf("\n");

    return first;
}

int *binaryNumber()
{
    system("cls");
    int i;
    int *array = malloc(sizeof(int) * SIZE);

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter [%d] bit: ", i + 1);
        scanf("%d", &array[i]);
        if(*(array + i) != 0)
            if(*(array + i) != 1)
                return NULL;
    }
    printf("\n");

    system("cls");

    return array;
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
    printf("9. First Complement.\n");
    printf("10. Second Complement.\n");
    printf("11. Exit.\n");
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
            AND();
            break;
        case 6:
            NOR();
            break;
        case 7:
            NAND();
            break;
        case 8:
            XOR();
            break;
        case 9:
            FirstComplement();
        case 10:
            SecondComplement();
        case 11:
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
