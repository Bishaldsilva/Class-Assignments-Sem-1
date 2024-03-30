#include<iostream>
#include<string>
#include<unordered_map>
#include<typeinfo>
using namespace std;

int main(){

    string s = "III";
    char a = 'I';
    unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };
    int sum = 0, i = 0;
    while(i < s.length()){
        cout << umap[s[i]] << endl;

        if(i + 1 < s.length()){
            if(umap[s[i]] >= umap[s[i + 1]]){
                sum += umap[s[i]];
                i++;
            } else {
                sum += (umap[s[i - 1]] - umap[s[i]]);
                i +=2;
            }
        } else {
            sum += umap[s[i]];
            i++;
        }
        // i++;
    }
    cout << sum;
}