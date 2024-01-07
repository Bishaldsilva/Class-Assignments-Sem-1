#include<stdio.h>
#include<stdlib.h>

void createTree(int arr[],int ind,int *limit){
    int n;
    printf("Enter the value to insert...(-1 to exit)\n");
    scanf("%d",&n);
    if(n != -1){
        arr[ind] = n;
        *limit = *limit + 1;
        printf("Enter element at left of %d\n",n);
        createTree(arr,2*ind,limit);
        printf("Enter element at right of %d\n",n);
        createTree(arr,2*ind + 1,limit);
    }
}

void inorder(int arr[],int ind,int limit){
    if(ind <= limit){
        inorder(arr,2*ind,limit);
        printf("%d ",arr[ind]);
        inorder(arr, 2*ind + 1,limit);
    }
}

void preorder(int arr[],int ind,int limit){
    if(ind <= limit){
        printf("%d ",arr[ind]);
        preorder(arr,2*ind,limit);
        preorder(arr, 2*ind + 1,limit);
    }
}

void postorder(int arr[],int ind,int limit){
    if(ind <= limit){
        postorder(arr,2*ind,limit);
        postorder(arr, 2*ind + 1,limit);
        printf("%d ",arr[ind]);
    }
}

int main(){
    int op,arr[100],limit = 0;
    arr[0] = -1;

    printf("1 to create the tree(max 100 elements are allowed)\n2 to display the tree in inorder\n3 to display the tree in preorder\n4 to display the tree in postorder\n");
    while(1){
        printf("Enter your operation...\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            createTree(arr,1,&limit);
            break;
        case 2:
            inorder(arr,1,limit);
            printf("\n");
            break;
        case 3:
            preorder(arr,1,limit);
            printf("\n");
            break;
        case 4:
            postorder(arr,1,limit);
            printf("\n");
            break;
        default:
            exit(0);
        }
    }
}