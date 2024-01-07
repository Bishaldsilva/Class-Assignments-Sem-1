#include<stdio.h>
#include<string.h>

int *calcArray(char pattern[]){
    int n = strlen(pattern);
    static int arr[100];
    int i = 1,j = 0;

    while(i < n){
        if(pattern[j] == pattern[i]){
            arr[i] = j + 1;
            j++;
            i++; 
        } else {
            if(j != 0)
                j = arr[j - 1];
            else
                i++;
        }
    }
    return arr;
}

int kmpAlgo(char text[],char pattern[]){
    int i=0,j=0;
    int *arr = calcArray(pattern);
    while (i < strlen(text) && j < strlen(pattern)){
        if(text[i] == pattern[j]){
            if(j == strlen(pattern) - 1)
                return i - j;
            i++;
            j++;
        } else {
            if(j != 0)
                j = arr[j - 1];
            else
                i++;
        }
    }

    return -1;
    
}

int main(){
    char text[100],pattern[100];
    printf("Enter the text: ");
    scanf("%s",text);
    printf("Enter the pattern: ");
    scanf("%s",pattern);

    int *arr = calcArray(pattern);
    
    int index = kmpAlgo(text,pattern);
    if(index >= 0)
        printf("Pattern exist at %d",index);
    else
        printf("pattern doesn't exist");
}