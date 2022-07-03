#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n, i, sum = 0;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter Elements of Array : ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum=%d", sum);
    free(ptr);
    return 0;
}