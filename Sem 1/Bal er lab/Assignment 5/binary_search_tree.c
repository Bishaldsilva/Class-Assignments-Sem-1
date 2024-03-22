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
    printf("Enter the value...(-1 to exit)\n");
    while (1)
    {
        scanf("%d",&val);
        if(val == -1){
            break;
        }
        root = insert(root,val);
    }
    return root;
}

void levelorder(struct node *root){
    struct node *queue[100];
    for(int j=0;j<100;j++){
        queue[j] = NULL;
    }
    int front = 0,i = 2;
    queue[0] = root;

    while(1){
        if(queue[front] == 0){
            i++;
            printf("\n");
            if(queue[front + 1] == 0)
                break;
        } else {
            printf("%d ",queue[front]->data);
            if(queue[front]->left)
                queue[i++] = queue[front]->left;
            if(queue[front]->right)
                queue[i++] = queue[front]->right;
        }
        front++;
    }
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

int get_max(struct node *root){
    int val;
    struct node *temp = root;
    while (temp->right){
        temp = temp->right;
    }
    return temp->data;
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
    
    return root;
}

int main(){
    struct node *root = NULL;
    int op,n;

    printf("1 to create the tree\n2 to display the tree in levelorder\n3 to insert an element\n4 to search an element\n5 to delete an element\n");
    while(1){
        printf("Enter your operation...\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            root = createTree(root);
            break;
        case 2:
            levelorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the lement to insert...\n");
            scanf("%d",&n);
            root = insert(root,n);
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