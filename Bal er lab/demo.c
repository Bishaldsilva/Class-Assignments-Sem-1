#include<stdio.h>
void print(char *ptr){
    *ptr = 'b';
}
void main(){
    char c = 'a';
    print(&c);
    printf("%c",c);
}