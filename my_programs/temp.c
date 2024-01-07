#include<stdio.h>
#include<string.h>

void fn(int *p){
    *p = *p + 1;
}

int main(){
    int a = 0;
    fn(&a);
    printf("%d",a);
}