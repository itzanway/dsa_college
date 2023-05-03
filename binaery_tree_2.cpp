#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* creatnode(int data){
  struct node* n=(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  return n;
}
struct node* insert(struct node * root,int data){
    if(root==NULL){
        return creatnode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
    
}
void preorder(struct node* root){
    if(root==NULL){
        return ;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
void inorder(struct node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
int main(){
    struct node* root=NULL;
    int  n;
    int choice;
    do{
        printf("1.create a binary search  tree\n");
        printf("2.traversal preorder\n");
        printf("3.traversal postorder\n");
        printf("4.traversal inorder\n");
        printf("5.exit 0\n");
        printf("enter the choice ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                 root=NULL;
                 int elements;
                 printf("enter the number how many element cretae a binary search tree ");
                 scanf("%d",&n);
                 printf("enter the number");
                 for(int i=1;i<=n;i++){
                 scanf("%d",&elements);
                 root=insert(root,elements);
            }
                break;
            case 2:
                printf("preorder traversal\n");
                preorder(root);
                break;
            case 3:
                printf("postorder traversal\n");
                postorder(root);
                break;
            case 4:
                printf("inorder traversal\n");
                inorder(root);
                break;
            case 5:
                exit(0);
                break;
        }

    }
            while(choice!=5);
       return 0;
}
