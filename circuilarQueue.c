#include <stdio.h>
#define SIZE 3
int arr[SIZE];
int front = -1;
int rear = -1;
void enqueue(int item)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == SIZE - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    arr[rear] = item;
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    printf("Element deleted from queue is : %d\n", arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == SIZE - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= SIZE - 1)
        {
            printf("%d ", arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
int main()
{
    int choice, item;
    do
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
    return 0;
}