#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr, *rptr;
};

void Insert(struct node *, int);
void Preorder(struct node *);
void Postorder(struct node *);
void Inorder(struct node *);
void Delete(struct node *, int);
struct node *Header;
int main()
{
    int ch, x;
    Header = (struct node *)malloc(sizeof(struct node));
    Header->lptr = Header;
    Header->rptr = Header;
    do
    {
        printf("\n1.Insert a node in a Tree");
        printf("\n2.Preorder Traversal(Recursively)");
        printf("\n3.Postorder Traversal(Recursively)");
        printf("\n4.Inorder Traversal(Recursively)");
        printf("\n5.Delete a node from Binary Search Tree");
        printf("\n6.Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tEnter Element : ");
            scanf("%d", &x);
            Insert(Header, x);
            printf("\n\tInorder Traversal(Recursively)=\n\t");
            printf("\n\t-------------------------------------\n\t");
            Inorder(Header->lptr);
            printf("\n\t-------------------------------------\n\t");
            break;
        case 2:
            printf("\n\tPreorder Traversal(Recursively):\n\t");
            printf("\n\t-------------------------------------\n\t");
            Preorder(Header->lptr);
            printf("\n\t-------------------------------------\n\t");
            break;
        case 3:
            printf("\n\tPostorder Traversal(Recursively):\n\t");
            printf("\n\t-------------------------------------\n\t");
            Postorder(Header->lptr);
            printf("\n\t-------------------------------------\n\t");
            break;
        case 4:
            printf("\n\tInorder Traversal(Recursively):\n\t");
            printf("\n\t-------------------------------------\n\t");
            Inorder(Header->lptr);
            printf("\n\t-------------------------------------\n\t");
            break;
        case 5:
            printf("\n\tEnter Element which u want to Delete: ");
            scanf("%d", &x);
            printf("\n\t-------------------------------------\n\t");
            Delete(Header, x);
            printf("\n\t-------------------------------------\n\t");
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n\t Plz Try Again.");
        }
    } while (6);
}
void Insert(struct node *h, int x)
{
    struct node *New, *parent, *cur;
    New = (struct node *)malloc(sizeof(struct node));
    if (New == NULL)
    {
        printf("\n\tNo Tree Node Available.");
        return;
    }
    New->data = x;
    New->lptr = NULL;
    New->rptr = NULL;
    if (h->lptr == h)
    {
        h->lptr = New;
        return;
    }
    cur = h->lptr;
    parent = h;
    while (cur != NULL)
    {
        if (x < cur->data)
        {
            parent = cur;
            cur = cur->lptr;
        }
        else if (x > cur->data)
        {
            parent = cur;
            cur = cur->rptr;
        }
        else
        {
            printf("\n\t Element Already Exist.\n");
            return;
        }
    }
    if (x < parent->data)
    {
        parent->lptr = New;
        return;
    }
    if (x > parent->data)
    {
        parent->rptr = New;
        return;
    }
    return;
}
void Preorder(struct node *t)
{
    if (t != NULL)
        printf("%d  ", t->data);
    else
    {
        printf("\n\t Empty Tree.");
        return;
    }
    if (t->lptr != NULL)
        Preorder(t->lptr);
    if (t->rptr != NULL)
        Preorder(t->rptr);
    return;
}
void Postorder(struct node *t)
{
    if (t == NULL)
    {
        printf("\n\t Empty Tree.");
        return;
    }
    Postorder(t->lptr);
    Postorder(t->rptr);
    printf("%d  ", t->data);
    return;
}
void Inorder(struct node *t)
{
    if (t == NULL)
    {
        printf("\n\t Empty Tree.");
        return;
    }
    if (t->lptr != NULL)
        Inorder(t->lptr);
    printf("%d  ", t->data);
    if (t->rptr != NULL)
        Inorder(t->rptr);
    return;
}
void Delete(struct node *h, int x)
{
    int found;
    char d;
    struct node *cur, *parent, *pred, *suc, *q;
    if (h->lptr == h)
    {
        printf("\n\t Empty Tree.");
        return;
    }
    parent = h;
    cur = h->lptr;
    d = 'L';
    found = 0;
    while (!found && cur != NULL)
    {
        if (x == cur->data)
            found = 1;
        else if (x < cur->data)
        {
            parent = cur;
            cur = cur->lptr;
            d = 'L';
        }
        else
        {
            parent = cur;
            cur = cur->rptr;
            d = 'R';
        }
    }
    if (!found)
    {
        printf("\n\t Node is not found.");
        return;
    }
    if (cur->lptr == NULL)
        q = cur->rptr;
    else
    {
        if (cur->rptr == NULL)
            q = cur->lptr;
        else
        {
            suc = cur->rptr;
            if (suc->lptr == NULL)
            {
                suc->lptr = cur->lptr;
                q = suc;
            }
            else
            {
                pred = cur->rptr;
                suc = pred->lptr;
                while (suc->lptr != NULL)
                {
                    pred = suc;
                    suc = pred->lptr;
                }
                pred->lptr = suc->rptr;
                suc->lptr = cur->lptr;
                suc->rptr = cur->rptr;
                q = suc;
            }
        }
    }
    if (d == 'L')
        parent->lptr = q;
    else
        parent->rptr = q;
    printf("\n\t%d is Deleted.", x);
}