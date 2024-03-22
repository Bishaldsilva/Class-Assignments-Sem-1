#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int pos;
    struct node *next;
};

void push(struct node **head,int val,int size){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    struct node *temp = *head;
    if(temp == NULL){
        newnode->pos = 0;
        temp = newnode;
        temp->next = NULL;
        *head = temp;
    } else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        if(temp->pos + 1 == size){
                printf("stack is full\n");
        }else{
            newnode->pos = temp->pos + 1;
            temp->next = newnode;
            temp= newnode;
            temp->next = NULL;
        }
    }
    printf("Element inserted\n");
}

void pop(struct node **head){
    struct node *temp = *head;
    if(temp == NULL){
        printf("stack is empty\n");
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        printf("Element deleted\n");
    }
}

void display(struct node *list){
    struct node *temp = list;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n,size;
    printf("Enter the number of stacks to be created\n");
    scanf("%d",&n);
    printf("Enter the size of each stack\n");
    scanf("%d",&size);
    struct node *stacks[n];

    for(int i=0;i<n;i++){
        stacks[i] = NULL;
    }

    int op,x,no;

    printf("1 for inserting an element\n2 for deleting an element\n3 for displaying the elements\n");
    while(1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the stack no...\n");
            scanf("%d",&no);
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            push(&stacks[no-1],x,size);
            break;
        case 2:
            printf("Enter the stack no...\n");
            scanf("%d",&no);
            pop(&stacks[no-1]);
            break;
        case 3:
            printf("Enter the stack no...\n");
            scanf("%d",&no);
            printf("Elements in the stack %d are\n",no);
            display(stacks[no-1]);
            break;
        default:
            exit(0);
        }
    } 
}
