#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *next;
};
struct node *head=NULL;
void enqueuePriority(){
    struct node *ptr, *s, *w;
    int d, p, f=0;
    printf("Enter the data of the queue: ");
    scanf("%d", &d);
    printf("Enter the priority of the queue: ");
    scanf("%d", &p);
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->priority=p;
    ptr->next=NULL;
    if(head==NULL)
    head=ptr;
    else if (ptr->priority>head->priority){
        ptr->next=head;
        head=ptr;
    }
    else{
        w=head;
        s=head->next;
        while(s->priority>ptr->priority){
            if(s->next==NULL){
                s->next=ptr;
                f=1;
                break;
            }
            else{
                w=w->next;
                s=s->next;
            }
        }
        if(f==0){
            w->next=ptr;
            ptr->next=s;
        }
    }
}
int deletePriority(){
    struct node *s; int t;
    s=head;
    t=s->data;
    head=head->next;
    free(s);
    return t;
}
void display(){
    struct node *s;
    s=head;
    while(s!=NULL){
        printf("\t%d", s->data);
        s=s->next;
    }
    printf("\n");
}
int main(){
    int ch;
    while(1){
        printf("!. Insert in a priority queue\n");
        printf("2. Delete from a priority queue\n");
        printf("3. Display\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch){
            case 1: enqueuePriority();
            break;
            case 2: printf("The deleted element: %d\n", deletePriority());
            break;
            case 3: display();
        }
    }
}
