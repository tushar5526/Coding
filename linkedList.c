#include <stdlib.h>
#include <stdio.h>

struct node
{
    int info;
    struct node *next;
};
struct node *start = NULL;

void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty:\n");
        return;
    }
    else
    {
        ptr = start;
        printf("\nThe List elements are:\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->info);
            ptr = ptr->next;
        }
    }
}
void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void delete_begin()
{
    struct node *ptr;
    if (ptr == NULL)
    {
        printf("\nList is Empty:\n");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\nThe deleted element is :%d\t", ptr->info);
        free(ptr);
    }
}

void reverse(){
    struct node *next = NULL, *curr = start, *prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}

int main()
{
    int choice;
    while (1)
    {

        printf("\n                MENU                             \n");
        printf("\n 1.Create     \n");
        printf("\n 2.Display    \n");
        printf("\n 3.Insert at the beginning    \n");
        printf("\n 4.Delete from beginning      \n");
        printf("\n 5.Reverse      \n");
        printf("\n 6.Exit       \n");
        printf("\n--------------------------------------\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            reverse();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("n Wrong Choice:n");
            break;
        }
    }
    return 0;
}