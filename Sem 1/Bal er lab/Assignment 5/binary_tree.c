#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int val){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root,int val){
    if(root == NULL){
        root = createNode(val);
    } else if(val > root->data){
        root->right = insert(root->right,val);
    }else{
        root->left = insert(root->left,val);
    }
    return root;
}

struct node *createTree(struct node *root){
    int val;
    printf("Enter the value (-1 to exit) \n");
    scanf("%d",&val);
    if(val == -1){
        return NULL;
    }

    root = createNode(val);
    printf("Enter a value at the left of %d \n",val);
    root->left = createTree(root->left);
    printf("Enter a value at the right of %d \n",val);
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
    struct node *root = NULL;
    int op;

    printf("1 to create the tree\n2 to display the tree in inorder\n3 to display the tree in preorder\n4 to display the tree in postorder\n");
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