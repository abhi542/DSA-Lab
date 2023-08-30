#include <stdio.h>
#define MAX_SIZE 3

int top = -1;
int stack[MAX_SIZE];

void push();
void pop();
void display();

int main()
{
    int ch;
    printf("1. Push 2.Pop 3.Display 4.Exit\n");

    do
    {
        printf("Enter your choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("invalid choice");
        }
    } while (ch != 4);
}

void push()
{
    int ele;
    if (top == MAX_SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    printf("Enter element: ");
    scanf("%d", &ele);
    top++;
    stack[top] = ele;
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Deleted element is %d \n", stack[top]);
    top--;
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Stack Elements: \n");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}