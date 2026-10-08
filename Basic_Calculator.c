#include <stdio.h>

int main()
{
    char choice;
    float result, num1, num2;
    printf("enter the num1: ");
    scanf("%f", &num1);
    printf("enter the num2: ");
    scanf("%f", &num2);

    printf("choose the operator (+,-,*,/): ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case '+':
        result = num1 + num2;
        printf("result =%f", result);
        break;
    case '-':
        result = num1 - num2;
        printf("result =%f", result);
        break;
    case '*':
        result = num1 * num2;
        printf("result =%f", result);
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("result=%f", result);
        }
        else
        {
            printf("invalid division!");
        }
        break;
    default:
        printf("invalid choice!");
    }

    return 0;
}
