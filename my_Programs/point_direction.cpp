#include<bits/stdc++.h>
using namespace std;

int direction(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> p0){
    int _x1 = p1.first - p0.first;
    int _y1 = p1.second - p0.second;
    int _x2 = p2.first - p0.first;
    int _y2 = p2.second - p0.second;

    int product = (_x1 * _y2) - (_x2 * _y1);
    return product;
}

bool compare_point(pair<int, int> p1, pair<int, int> p2){
    
}

int main(){

    list<pair<int, int>> l;

    pair<int, int> p1, p2;
    p1 = make_pair(5,4);
    p2 = make_pair(4,6);

    bool result = is_clockwise(p2, p1, make_pair(0,0));

    cout << result << endl;

    return 0;
}