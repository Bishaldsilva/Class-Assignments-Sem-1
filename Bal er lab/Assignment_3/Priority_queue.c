#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *head = NULL;
int size=0,max_size;

void push(int val,int priority){
    if(size == max_size){
        printf("Queue is full...\n");
    }else{
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->priority =priority;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
        }else{
            if(head->priority < priority){
                newnode->next = head;
                head = newnode;
                size++;
            }else{
                struct node *temp = head;
                while(temp->next && temp->next->priority > priority){
                    temp = temp->next;
                }
                newnode->next = temp->next;
                temp->next = newnode;
                size++;
            }
        }
        printf("Element inserted...\n");
    }
}

void pop(){
    if(size == 0){
        printf("Queue is empty...\n");
    }else{
        struct node *temp = head;
        head = head->next;
        free(temp);
        size--;
        printf("Element deleted...\n");
    }
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    printf("Enter the max size of the priority queue\n");
    scanf("%d",&max_size);

    int op,val,priority;
    printf("1 for inserting an element\n2 for deleting an element\n3 for displaying the elements\n");
    while(1){
        printf("Enter your operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&val);
            printf("Enter the priority...\n");
            scanf("%d",&priority);
            push(val,priority);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Elements in the queue are...\n");
            display();
            break;
        default:
            exit(0);
        }
    } 
}