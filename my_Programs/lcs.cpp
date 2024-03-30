#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longest_common_subsequence(int m, int n, string s1, string s2, vector<vector<string>> &s){
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    int i, j;
    for(i = 0; i <= m; i++)
        c[i][0] = 0;

    for(j = 0; j <= n; j++)
        c[0][j] = 0;

    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(s1[i - 1] == s2[j - 1]){
                c[i][j]= c[i - 1][j - 1] + 1;
                s[i][j] = "LU";
            } else {
                if(c[i - 1][j] > c[i][j - 1]){
                    c[i][j] = c[i - 1][j];
                    s[i][j] = "U";
                } else {
                    c[i][j] = c[i][j - 1];
                    s[i][j] = "L";
                }
            }
        }
    }
    return c[m][n];
}

void display_subsequence(vector<vector<string>> s, string s1, int i, int j){
    if(i != 0 && j != 0){
        if(s[i][j] == "LU"){
            display_subsequence(s, s1, i - 1, j - 1);
            cout << s1[i - 1];
        } else {
            if(s[i][j] == "U")
                display_subsequence(s, s1, i - 1, j);
            else
                display_subsequence(s, s1, i, j - 1);
        }
    }
}

int main(){
    string s1, s2;

    cout << "Enter the first string: \n";
    cin >> s1;

    cout << "Enter the second string: \n";
    cin >> s2;

    vector<vector<string>> s(s1.length() + 1, vector<string>(s2.length() + 1));

    cout << "The length of the common subsequence is: " << longest_common_subsequence(s1.length(), s2.length(), s1, s2, s) << endl;
    display_subsequence(s, s1, s1.length(), s2.length());


    return 0;
}