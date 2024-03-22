#include<stdio.h>
#include<stdlib.h>

void push(int *arr,int *top,int val,int n){
    if(*top + 1 == n){
        printf("stack is full\n");
    }
    else{
        *top = *top + 1;
        arr[*top] = val;
        printf("Element inserted\n");
    }
}

int pop(int *arr,int *top,int n){
    if(*top == -1){
        printf("stack is empty");
        return -1;
    }
    else{
        int x = arr[*top];
        *top = *top - 1;
        return x;
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
    int n,top=-1;
    printf("Enter the maximum number of element you want in the stack\n");
    scanf("%d",&n);
    int arr[n],op,x;
    printf("1 for inserting an element\n2 for deleting an element\n3 for displaying the elements\n");
    while(1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            push(arr,&top,x,n);
            break;
        case 2:
            x = pop(arr,&top,n);
            if(x >= 0){
                printf("%d has been deleted\n",x);
            }
            break;
        case 3:
            printf("Elements in the stack are\n");
            display(arr,top);
            break;
        default:
            exit(0);
        }
    } 
}