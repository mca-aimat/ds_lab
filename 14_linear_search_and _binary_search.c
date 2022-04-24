#include <stdio.h>
#include <stdlib.h>

void linear();
void binary();

int main()
{
    int choice;
    while (1)
    {
        printf("\n 1.Linear search");
        printf("\n 2.Binary search");
        printf("\n 3.Quit");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linear();
            break;
        case 2:
            binary();
            break;
        case 3:
            exit(0);
        default:
            printf("\nIncorrect Choice\n");
            continue;
        }
    }
    return 0;
}
void linear()
{
    int a[25], item, n, i;
    printf("\n Enter the number of elements : ");
    scanf("%d", &n);
    printf("\n Enter the sorted array : ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n Enter the item to be searched : ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("\n Item found at position %d", i + 1);
            break;
        }
    }
    if (i == n)
        printf("\n Item not found");
}
void binary()
{
    int a[25], beg, item, last, n, num, i, ch, mid, f = 0, flag = 0;
    printf("\nEnter the number of elements in the array : ");
    scanf("%d", &n);
    printf("Enter the sorted array : ");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Item to be searched : ");
    scanf("%d", &item);
    last = n - 1;
    mid = (beg + last) / 2;
    while (beg <= last)
    {
        if (item == a[mid])
        {
            printf("\n Item found at position %d", mid + 1);
            flag = flag + 1;
            break;
        }
        else if (a[mid] > item)
            last = mid - 1;
        else
            beg = mid + 1;
        mid = (beg + last) / 2;
    }
    if (flag == 0)
        printf("\nItem not found");
}