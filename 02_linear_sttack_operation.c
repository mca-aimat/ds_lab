#include <stdio.h>
#include <stdlib.h>

void pushs();
void pops();
void visit();

int n, top;
int a[25];

void main()
{
    int i, n, c;
    char d;
    printf("Enter the size of the stack : ");
    scanf("%d", &n);
    if (n > 25)
    {
        printf("\n stack overflow");
        exit(0);
    }
    else
        printf("Enter Stack elements :\n");
    for (top = 0; top < n; top++)
        scanf("%d", &a[top]);
    do
    {
        printf("\nMENU \n 1.push\n 2.pop \n 3.traversing\n 4.exit\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            pushs();
            break;
        case 2:
            pops();
            break;
        case 3:
            visit();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid input");
        }
        printf("\nDo you want to continue? Exit-y else-n : ");
        scanf("%s", &d);
    } while (d == 'y');
}
void pushs()
{
    int data, i;
    printf("\nEnter the data : ");
    scanf("%d", &data);
    if (top >= 25)
        printf("stack overflow");
    else
    {
        a[top] = data;
        top++;
    }
    visit(a);
    return;
}
void pops()
{
    int data;
    top = top - 1;
    if (top == 0)
        printf("stack underflow");
    else
    {
        data = a[top];
        printf("\npopped item is %d", data);
    }
    visit(a);
    return;
}
void visit()
{
    printf("\nStack elements are : ");
    for (int i = 0; i < top; i++)
        printf("%d\t", a[i]);
    return;
}