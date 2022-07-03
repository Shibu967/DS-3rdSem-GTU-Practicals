#include <stdio.h>
void swap(int *, int *);
int main()
{
    int a, b;
    printf("Enter a Value of A : ");
    scanf("%d", &a);
    printf("Enter a Value of B : ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("Old Values:");
    printf("A=%d  B=%d \n", a, b);
}
void swap(int *p, int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
    printf("New Values After Swap :");
    printf("A=%d B=%d", *p, *q);
}