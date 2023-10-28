#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int size;

void create(){
    int n,x;
    struct node *temp;
    printf("Enter the number of node you want to insert...\n");
    scanf("%d",&n);
    size = n;
    printf("Enter the values...\n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void swap(int a,int b){
    struct node *temp=head,*temp1=NULL,*temp2=NULL;
    while(temp){
        if(temp->data == a || temp->data == b){
            if(temp1== NULL)
                temp1 = temp;
            else
                temp2 = temp;
        }
        temp = temp->next;
    }
    int tmp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = tmp;
}

void bubble_sort(){
    struct node *temp1,*temp2;
    int flag = 0;
    for(int i=0;i<size;i++){
        temp1 = head;
        temp2 = temp1->next;
        for(int j=0;j<size - 1 - i;j++){
            if(temp1->data > temp2->data){
                swap(temp1->data,temp2->data);
                flag = 1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(flag==0){
            break;
        }
    }
    printf("List sorted...\n");
}

struct node *sortedInsert(struct node *sorted,struct node *curr){
    if(sorted == NULL || sorted->data > curr->data){
        curr->next = sorted;
        sorted = curr;
    }else{
        struct node *temp = sorted;
        while(temp->next != NULL && temp->next->data <curr->data){
            temp = temp->next;
        }
        curr->next = temp->next;
        temp->next = curr;
    }
    return sorted;
}

void insertion_sort(){
    struct node *sorted = NULL,*curr = head;
    while(curr){
        struct node *next = curr->next;
        sorted = sortedInsert(sorted,curr);
        curr = next;
    }
    head= sorted;
    printf("List sorted...\n");
}

void selection_sort(){
    struct node *ptr1 = head,*ptr2;
    int min;
    while(ptr1){
        ptr2 = ptr1->next;
        min = ptr1->data;
        while(ptr2){
            if(ptr2->data < min){
                min = ptr2->data;
            }
            ptr2 = ptr2->next;
        }
        if(min != ptr1->data)
            swap(ptr1->data,min);
        ptr1 = ptr1->next;
    }
    printf("List sorted...\n");
}

void display(){
    struct node *temp = head;
    while(temp){
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int op,a,b;
    printf("1 to create the list\n2 to display the list\n3 to bubble sort\n4 for insertion sort\n5 for selection sort\n");
    while(1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            head = NULL;
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            bubble_sort();
            break;
        case 4:
            insertion_sort();
            break;
        case 5:
            selection_sort();
            break;
        default:
            exit(0);
        }
    }
}