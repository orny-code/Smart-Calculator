#include <stdio.h>

int main()
{
    int n, i;
    float num[100], result;
    char op[100];

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    // Input first number
    printf("Enter first number: ");
    scanf("%f", &num[0]);

    // Input remaining numbers and operators
    for(i = 1; i < n; i++)
    {
        printf("Enter operator (+, -, *, /): ");
        scanf(" %c", &op[i - 1]);

        switch(op[i - 1])
        {
            case '+':
            case '-':
            case '*':
            case '/':
                break;

            default:
                printf("Invalid operator!\n");
                return 0;
        }

        if(i == 1)
            printf("Enter second number: ");
        else if(i == 2)
            printf("Enter third number: ");
        else
            printf("Enter number %d: ", i + 1);

        scanf("%f", &num[i]);
    }

    // Print expression
    printf("\nExpression: ");

    for(i = 0; i < n; i++)
    {
        printf("%.0f", num[i]);

        if(i < n - 1)
            printf("%c", op[i]);
    }

    // Apply BODMAS (* and / first)
    for(i = 0; i < n - 1; i++)
    {
        switch(op[i])
        {
            case '*':
                num[i + 1] = num[i] * num[i + 1];
                num[i] = 0;
                op[i] = '+';
                break;

            case '/':
                if(num[i + 1] == 0)
                {
                    printf("\nDivision by zero is not allowed!\n");
                    return 0;
                }

                num[i + 1] = num[i] / num[i + 1];
                num[i] = 0;
                op[i] = '+';
                break;
        }
    }

    // Final calculation
    result = num[0];

    for(i = 0; i < n - 1; i++)
    {
        switch(op[i])
        {
            case '+':
                result = result + num[i + 1];
                break;

            case '-':
                result = result - num[i + 1];
                break;
        }
    }

    printf("\nResult = %.2f\n", result);

    return 0;
}
