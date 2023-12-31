#include<stdio.h>
#include<stdlib.h>
int n, top=-1, arr[30];

void push(int item){
    if(top==n-1)
    printf("Stack Overflow\n");
    else
    arr[++top]=item;
}

int pop(){
    if(top==-1)
    printf("Stack Underflow!!\n");
    else
    return arr[top--];
}
void display(){
    if(top==-1)
    printf("No element to display");
    else{
        for(int i=0;i<=top;i++){
            printf("\t%d", arr[i]);
        }
    }
    printf("\n");
}
int main(){
    int ch, item;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    while(1){
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Element\n");
        printf("4. Exit\n");
        printf("ENter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\n Enter an element: ");
            scanf("%d", &item);
            push(item);
            break;
            case 2: printf("The element popped: %d\n", pop());
            break;
            case 3: display();
            break;
            case 4: exit(0);
        }
    }
}
