#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int l,int r){
    int i = l-1,j;
    for(j=l;j<=r;j++){
        if(arr[j] < arr[r]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void merge(int arr[],int l,int m,int r){
    int i,j,k,n1 = m - l + 1,n2 = r - m;
    int L[n1],R[n2];

    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int q = partition(arr,l,r);
        quickSort(arr,l,q-1);
        quickSort(arr,q+1,r);
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int op,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("1 for quick sort\n2 for merge sort\n3 for display\n");
    while (1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                quickSort(arr,0,n-1);
                printf("Array sorted...\n");
                break;
            case 2:
                mergeSort(arr,0,n-1);
                printf("Array sorted...\n");
                break;
            case 3:
                display(arr,n);
                break;
            default:
                exit(0);
        }
    }
}