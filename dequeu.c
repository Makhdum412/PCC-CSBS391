#include<stdio.h>
int a[30]; 
int front=-1,rear=-1;
void insertFront(int item){
  if(front==-1 && rear==-1){
        front=rear=0;
        a[front]=item;
    }
    else if(front==0)
      printf("Not possible");
    else{
        front--;
        a[front]=item;
    }
}
void insertRear(int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        a[front]=item;
    }
    else{
        rear++;
        a[rear]=item;
    }
}
int deleteFront(){
    int t=a[front];
    if(front==rear){
        front=rear=-1;
        return t;
    }
    else{
        front++;
        
    }
    return t;
}
int deleteRear(){
    int t=a[rear];
    if(front==rear){
        front=rear=-1;
    }
    else
    rear--;
    return t;
}
void display(){
    int i;
    for(i=front; i<=rear; i++){
        printf("\t%d", a[i]);
    }
    printf("\n");
}
int main(){
    int ch, item, n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    while(1){
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display Queue");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
             if(front==0 && rear==n-1)
            printf("Insertion not possible. Queue full");
            else{
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insertFront(item);
            }
            break;
            case 2:
            if(rear==n-1)
            printf("Insertion not possible. Queue full");
            else{
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insertRear(item);
            }
            break;
            case 3: 
            if(front==-1 && rear==-1){
                printf("Deletion not possible. Queue Empty");
            }
            else{
                printf("\nThe deleted item: %d", deleteFront());
            }
            break;
            case 4: 
            if(front==-1 && rear==-1){
                printf("Deletion not possible. Queue Empty");
            }
            else{
                printf("\nThe deleted item: %d", deleteRear());
            }
            break;
            case 5: 
            if(front==-1 && rear==-1){
             printf("Display not possible. Queue Empty");
            } else{
            display();
            }
        }
    }
}
