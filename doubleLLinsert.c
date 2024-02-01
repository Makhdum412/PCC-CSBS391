#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertLast(){
    struct node *ptr, *s;
    int k;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &k);
    ptr->data=k;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(head==NULL)
    head=ptr;
    else{
        s=head;
        while(s->next!=NULL)
        s=s->next;
        s->next=ptr;
        ptr->prev=s;
    }
}
void insertFirst(){
    struct node *ptr;
    int k;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &k);
    ptr->data=k;
    ptr->next=head;
    ptr->prev=NULL;
    if(head!= NULL)
    head->prev=ptr;
    head=ptr;
}
void insertAfterNodeValue(){
  struct node *ptr, *s, *w;
    int k,b, f=0;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d", &k);
    ptr->data=k;
    ptr->prev=NULL;
    ptr->next=NULL;
    printf("Enter the node value after which to be inserted: ");
    scanf("%d", &b);
        s=head;
        while(s->data!=b){
            s=s->next;
            if(s==NULL){
                f=1;
                break;
            }
        }
        if(f==1){
            printf("Node value does not exist");
            free(ptr);
        }
        else{
            w=s->next;
            s->next=ptr;
            ptr->prev=s;
            ptr->next=w;
            w->prev=ptr;
        }
    }
void display(){
    struct node *s;
    s=head;
    while(s!=NULL){
        printf("%d\t", s->data);
        s=s->next;
    }
    printf("\n");
}
int main(){
    int ch;
    while(1){
        printf("\n1. Insert Last");
        printf("\n2. Insert First");
        printf("\n3. Insert after node value");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insertLast();
            break;
            case 2: insertFirst();
            break;
            case 3: insertAfterNodeValue();
            break;
            case 4: display();
            break;
            case 5: exit(0);
        }
    }
}
