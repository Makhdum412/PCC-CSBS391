#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
void createBst(struct node *root, struct node *ptr){
    if(ptr->data<root->data){
        if(root->left==NULL)
        root->left=ptr;
        else createBst(root->left, ptr);
    }
    else{
            if(root->right==NULL)
            root->right=ptr;
        else createBst(root->right, ptr);
    }
  }
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if(root!=NULL){
       printf("%d\t", root->data);
       preorder(root->left);
       preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        printf("%d\t", root->data);
        postorder(root->right);
    }
}
int main(){
    int ch,k;
	struct node *root=NULL,*ptr;
	
	while(1)
	{
		printf("\n1 for insertion into bst");
		printf("\n2 for inorder traversal");
		printf("\n3 for preorder traversal");
		printf("\n4 for postorder traversal");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: 
		      ptr=(struct node *)malloc(sizeof(struct node));
		      printf("Enter the data: ");
		      scanf("%d", &k);
		      ptr->left=NULL;
		      ptr->right=NULL;
		      ptr->data=k;
  		    if(root==NULL)
		      root=ptr;
		      else
		      createBst(root, ptr);
		      break;
		    case 2:
		      inorder(root);
		      break;
		    case 3:
		      preorder(root);
		      break;
		    case 4:
		      postorder(root);
		      break;
		    case 5: exit(0);
		}
	}
}
