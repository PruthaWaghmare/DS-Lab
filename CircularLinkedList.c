#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg() {
    struct node *n,*t;
    n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&n->data);

    if(head == NULL) {
        head = n;
        n->next = head;
    }
    else {
        t = head;
        while(t->next != head)
            t = t->next;
        n->next = head;
        t->next = n;
        head = n;
    }
}

void insertEnd() {
    struct node *n,*t;
    n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&n->data);

    if(head == NULL) {
        head = n;
        n->next = head;
    }
    else {
        t = head;
        while(t->next != head)
            t = t->next;
        t->next = n;
        n->next = head;
    }
}

void deleteBeg() {
    struct node *t,*last;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    last = head;
    while(last->next != head)
        last = last->next;

    t = head;
    head = head->next;
    last->next = head;
    free(t);
}

void deleteEnd() {
    struct node *t,*p;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    t = head;
    while(t->next != head) {
        p = t;
        t = t->next;
    }

    p->next = head;
    free(t);
}

void forward() {
    struct node *t;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    t = head;
    do {
        printf("%d -> ",t->data);
        t = t->next;
    } while(t != head);

    printf("HEAD\n");
}

int main() {
    int ch;

    do {
        printf("\n1.Insert Begin  2.Insert End");
        printf("\n3.Delete Begin  4.Delete End");
        printf("\n5.Forward  6.Backward  7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeg(); break;
            case 4: deleteEnd(); break;
            case 5: forward(); break;
            case 6:
                printf("Backward traversal not possible\n");
                break;
            case 7: break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 7);

    return 0;
}