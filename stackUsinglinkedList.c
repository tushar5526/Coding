#include <stdlib.h>
#include <stdio.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

void push()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOverflow\n");
        exit(0);
    }
    printf("\nEnter the data value :\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        start = temp;
        temp->next = ptr;
    }
}
void peak()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        printf("\nPeak is %d\n",start->info);
    }
}

void pop()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nStack is Empty or Underflow:\n");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\nThe popped element is :%d\t", ptr->info);
        free(ptr);
    }
}

int main()
{
    int choice;
    while (1)
    {

        printf("\n                MENU                             \n");
        printf("\n 1.Push     \n");
        printf("\n 2.Pop    \n");
        printf("\n 3.Peak    \n");
        printf("\n 4.Exit       \n");
        printf("\n--------------------------------------\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peak();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("n Wrong Choice:n");
            break;
        }
    }
    return 0;
}