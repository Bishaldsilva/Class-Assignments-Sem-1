#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL; 
    newNode->right = NULL;

    return newNode; 
}

struct node *createTree(struct node *root){
    int n;
    printf("Enter the value...\n");
    scanf("%d",&n);
    if(n == -1){
        return NULL;
    }

    root = createNode(n);
    printf("Enter the value at the left of %d\n",n);
    root->left = createTree(root->left);
    printf("Enter the value at the right of %d\n",n);
    root->right = createTree(root->right);

    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int op;
    struct node *root = NULL;

    printf("1 to create the tree(max 100 elements are allowed)\n2 to display the tree in inorder\n3 to display the tree in preorder\n4 to display the tree in postorder\n");
    while(1){
        printf("Enter your operation...\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            root = createTree(root);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
}