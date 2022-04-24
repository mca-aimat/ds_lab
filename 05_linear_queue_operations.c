#include <stdio.h> 
#include<stdlib.h> 

int f,r,front,rear; 
int n,q[50];

void main()
{
    int a, item, x, i, loc = 0, c = 0, z;
    char k;
    f = r = -1;
    printf("\n Enter the size : ");
    scanf("%d", &n);
    if (n > 25)
        printf("\n Queue overflow");
    else
        printf("\n Enter the elements : ");
    while (r < n)
    {
        if (r == -1)
            r = 0;
        scanf("%d", &q[r]);
        r++;
    }
    rear--;
    printf("\n menu\n 1. insert\n 2.delete\n 3. print\n 4. exit");
    do
    {
        printf("\n enter your choice : ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\n enter the item : ");
            scanf("%d", &item);
            if (rear > 25)
                printf("\n queue overflow");
            else
            {
                rear++;
                q[r] = item;
            }
            printf("\n queue is: ");
            for (i = f + 1; i <= r; i++)
                printf("%d\t", q[i]);
            break;
        case 2:
            f++;
            if (f == r)
                printf("\n queue underflow");
            else
            {
                f++;
                x = q[front];
                c++;
            }
            if (f != r)
            {
                printf("deleted item is %d\n", x);
                printf("queue is : ");
                for (i = f; i <= r; i++)
                    printf("%d\t", q[i]);
            }
            else
                printf("queue is empty");
            break;
        case 3:
            if (f != r)
            {
                printf("\n queue is :");
                for (i = f; i <= r; i++)
                    printf("%d\t", q[i]);
            }
            else
                printf("queue is empty");
            break;
        default:
            exit(0);
        }
        printf("\n do you want to continue? if yes-y exit-n : ");
        scanf("%s", &k);
    } while (k == 'y');
}