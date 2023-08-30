#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char usn[12];
    char name[25];
    char branch[5];
    int sem;
    float phone;
    struct node *ptr;
};
typedef struct node *NODE;

NODE getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}

NODE insertbeg(NODE first)
{
    char usn[12], name[25], branch[5];
    int sem;
    float phone;
    printf("Enter the students USN : ");
    scanf("%s", usn);
    getchar();
    printf("Enter the name of the student : ");
    scanf("%s", name);
    getchar();
    printf("Enter the branch of student : ");
    scanf("%s", branch);
    printf("Enter the students semester in : ");
    scanf("%d", &sem);
    printf("Enter the phone number of student : ");
    scanf("%f", &phone);
    NODE newnode = getnode();
    strcpy(newnode->usn, usn);
    strcpy(newnode->name, name);
    strcpy(newnode->branch, branch);
    newnode->sem = sem;
    newnode->phone = phone;
    newnode->ptr = first;
    return newnode;
}

NODE deletefront(NODE first)
{
    if (first == NULL)
    {
        printf("Liked List is empty!!\n");
    }
    else if (first->ptr == NULL)
    {
        first = NULL;
        return first;
    }
    else
    {
        NODE temp = first->ptr;
        printf("Deleted data is of Name = %s\n\n", first->name);
        free(first);
        return temp;
    }
}

NODE deleteend(NODE first)
{
    if (first == NULL)
    {
        printf("Linked List is empty!!\n");
        return first;
    }
    else if (first->ptr == NULL)
    {
        printf("Deleted data is of Name = %s\n\n", first->name);
        first = NULL;
        return first;
    }
    else
    {
        NODE curr = first->ptr, prev = first;
        while (curr->ptr != NULL)
        {
            prev = curr;
            curr = curr->ptr;
        }
        printf("Deleted data is of Name = %s\n\n", curr->name);
        free(curr);
        prev->ptr = NULL;
        return first;
    }
}

void display(NODE first)
{
    int count = 0;
    if (first == NULL)
    {
        printf("Linked list is empty!!\n");
    }
    else
    {
        NODE curr = first;
        printf("USN\t\tName\t\tBranch\tSem\tPhone\n");
        while (curr != NULL)
        {
            count++;
            printf("%-20s%-15s%-5s%5d%15.0f\n", curr->usn, curr->name, curr->branch, curr->sem, curr->phone);
            curr = curr->ptr;
        }
        printf("\nThe no. of nodes = %d\n", count);
    }
}

int main()
{
    NODE first = NULL;
    int choice;
    int n, i;
    printf("Enter the amount of student data you want to insert : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        first = insertbeg(first);
    }

    for (;;)
    {
        printf("\nMenue\n");
        printf("1.Insert the student datas\n");
        printf("2.Delete data from front\n");
        printf("3.Delete data from the end\n");
        printf("4.Display the students data\n");
        printf("5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = insertbeg(first);
            break;

        case 2:
            first = deletefront(first);
            break;

        case 3:
            first = deleteend(first);
            break;

        case 4:
            display(first);
            break;

        default:
            exit(0);
        }
    }
    return 0;
}