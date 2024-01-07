#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
    int height;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int max(int a,int b){
    return (a > b)? a:b;
}

int height(struct node *node){
    if(node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct node *node){
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int get_max(struct node *root){
    int val;
    struct node *temp = root;
    while (temp->right){
        temp = temp->right;
    }
    return temp->data;
}

struct node *rightRotation(struct node *a){
    struct node *b = a->left;
    struct node *TR = b->right;

    // rotation
    b->right = a;
    a->left = TR;

    a->height = max(height(a->left),height(a->right)) + 1;
    b->height = max(height(b->left),height(b->right)) + 1;

    return b;
}

struct node *leftRotation(struct node *a){
    struct node *b = a->right;
    struct node *TL = b->left;

    // rotation
    b->left = a;
    a->right = TL;

    a->height = max(height(a->left),height(a->right)) + 1;
    b->height = max(height(b->left),height(b->right)) + 1;

    return b;
}

struct node *insertNode(struct node *root,int val){
    if(root == NULL)
        return createNode(val);
    else if(val > root->data)
        root->right = insertNode(root->right,val);
    else   
        root->left = insertNode(root->left,val);

    root->height = max(height(root->left),height(root->right)) + 1;
    int balance = getBalance(root);

    // left left
    if(balance > 1 && (val < root->left->data))
        return rightRotation(root);
    // right right
    else if(balance < -1 && (val > root->right->data))
        return leftRotation(root);
    // left right
    else if(balance > 1 && (val > root->left->data)){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right left
    else if(balance < -1 && (val < root->right->data)){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

struct node *createTree(struct node *root){
    int n;
    while(1){
        printf("Enter the value: ");
        scanf("%d",&n);
        if(n == -1)
            break;
        root = insertNode(root,n);
    }
    return root;
}

void search(struct node *root,int val){
    if(root == NULL)
        printf("Element doesn't exist...\n");
    else{
        if(root->data == val)
            printf("It exists...\n");
        else if(val > root->data)
            search(root->right,val);
        else
            search(root->left,val);
    }
}

struct node *delete(struct node *root,int val){
    if(root->data == val){
        // no child
        if(root->left == NULL && root->right == NULL)
            return NULL;
        // only left
        else if(root->left != NULL && root->right == NULL)
            return root->left;
        // only right
        else if(root->left == NULL && root->right != NULL)
            return root->right;
        // both child
        else {
            int max_left = get_max(root->left);
            root->data = max_left;
            root->left = delete(root->left,max_left);
        }
    } else if(val > root->data)
        root->right = delete(root->right,val);
    else 
        root->left = delete(root->left,val);

    root->height = max(height(root->left),height(root->right)) + 1;
    int balance = getBalance(root);

    // left left
    if(balance > 1 && getBalance(root->left) >=0)
        return rightRotation(root);
    // right right
    else if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotation(root);
    // left right
    else if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right left
    else if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    
    return root;
}

void preorder(struct node *root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root = NULL;
    int op,n;

    printf("1 to create the tree\n2 to display the tree in preorder\n3 to insert an element\n4 to search an element\n5 to delete an element\n");
    while(1){
        printf("Enter your operation...\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            root = createTree(root);
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the lement to insert...\n");
            scanf("%d",&n);
            root = insertNode(root,n);
            printf("Element inserted...\n");
            break;
        case 4:
            printf("Enter the element to search...\n");
            scanf("%d",&n);
            search(root,n);
            break;
        case 5:
            printf("Enter the element to delete...\n");
            scanf("%d",&n);
            root = delete(root,n);
            printf("Element deleted...\n");
            break;
        default:
            exit(0);
        }
    }
}