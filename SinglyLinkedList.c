#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBeg() {
    struct node *n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&n->data);
    n->next = head;
    head = n;
}

void insertEnd() {
    struct node *n,*t;
    n = malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&n->data);
    n->next = NULL;

    if(head == NULL)
        head = n;
    else {
        t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void deleteBeg() {
    struct node *t;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    t = head;
    head = head->next;
    free(t);
}

void deleteEnd() {
    struct node *t,*p;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    t = head;
    while(t->next != NULL) {
        p = t;
        t = t->next;
    }
    p->next = NULL;
    free(t);
}

void forward() {
    struct node *t = head;
    while(t != NULL) {
        printf("%d -> ",t->data);
        t = t->next;
    }
    printf("NULL\n");
}

void backward(struct node *t) {
    if(t == NULL) return;
    backward(t->next);
    printf("%d -> ",t->data);
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
            case 6: backward(head); printf("NULL\n"); break;
            case 7: break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 7);

    return 0;
}