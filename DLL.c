#include <stdio.h>
#include <stdlib.h>

struct node
{
    char ssn[12], name[25], branch[5], desg[10], phone[11];
    int sal;
    struct node *right, *left;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the ssn of the employee : ");
    scanf("%s", newnode->ssn);
    getchar();
    printf("Enter the name of the employee : ");
    //scanf("%s", newnode->name);
    gets(newnode->name);
    getchar();
    printf("Enter the branch of the employee : ");
    scanf("%s", newnode->branch);
    getchar();
    printf("Enter the desg of the employee : ");
    scanf("%s", newnode->desg);
    getchar();
    printf("Enter the salary of the employee : ");
    scanf("%d", &newnode->sal);
    printf("Enter the phone number of the employee : ");
    scanf("%s", newnode->phone);
    return newnode;
}

NODE insertbeg(NODE first)
{
    NODE temp = getnode();
    temp->left = NULL;
    temp->right = first;
    return temp;
}

NODE insertend(NODE first)
{
    NODE temp = getnode();
    temp->left = NULL;
    temp->right = NULL;
    if (first == NULL)
    {
        return temp;
    }
    else if (first->right == NULL)
    {
        first->right = temp;
        temp->left = first;
        return first;
    }
    else
    {
        NODE curr = first;
        while (curr->right != NULL)
        {
            curr = curr->right;
        }
        curr->right = temp;
        temp->left = curr;
        return first;
    }
}

NODE deletefront(NODE first)
{
    if (first == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
        return first;
    }
    else
    {
        NODE temp = first->right;
        printf("Deleted data is of name : %s\n", first->name);
        free(first);
        return temp;
    }
}

NODE deleteend(NODE first)
{
    NODE curr = first;
    if (first == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
        return first;
    }
    else if (first->right == NULL)
    {
        printf("Deleted data is of name : %s\n", curr->name);
        free(curr);
        return NULL;
    }
    else
    {
        NODE p = first;
        while (curr->right != NULL)
        {
            p = curr;
            curr = curr->right;
        }
        p->right = NULL;
        printf("Deleted data is of name : %s\n", curr->name);
        free(curr);
        return first;
    }
}

void display(NODE first)
{
    int count = 0;
    if (first == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
    }
    else
    {
        NODE curr = first;
        printf("ssn\t\tname\t\tBranch\tdesg\t\tsalary\tphone\n");
        while (curr != NULL)
        {
            printf("%-20s%-15s%-5s%-10s%5d\t%-10s\n", curr->ssn, curr->name, curr->branch, curr->desg, curr->sal, curr->phone);
            curr = curr->right;
            count++;
        }
        printf("\nTotal no. of nodes = %d\n", count);
    }
}

int main()
{
    NODE first = NULL;
    int choice, n;
    printf("Enter the no. of employees : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        first = insertend(first);
        printf("\n");
    }
    for (;;)
    {
        printf("Menu\n");
        printf("1.Display\n");
        printf("2.Insert at end\n");
        printf("3.Delete at end\n");
        printf("4.Insert at beginning\n");
        printf("5.Delete at beginning\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            display(first);
            break;

        case 2:
            first = insertend(first);
            break;

        case 3:
            first = deleteend(first);
            break;

        case 4:
            first = insertbeg(first);
            break;

        case 5:
            first = deletefront(first);
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}