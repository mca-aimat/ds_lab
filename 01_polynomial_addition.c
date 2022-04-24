#include <stdio.h>

void main()
{
    int fir[10], sec[10], res[20], m, n;
    int i = 0, k = 0, j = 0;
    printf("\n Enter the limit of first polynomial: ");
    scanf("%d", &m);
    printf("\n Enter the limit of second polynomial: ");
    scanf("%d", &n);
    printf("\n Enter the coefficent and exponent of first polynomial: ");
    for (i = 0; i < 2 * m - 1; i = i + 2)
    {
        scanf("%d %d", &fir[i], &fir[i + 1]);
    }
    printf("\n Enter the coefficent and exponent of second polynomial: ");
    for (j = 0; j < 2 * n - 1; j = j + 2)
    {
        scanf("%d %d", &sec[j], &sec[j + 1]);
    }
    printf("\n The first polynomial is : ");
    for (i = 0; i < 2 * m - 2; i = i + 2)
    {
        printf("%dx^%d+ ", fir[i], fir[i + 1]);
    }
    printf("%dx^%d ", fir[i], fir[i + 1]);
    printf("\n The second polynomial is : ");
    for (j = 0; j < 2 * n - 2; j = j + 2)
    {
        printf("%dx^%d+ ", sec[j], sec[j + 1]);
    }
    printf("%dx^%d ", sec[j], sec[j + 1]);
    for (i = 0, j = 0, k = 0; (i < 2 * m - 1) && (j < 2 * n - 1);)
    {
        if (fir[i + 1] == sec[j + 1])
        {
            res[k] = fir[i] + sec[j];
            res[k + 1] = fir[i + 1];
            i = i + 2;
            j = j + 2;
            k = k + 2;
        }
        else if (fir[i + 1] < sec[j + 1])
        {
            res[k] = sec[j];
            res[k + 1] = sec[j + 1];
            j = j + 2;
            k = k + 2;
        }
        else if (fir[i + 1] > sec[j + 1])
        {
            res[k] = fir[i];
            res[k + 1] = fir[i + 1];
            k = k + 2;
            i = i + 2;
        }
    }
    for (; i < 2 * m - 1; i = i + 2)
    {
        res[k] = fir[i];
        res[k + 1] = fir[i + 1];
        k = k + 2;
    }
    for (; j < 2 * n - 1; j = j + 2)
    {
        res[k] = sec[j];
        res[k + 1] = sec[j + 1];
        k = k + 2;
    }
    n = k;
    printf("\n After addition : ");
    for (i = 0; i < k; i = i + 2)
    {
        printf(" %dx^%d", res[i], res[i + 1]);
    }
}