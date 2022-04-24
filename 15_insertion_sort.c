#include <stdio.h>
void main()
{
    int a[100], number, i, j, temp;
    printf("\nEnter the number of elements :");
    scanf("%d", &number);
    printf("\n Enter the Elements :\n");
    for (i = 0; i < number; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= number - 1; i++)
    {
        for (j = i; j > 0 && a[j - 1] > a[j]; j--)
        {
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }
    printf("\n Elements after Insertion Sort : ");
    for (i = 0; i < number; i++)
    {
        printf(" %d \t", a[i]);
    }
    printf("\n");
}