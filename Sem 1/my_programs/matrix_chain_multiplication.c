#include<stdio.h>
#include<string.h>
#define INF 10000009

int matrix_chain(int n, int p[], int s[][n + 1]){
    int m[n + 1][n + 1];
    int i, j, k, l, q;

    for(i = 1; i <= n; i++)
        m[i][i] = 0;


    for(l = 2; l <= n; l++){
        for(i = 1; i <= n - l + 1; i++){
            j = i + l - 1;
            m[i][j] = INF;
            for(k = i; k < j; k++){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n];
}

void print_parenthesis(int n, int i, int j, int s[][n + 1]){
    if(i == j){
        char c[1],s[1] = "A";
        sprintf(c, "%d", i);
        strcat(s, c);
        printf("%s",s);
    } else {
        printf("(");
        print_parenthesis(n, i, s[i][j], s);
        print_parenthesis(n, s[i][j] + 1, j, s);
        printf(")");
    }
        
}

int main(){

    int n;
    printf("Enter the number of matrices: ");
    scanf("%d",&n);

    int i, x, p[n + 1], s[n + 1][n + 1];
    printf("Enter the dimention of the matrices...\n");
    for(int i = 0; i <= n; i++){
        scanf("%d",&x);
        p[i] = x;
    }

    printf("%d \n",matrix_chain(n, p, s));
    print_parenthesis(n, 1, n, s);

    return 0;
}