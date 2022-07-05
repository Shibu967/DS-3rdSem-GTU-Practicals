#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr, *rptr;
} * l, *r, *l1, *r1;
void doubins(int);
void doubins1(int);
void display();
void display1();
void merge();
int chk;
void main()
{
    int ch, x;
    l = NULL;
    r = NULL;
    l1 = NULL;
    r1 = NULL;
    do
    {
        printf("\n\n [1] Create First Doubly Linked List");
        printf("\n [2] Create Second Doubly Linked List");
        printf("\n [3] Merge both list");
        printf("\n [4] Exit");
        printf("\n\n\tEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tEnter Element: ");
            scanf("%d", &x);
            doubins(x);
            display();
            break;
        case 2:
            printf("\n\tEnter Element: ");
            scanf("%d", &x);
            doubins1(x);
            display1();
            break;
        case 3:
            merge();
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n\tInvalid Choice.\n\tTry Again.");
        }
    } while (ch != 3);
}
void doubins(int x)
{
    struct node *New, *temp;
    int sc;
    New = (struct node *)malloc(sizeof(struct node));
    New->info = x;
    if (l == NULL)
    {
        New->lptr = NULL;
        New->rptr = NULL;
        l = New;
        r = New;
        return;
    }
    if (x <= l->info)
    {
        New->lptr = NULL;
        New->rptr = l;
        l->lptr = New;
        l = New;
        return;
    }
    temp = l;
    while (temp->rptr != NULL && temp->info < x)
    {
        temp = temp->rptr;
    }
    if (temp->info < x)
    {
        New->rptr = NULL;
        New->lptr = r;
        r->rptr = New;
        r = New;
        return;
    }
    New->lptr = temp->lptr;
    New->rptr = temp;
    temp->lptr = New;
    New->lptr->rptr = New;
}
void doubins1(int x)
{
    struct node *New, *temp;
    int sc;
    New = (struct node *)malloc(sizeof(struct node));
    New->info = x;
    if (l1 == NULL)
    {
        New->lptr = NULL;
        New->rptr = NULL;
        l1 = New;
        r1 = New;
        return;
    }
    if (x <= l1->info)
    {
        New->lptr = NULL;
        New->rptr = l1;
        l1->lptr = New;
        l1 = New;
        return;
    }
    temp = l1;
    while (temp->rptr != NULL && temp->info < x)
    {
        temp = temp->rptr;
    }
    if (temp->info < x)
    {
        New->rptr = NULL;
        New->lptr = r1;
        r1->rptr = New;
        r1 = New;
        return;
    }
    New->lptr = temp->lptr;
    New->rptr = temp;
    temp->lptr = New;
    New->lptr->rptr = New;
}
void display()
{
    struct node *temp;
    if (l == NULL)
        printf("\n\n\tDoubly Linked List is Empty.");
    else
    {
        printf("\n\nDoubly Linked List:\n\n\n");
        printf("-----------------------------\n");
        printf("l = %u\n\n", l);
        printf("-----------------------------\n");
        temp = l;
        while (temp != NULL)
        {
            printf("[%u|%u|%d|%u]->", temp, temp->lptr, temp->info, temp->rptr);
            temp = temp->rptr;
        }
        printf("NULL");
        printf("\n\nr= %u", r);
    }
}
void display1()
{
    struct node *temp;
    if (l1 == NULL)
        printf("\n\tDoubly Linked List is Empty.");
    else
    {
        printf("\n\nDoubly Linked List:\n\n\n");
        printf("l1 = %u\n\n", l1);
        temp = l1;
        while (temp != NULL)
        {
            printf("[%u|%u|%d|%u]->", temp, temp->lptr, temp->info, temp->rptr);
            temp = temp->rptr;
        }
        printf("NULL");
        printf("\n\nr1= %u", r1);
    }
}
void merge()
{
    r->rptr = l1;
    l1->lptr = r;
}