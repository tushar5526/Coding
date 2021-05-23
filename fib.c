#include <stdio.h>


int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int pop()
{
    int data;

    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{

    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

int main(){
    int n,tmp;
    printf("enter the term : ");
    scanf("%d",&n);

    tmp = n;
    printf("%d ",n);
    //insert initial two elements in stack
    push(0);
    push(1);

    //decrease nth term by 2
    n -= 1;

    while(n > 0){
        int s = pop();
        int f = pop();
        int next = f + s;
        push(s);
        push(next);
        --n;
    }

    printf("\n %dth term in sequence is %d ",tmp,pop());
    return 0;
}
