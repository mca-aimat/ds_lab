#include <stdio.h>
#include <ctype.h>
char st[20];
int i, t = -1;
void add(char x)
{
    st[++t] = x;
}
char del()
{
    if (t == -1)
        return -1;
    else
        return st[t--];
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '$' || x == '#')
        return 3;
}
int main()
{
    char exp[20];
    char e[20], x;
    printf("\nEnter the expression : ");
    scanf("%s", exp);
    printf("\nPostfix expression : ");
    for (i = 0; exp[i] != '\0'; i++)
        e[i] = exp[i];
    i = 0;
    while (e[i] != '\0')
    {
        if (isalnum(e[i]))
            printf("%c", e[i]);
        else if (e[i] == '(')
            add(e[i]);
        else if (e[i] == ')')
        {
            while ((x = del()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(st[t]) >= priority(e[i]))
                printf("%c", del());
            add(e[i]);
        }
        i++;
    }
    while (t != -1)
    {
        printf("%c", del());
    }
    printf("\n\n");
}