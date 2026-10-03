#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element into stack
void push(int value)
{
    stack[++top] = value;
}

// Pop element from stack
int pop()
{
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i, a, b, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        // If operand, push it into stack
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        // If operator, pop two operands
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
