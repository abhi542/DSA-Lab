#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void insert(int *f, int *r, int q[MAX]);
void delete (int *f, int *r, int q[MAX]);
void display(int *f, int *r, int q[MAX]);

int main()
{
    int f = -1, r = -1, ch;
    int q[MAX];

    do
    {
        printf("1. Inser 2.Delete 3.Display 4.Exit\n");
        printf("enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(&f, &r, q);
            break;
        case 2:
            delete (&f, &r, q);
            break;
        case 3:
            display(&f, &r, q);
            break;
        default:
            exit(0);
        }
    } while (ch != 4);
}

void insert(int *f, int *r, int q[MAX])
{
    int item;
    if (*f == (*r + 1) % MAX)
    {
        printf("Queue is Full\n");
        return;
    }
    printf("Enter item: ");
    scanf("%d", &item);
    *r = (*r + 1) % MAX;
    q[*r] = item;
    if (*f == -1)
        *f = *f + 1;
}

void delete (int *f, int *r, int q[MAX])
{
    if (*f == -1)
    {
        printf("Underflow\n");
        return;
    }
    printf("deleted item is %d", q[*f]);
    *f = (*f + 1) % MAX;
}

void display(int *f, int *r, int q[MAX])
{
    int i;
    if (*f == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: \n");

    for (i = *f; i <= *r; i++)
        printf("%d\n", q[i]);

    if (*f > *r)
    {
        for (i = *f; i < MAX; i++)
            printf("%d\n", q[i]);
        for (i = 0; i < *f; i++)
            printf("%d\n", q[i]);
    }
}