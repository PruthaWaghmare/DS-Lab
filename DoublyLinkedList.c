#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* 1. Insertion at Beginning */
void insert_begin()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prev = newnode;
    }

    head = newnode;

    printf("Node inserted at beginning.\n");
}

/* 2. Insertion at Ending */
void insert_end()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at ending.\n");
}

/* 3. Deletion at Beginning */
void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

/* 4. Deletion at Ending */
void delete_end()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev == NULL)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

/* 5. Forward Traversing */
void forward()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* 6. Backward Traversing */
void backward()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Backward List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n----- DOUBLY LINKED LIST -----\n");
        printf("1. Insertion at Beginning\n");
        printf("2. Insertion at Ending\n");
        printf("3. Deletion at Beginning\n");
        printf("4. Deletion at Ending\n");
        printf("5. Forward Traversing\n");
        printf("6. Backward Traversing\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                delete_end();
                break;

            case 5:
                forward();
                break;

            case 6:
                backward();
                break;

            case 7:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}