#include<iostream>
#include<string>
using namespace std;

void func(int n, int **s){
    printf("lkfw");
}

int main(){
   int n = 5;
   int **s;

   s = new int *[n + 1];

    func(n, s);

    return 0;
}