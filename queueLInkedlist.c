#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

struct Node *newNode(int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q)
{
    int tmp;
    printf("Enter the value to be inserted : ");
    scanf("%d", &tmp);
    struct Node *temp = newNode(tmp);

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(struct Queue *q)
{
    if (q->front == NULL)
        return;

    struct Node *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void display(struct Queue *q)
{
    struct Node *tmp = q->front;
    printf("Elements in queue are : ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->key);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();

    int choice;
    while (1)
    {
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display  \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue(q);
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }

    return 0;
}