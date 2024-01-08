#include<stdio.h>
#include<stdlib.h>
int front=-1, rear=-1, a[30],n;
void enqueue(int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        a[rear]=item;
    }
    else{
        rear=(rear+1)%n;
        a[rear]=item;
    }
}
int dequeue(){
    int t;
    t=a[front];
    if(front==rear){
        front=rear=-1;
    }
    else 
    front=(front+1)%n;
    return t;
}
void display(){
    int i;
    i=front;
    while(i!=rear){
        printf("\t%d", a[i]);
        i=(i+1)%n;
    }
    printf("\t%d", a[i]);
}
int main(){
    int ch, item;
    printf("Enter the no of elements in the array: ");
    scanf("%d", &n);
    while(200){
        printf("\n1. Enqueue Element in the array");
        printf("\n2. Dequeue Element from the array");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: 
            if((rear+1)%n==front)
            printf("Queue Full. Insertion not possible");
            else{
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
            }
            break;
            case 2: 
            if(front==-1 && rear ==-1){
                printf("Queue Empty. Deletion not possible");
            }
            else{
                printf("The deleted element: %d", dequeue());
            }
            break;
            case 3: display();
            break;
            case 4: exit(0);
        }//switch
    }//while
}// main
