#include<iostream>
#include<vector>
#define INF 10000009
using namespace std;


int matrix_chain(int n, vector<vector<int>> &m, vector<vector<int>> &s, vector<int> &p){
    int i, l, j, k, q;
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

void print_chain(vector<vector<int>> &s, int i,int j){
    if(i == j)
        cout << "A"+to_string(i);
    else{
        cout << "(";
        print_chain(s, i, s[i][j]);
        print_chain(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main(){

    int i,n;

    cout << "Enter the number of matrices: \n";
    cin >> n;

    vector<vector<int>> m(n + 1, vector<int>(n + 1)), s(n + 1, vector<int>(n + 1));
    vector<int> p(n + 1);

    cout << "Enter the dimension of the matrices: \n";
    for(i = 0; i <= n; i++)
        cin >> p[i];
    
    int cost = matrix_chain(n, m, s, p);
    cout << cost << endl;
    print_chain(s, 1, n);

    return 0;
}