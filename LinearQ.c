#include<stdio.h>
#include<stdlib.h>
int front=-1, rear=-1, a[30],n;
void enqueue(int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        a[rear]=item;
    } 
    else{
        a[++rear]=item;
    }
}
int dequeue(){
    return a[front++];
}
void display(){
    int i; 
    for(i=front; i<=rear; i++){
        printf("\t%d", a[i]);
    }
}
int main(){
    int n, ch, item;
    printf("Enter the no of elements in the array: ");
    scanf("%d", &n);
    while(1){
        printf("\n1. Enqueue Element in the array");
        printf("\n2. Dequeue Element from the array");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: if(rear==n-1)
            printf("Queue Full. Insertion not possible");
            else{
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
            }
            break;
            case 2: if(front==-1 && rear==-1 || front>rear)
            printf("Queue is empty. Deletion not possible");
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
