#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void display(struct node *head){
    struct node *s;
    s=head;
    while(s!=NULL){
        printf("\t%d ", s->data);
        s=s->next;
    }
    printf("\n");
}
void intersection(struct node *head1, struct node *head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->data>head2->data)
        head2=head2->next;
        else if(head1->data<head2->data)
        head1=head1->next;
        else{
            printf("\t%d ", head1->data);
            head1=head1->next;
            head2=head2->next;
        }
    }
    printf("\n");
}
void unionLL(struct node *head1, struct node *head2){
    while(head1!=NULL && head2!=NULL){
         if(head1->data>head2->data){
             printf("\t%d ", head2->data);
             head2=head2->next;
         }
        else if(head1->data<head2->data){
            printf("\t%d ", head1->data);
             head1=head1->next;
        }
        else{
            printf("\t%d ", head1->data);
            head1=head1->next;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
         printf("\t%d ", head1->data);
         head1=head1->next;
    }
      while(head2!=NULL){
         printf("\t%d ", head2->data);
         head2=head2->next;
    }
    printf("\n");
}
int main(){
    struct node *head1=NULL, *head2=NULL, *ptr, *temp;
    int ch, d, n, i;
    while(1){
     printf("1. First Linked List\n");
     printf("2. Second Linked List\n");
     printf("3. Display first Linked List\n");
     printf("4. Display second linked list\n");
     printf("5. Intersection of linked List\n");
     printf("6. Union of two Linked List\n");
     printf("7. Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &ch);
     switch(ch){
         case 1:
         printf("Enter the no of terms: ");
         scanf("%d", &n);
         for( i=1;i<=n;i++){
             printf("Enter the data to be inserted: ");
             scanf("%d", &d);
             ptr=(struct node *)malloc(sizeof(struct node));
             ptr->data=d;
             ptr->next=NULL;
             if(head1==NULL){
                 head1=ptr;
                 temp=head1;
             }
             temp->next=ptr;
             temp=temp->next;
         }
         break;
         case 2:
         printf("Enter the no of terms: ");
         scanf("%d", &n);
         for( i=1;i<=n;i++){
             printf("Enter the data to be inserted: ");
             scanf("%d", &d);
             ptr=(struct node *)malloc(sizeof(struct node));
             ptr->data=d;
             ptr->next=NULL;
             if(head2==NULL){
                 head2=ptr;
                 temp=head2;
             }
             temp->next=ptr;
             temp=temp->next;
         }
        break;
        case 3: display(head1);
        break;
        case 4: display(head2);
        break;
        case 5: intersection(head1, head2);
        break;
        case 6: unionLL(head1, head2);
        break;
        case 7: exit(0);
        }
        
    }
}
