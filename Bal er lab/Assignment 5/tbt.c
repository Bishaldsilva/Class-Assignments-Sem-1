#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int lthread;
    int rthread;
};

struct node *createNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lthread = 1;
    newNode->rthread = 1;
}

struct node *insertNode(struct node *root,int val){
    struct node *queue[1000];
    struct node *temp,*newNode;
    int front = 0,top = 1;
    queue[front] = root;
    while(1){
        temp = queue[front];
        front++;
        if(temp->lthread == 1){
            newNode = createNode(val);
            newNode->left = temp->left;
            newNode->right = temp;
            temp->left = newNode;
            temp->lthread = 0;
            return root;
        } else {
            queue[top] = temp->left;
            top++;
        }
        if(temp->rthread == 1){
            newNode = createNode(val);
            newNode->right = temp->right;
            newNode->left = temp;
            temp->right = newNode;
            temp->rthread = 0;
            return root;
        } else {
            queue[top] = temp->right;
            top++;
        }
    }
}

struct node *createTree(struct node *root){
    int n;
    while(1){
        printf("Enter the value... ");
        scanf("%d",&n);
        if(n == -1)
            break;
        if(root == NULL)
            root = createNode(n);
        else
            root = insertNode(root,n);
    }
    return root;
}

struct node *leftMost(struct node *root){
    while(root->lthread == 0)
        root = root->left;
    return root;
}

void inorder(struct node *root){
    struct node *cur = leftMost(root);
    int count = 0;

    while(cur){
        if(count == 10)
            break;
        printf("%d ",cur->data);
        if(cur->rthread)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
        count++;
    }
}

int main(){
    struct node *root = NULL;
    root = createTree(root);
    printf("Inorder of the tree is: ");
    inorder(root);
}