#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node)); 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL;
    return n; 
}
struct node * insert(struct node * root,int data){
	 if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
    
}

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct  node* root){
    if(root!=NULL){
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
    }
}
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int height (struct node *node)
{
  if (node == NULL)
    return 0;
  else
    {

      int leftHeight = height (node->left);
      int rightHeight = height (node->right);

      if (leftHeight > rightHeight)
	return (leftHeight + 1);
      else
	return (rightHeight + 1);
    }
}
int find_max_path_length(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    int max_path_length = left_height + right_height + 2;
    int left_max_path_length = find_max_path_length(root->left);
    int right_max_path_length = find_max_path_length(root->right);
    if (left_max_path_length > max_path_length) {
        max_path_length = left_max_path_length;
    }
    if (right_max_path_length > max_path_length) {
        max_path_length = right_max_path_length;
    }
    return max_path_length;
}

void find_leaf_node(struct node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        find_leaf_node(root->left);
        find_leaf_node(root->right);
    }
}



int main(){
	struct node* root=NULL;
	int choice,n;
	while(1){
		printf("\n\t1 to create tree\n");
		printf("\n\t2 for preorder traversal\n");
		printf("\n\t3 for postorder traversal\n");
		printf("\n\t4 for inorder traversal\n");
		printf("\n\t5 to find height of tree\n");
		printf("\n\t6 to max path length\n");
		printf("\n\t7 to find leaf node\n");
		printf("enter choice:");
		scanf("%d",&choice);
	    switch(choice){
		case 1:
			root = NULL;
            int elements;
            printf("enter the number how many element create a binary search tree: ");
            scanf("%d",&n);
            printf("\n enter the number");
            for(int i=1;i<=n;i++){
            scanf("%d",&elements);
            root=insert(root,elements);
            }
            break;
         
		case 2:
			preOrder(root);
			break;
		case 3:
			postOrder(root);
			break;
		case 4:
		    inOrder(root);   	
			break;
	    case 5:
		    printf("height of tree is %d",height(root));
			break;
		case 6:		
		    printf("\nMaximum path length: %d\n",find_max_path_length(root));
			break;
		case 7:
			printf("\nLeaf nodes: ");
            find_leaf_node(root);
            break;			
		default:
		    printf("Incorrect Choice. Try Again \n");
			continue;	
	    }

}
}
