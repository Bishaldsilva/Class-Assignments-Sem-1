#include<stdio.h>
#include<stdlib.h>

void push(int *arr,int *top,int val,int size){
    if(*top + 1 == size){
        printf("queue is full\n");
    }
    else{
        *top = *top + 1;
        arr[*top] = val;
        printf("Element inserted\n");
    }
}

void pop(int *arr,int *top){
    if(*top == -1){
        printf("queue is empty");
    }
    else{
        int x = arr[0];
        for(int i=1;i<=*top;i++){
            arr[i-1] = arr[i];
        }
        *top = *top - 1;
        printf("Element deleted\n");
    }
}

void is_same(int arr1[],int top1,int arr2[],int top2){
    if(top1 != top2){
        printf("These two stack are not same\n");
    }else{
        int flag = 1;
        for(int i=0;i<=top1;i++){
            if(arr1[i]!=arr2[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("These two stack are same\n");
        }else{
            printf("These two stack are not same\n");
        }
    }
}

void display(int arr[],int top){
    int i;
    for(i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n,size;
    printf("Enter the number of queues to be created\n");
    scanf("%d",&n);
    printf("Enter the size of each queues\n");
    scanf("%d",&size);

    int arr[n][size],top[n],op,x,no,n1,n2;

    for(int i=0;i<n;i++){
        top[i] = -1;
    }

    printf("1 for inserting an element\n2 for deleting an element\n3 for displaying the elements\n4 for comparing wo queues\n");
    while(1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the queue no...\n");
            scanf("%d",&no);
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            push(arr[no-1],&top[no-1],x,size);
            break;
        case 2:
            printf("Enter the queue no...\n");
            scanf("%d",&no);
            pop(arr[no-1],&top[no-1]);
            break;
        case 3:
            printf("Enter the queue no...\n");
            scanf("%d",&no);
            printf("Elements in the queue %d are\n",no);
            display(arr[no-1],top[no-1]);
            break;
        case 4:
            printf("Enter the 1st queue no...\n");
            scanf("%d",&n1);
            printf("Enter the 2nd queue no...\n");
            scanf("%d",&n2);
            is_same(arr[n1-1],top[n1-1],arr[n2-1],top[n2-1]);
            break;
        default:
            exit(0);
        }
    } 
}