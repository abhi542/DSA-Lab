#include <stdio.h>
#include <stdlib.h>

void insert(int[]);
void display(int[]);
void insertpos(int[]);
void delpos(int[]);
int n;
int main()
{
    int a[100], ch, i;
    printf("Menu\n");
    printf("1.Create Array 2.Display 3.Insert at pos 4.Delete at pos 5.Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(a);
            break;

        case 2:
            display(a);
            break;

        case 3:
            insertpos(a);
            break;

        case 4:
            delpos(a);
            break;

        case 5:
            break;

        default:
            printf("INVALID CHOICE!\n");
        }
    } while (ch != 5);
}

void insert(int a[])
{
    int i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter array elements ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int a[])
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
}

void insertpos(int a[])
{
    int pos, ele, i;
    printf("Enter the position ");
    scanf("%d", &pos);
    printf("Enter the element ");
    scanf("%d", &ele);

    for (i = n; i >= pos; i--) //travel from n to pos
        a[i] = a[i - 1];
    a[pos - 1] = ele;
    n++;
}

void delpos(int a[])
{
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);
    n--;
    for (i = pos - 1; i < n; i++) // travel from pos to n
        a[i] = a[i + 1];
}