#include<stdio.h>
#include<string.h>

int main(){
    int a = 1;
    char c[1] = "a", s[1] = "A";
    c[0] = a + '0';
    strcat(s,c);
    printf("%s", c);
}