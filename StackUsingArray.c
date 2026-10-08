#include <stdio.h>
#define N 5

int stack[N];
int top = -1;

// Push operation
void push()
{
    int x;

    if (top == N - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);
        stack[++top] = x;
        printf("Element pushed successfully.\n");
    }
}

// Pop operation
void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped value = %d\n", stack[top--]);
}

// Peek operation
void peek()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", stack[top]);
}

// Display operation
void display()
{
    int i;

    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");

        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
