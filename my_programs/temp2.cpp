#include<iostream>
using namespace std;
int main(){
    int my_arr[] = {2, 3, 4, 5, 6};
    for(int i:my_arr){
        cout << i << "\n";
    }

    char mystr[100] = {'B','i','s','h','a','l','\0'};
    *(mystr + 2) = 'c';
    printf("%s\n",mystr);


    return 0;
}