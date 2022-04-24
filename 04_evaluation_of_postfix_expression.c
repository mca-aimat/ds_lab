#include <stdio.h>
#include <string.h>

char expr[50], ch;
int stk[100];

void main()
{
    int i, cnt = 0, a, b, res;
    int top = -1;
    printf("Enter your expression : ");
    scanf("%s", expr);
    for (i = 0; i < strlen(expr); i++)
    {
        if (expr[i] >= '0' && expr[i] <= '9')
        {
            top++;
            stk[top] = (int)(expr[i] - 48);
        }
        if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^')
        {
            ch = expr[i];
            a = stk[top];
            stk[top] = '\0';
            top--;
            b = stk[top];
            stk[top] = '\0';
            top--;
            switch (ch)
            {
            case '+':
                res = b + a;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = b * a;
                break;
            case '/':
                res = b / a;
                break;
            case '^':
                res = b ^ a;
                break;
            }
            top++;
            stk[top] = res;
        }
    }
    printf(" The result of expression %s = %d \n\n", expr, stk[top]);
}