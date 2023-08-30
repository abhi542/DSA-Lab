#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX 50

int top = 0;
int s[MAX];

int main()
{
    char a[MAX];
    int res;
    int op1, op2, i = 0;
    void push(int ele);
    int pop();
    printf("Enter suffix expression:");
    gets(a);
    while (a[i] != '\0')
    {
        if (isdigit(a[i]))
            push(a[i] - '0');

        else
        {
            op2 = pop();
            op1 = pop();

            switch (a[i])
            {
            case '+':
                res = op1 + op2;
                push(res);
                break;

            case '-':
                res = op1 - op2;
                push(res);
                break;

            case '*':
                res = op1 * op2;
                push(res);
                break;

            case '/':
                res = op1 / op2;
                push(res);
                break;

            case '^':
                res = pow(op1, op2);
                push(res);
                break;

            case '%':
                res = op1 % op2;
                push(res);
                break;

            default:
                printf("Invalid expression\n");
            }
        }
        i = i + 1;
    }
    printf("Value is %d \n", res);
}

void push(int ele)
{
    if (top > 49)
    {
        printf("Overflow\n");
        return;
    }
    s[top] = ele;
    top++;
}

int pop()
{
    if (top <= 0)
        printf("Invalid expression\n");
    else
        return (s[--top]);

    return 0;
}