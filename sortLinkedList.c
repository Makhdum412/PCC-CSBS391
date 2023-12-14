#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head= NULL;
void insertLast(){
    struct node *ptr, *temp;
    int d;
    printf("Enter the data of the linked list: ");
    scanf("%d", &d);
    
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
     }
   else{
      temp=head;
      while(temp->next!=NULL)
      temp=temp->next;
      temp->next=ptr;
   }
}
void display(){
    struct node *s;
    s=head;
    while(s!=NULL){
        printf("%d ", s->data);
        s=s->next;
    }
    printf("\n");
}
void sort(){
    int temp;
    struct node *s, *s1;
    s=head;
    while(s->next!=NULL){
        s1=s->next;
        while(s1!=NULL){
            if(s->data>s1->data){
                temp=s->data;
                s->data=s1->data;
                s1->data=temp;
            }
            s1=s1->next;
        }
        s=s->next;
    }
}
int main(){
    int ch;
    while(1){
        printf("1. Insert Last\n");
        printf("2. Display\n");
        printf("3. Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insertLast();
            break;
            case 2: display();
            break;
            case 3: sort();
            
     }   }
}
