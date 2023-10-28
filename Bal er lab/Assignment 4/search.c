#include<stdio.h>
#include<stdlib.h>

void linear_search(int a[],int n,int val){
    int flag = 0,i;
    for(i=0;i<n;i++){
        if(a[i] == val){
            printf("%d found at index %d\n",val,i);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Element not found\n");
    }
}

void binary_search(int a[],int n,int val){
    int left = 0;
    int right = n-1;
    int flag = 0;
    while(left<right){
        int mid = (left + right) / 2;
        if(a[mid] == val){
            printf("%d found at index %d\n",val,mid);
            flag = 1;
            break;
        }
        else if(val < a[mid]){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    if(flag == 0){
        printf("Element not found\n");
    }
}

int main(){
    int op,val,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("1 for linear search\n2 for binary search\n");
    while (1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                printf("Enter the value you want to search...\n");
                scanf("%d",&val);
                linear_search(arr,n,val);
                break;
            case 2:
                printf("Enter the value you want to search...\n");
                scanf("%d",&val);
                binary_search(arr,n,val);
                break;
            default:
                exit(0);
        }
    }
    
}