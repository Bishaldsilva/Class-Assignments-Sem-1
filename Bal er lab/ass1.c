#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *ptr;
int len = 0;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void create(int size){
    ptr = (int*)malloc(size * sizeof(int));
    for(int i=0;i<size;i++){
        scanf("%d",&ptr[i]);
    }
    len = size;
    printf("Enter the next operation.");
}
void insert(int n,int ind){
    for(int i=len;i>ind;i--){
        ptr[i] = ptr[i-1];
    }
    ptr[ind] = n;
    len++;
    printf("Enter the next operation.");
}
int count(){
    return len;
}
void indexed_element(int ind){
    printf("The %dth index is: ",ind);
    printf("%d\n",ptr[ind]);
    printf("Enter the next operation.");
}
void delete(int ind){
    for(int i=ind;i<len-1;i++){
        ptr[i] = ptr[i+1];
    }
    len--;
    printf("Enter the next operation.");
}
void sort(){
    int i,j;
    bool swapped;
    for(i = 0;i < len - 1; i++){
        for(j=0;j<len-i-1;j++){
            if(ptr[j] > ptr[j + 1]){
                swap(&ptr[j],&ptr[j + 1]);
            }
        }
    }
}
void search(int x){
    for(int i=0;i<len;i++){
        if(ptr[i]==x){
            printf("Element found at index %d",i);
        }
    }
}
void merge(){
    int n,i;
    printf("Enter the number of element for the 2nd array\n");
    scanf("%d",&n);
    int arr[n];
    int arr2[len + n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<(len+n);i++){
        if(i < len){
            arr2[i] = ptr[i];
        }
        else{
            arr2[i] = arr[i - len];
        }
    }
    printf("The merged array is \n");
    for(i=0;i<(len + n);i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
    printf("Enter the next operation.");
}
void split(int ind){
    int i,arr1[ind + 1],arr2[len - (ind + 1)];
    for(i=0;i<ind + 1;i++){
        arr1[i] = ptr[i];
    }
    for(i=0;i<(len - (ind + 1));i++){
        arr2[i] = ptr[ind + 1 + i];
    }
    printf("After splitting, the 1st array is: \n");
    for(i=0;i<ind + 1;i++){
        printf("%d ",arr1[i]);
    }
    printf("\nThe 2nd array is: \n");
    for(i=0;i<(len - (ind + 1));i++){
        printf("%d ",arr2[i]);
    }
}
void main(){
    printf("Enter the opertions...\n1 for creating the array\n2 for inserting values\n3 for getting the number of lements in the array\n 4 for getting an element\n5 to delete an element\n6 for sorting the array\n7 for displaying the whole array\n8 for searching a particular value in the array\n9 for merging two arrays.\n10 for splitting the array.\n");
    while(1){
        int n,x,ind;
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("enter the size of the array: ");
            scanf("%d",&x);
            create(x);
            break;
        case 2:
            printf("enter the value to be entered: \n");
            scanf("%d",&x);
            printf("Enter the index to be inserted: \n");
            scanf("%d",&ind);
            insert(x,ind);
            break;
        case 3:
            printf("The number of elements of the array is %d",count());
            break;
        case 4:
            printf("enter the index: ");
            scanf("%d",&x);
            indexed_element(x);
            break;
        case 5:
            printf("Enter the index to be deleted: \n");
            scanf("%d",&ind);
            delete(ind);
            printf("element deleted...");
            break;
        case 6:
            sort();
            printf("element sorted...");
            break;
        case 7:
            printf("The elements are...");
            for(int i=0;i<len;i++){
                printf("%d ",ptr[i]);
            }
            break;
        case 8:
            printf("Enter the element to be searched: ");
            scanf("%d",&x);
            search(x);
            break;
        case 9:
            merge();
            break;
        case 10:
            printf("Enter the index for the split operation: ");
            scanf("%d",&ind);
            split(ind);
            break;
        default:
            exit(0);
        }
    }
    // create(5);
    // int i;
    // for(i = 0;i < 5;i++){
    //     scanf("%d",&ptr[i]);
    // }
}