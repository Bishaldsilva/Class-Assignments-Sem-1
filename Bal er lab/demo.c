#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
int size;

void createList(){
    struct node *temp;
    int val,i;
    printf("Enter the values...\n");
    for(i = 0;i < size; i++){
        scanf("%d",&val);
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        }else{
            temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void reverseList(){
    struct node *prev = NULL,*curr = head;
    while(curr){
        struct node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void swap(int x,int y){
    struct node *temp = head,*prev1=NULL,*cur1=NULL,*prev2=NULL,*cur2=NULL;
    if(head->data == x || head->data == y){
        cur1 = head;
    }
    while(temp->next){
        if(temp->next->data == x || temp->next->data == y){
            if(cur1 == NULL){
                prev1 = temp;
                cur1 = temp->next;
            }else{
                prev2 = temp;
                cur2 = temp->next;
            }
        }
        temp = temp->next;
    }
    if(head==cur1){
        head = cur2;
    }else{
        prev1->next = cur2;
    }
    // if these two nodes are adjacent
    if(cur1 == prev2){        
        cur1->next = cur2->next;
        cur2->next = cur1;
    }else{ 
        // if not
        prev2->next = cur1;
        temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;
    }
}

void display(){
    struct node *temp = head;
    while(temp){
        printf("->%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    printf("Enter the size of the list\n");
    scanf("%d",&size);
    createList();
    display();
    swap(4,2);
    display();
}