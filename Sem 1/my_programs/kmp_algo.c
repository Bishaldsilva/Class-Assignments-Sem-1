#include<stdio.h>
#include<string.h>

int *calcPatternArray(char str[]){
    static int arr[100];
    int j = 0,i = 1;

    int len = strlen(str) - 1;
    while(i < len){
        if(str[j] == str[i]){
            arr[i] = j + 1;
            j++;
            i++;
        }else{
            if(j != 0)
                j = arr[j - 1];
            else
                i++;
        }
    }
    return arr;
}

int kmpAlgo(char str1[],char str2[],int len1,int len2){
    int *patternArray = calcPatternArray(str2);
    int i = 0,j = 0;
    while(i < len1 && j < len2){
        if(str1[i] == str2[j]){
            if( j == len2 - 1)
                return i - j;
            i++;
            j++;
        } else {
            if(j != 0)
                j = patternArray[j - 1];
            else
                i++;
        }
    }
    return -1;
}

int main(){
    char str1[100],str2[100];
    int i;

    printf("Enter the main string...\n");
    fgets(str1,sizeof(str1),stdin);
    printf("Enter the pattern string...\n");
    fgets(str2,sizeof(str2),stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    int index = kmpAlgo(str1,str2,len1,len2);
    if(index >= 0)
        printf("pattern exist at %d",index);
    else
        printf("pattern doesn't exist");   
}