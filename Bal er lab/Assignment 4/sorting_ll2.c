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

void swapAddr(struct node **ptr1,struct node **ptr2){
    struct node *temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void display(){
    struct node *temp = head;
    while(temp){
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void swap(int a,int b){
    struct node *temp=head,*prev1=NULL,*cur1=NULL,*prev2=NULL,*cur2=NULL;
    if(head->data == a || head->data == b){
        cur1 = head;
    }
    while(temp->next){
        if(temp->next->data == a || temp->next->data == b){
            if(cur1== NULL){
                prev1 = temp;
                cur1 = temp->next;
            }else{
                prev2= temp;
                cur2 = temp->next;
            }
        }
        temp = temp->next;
    }
    if(head == cur1){
        head = cur2;
    }else{
        prev1->next = cur2;
    }
    if(cur1 == prev2){
        temp = cur2->next;
        cur1->next = temp;
        cur2->next = cur1;
    }else{
        prev2->next = cur1;
        temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;
    }
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
                swapAddr(&temp1,&temp2);
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
    struct node *minAddr;
    while(ptr1){
        ptr2 = ptr1->next;
        minAddr = ptr1;
        while(ptr2){
            if(ptr2->data < minAddr->data){
                minAddr = ptr2;
            }
            ptr2 = ptr2->next;
        }
        if(minAddr->data != ptr1->data){
            swap(ptr1->data,minAddr->data);
            swapAddr(&ptr1,&minAddr);
        }
        ptr1 = ptr1->next;
    }
    printf("List sorted...\n");
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