#include<stdio.h>

int stack[100];
int top = -1;

void push(int val){
    if(top == 99){
        printf("Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop(){
    if(top == -1){
        printf("Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peak(){
    if(top == -1){
        printf("underflow\n");
        return -1;
    }
    return stack[top];
}

int main(){
    while(1){
        printf("1: push \n2: pop \n3: peak\n4: exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the element to pushed\n");
            int tmp;
            scanf("%d",&tmp);
            push(tmp);
        }
        else if(ch == 2){
            printf("Element poppped is %d\n", pop());
        }
        else if(ch == 3){
            printf("peak element is %d\n",peak());
        }
        else if(ch == 4){
            break;
        }
        else{
            printf("invalid choice enter again \n");
        }
    }
    return 0;
}