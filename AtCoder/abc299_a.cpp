//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
    cin >> n >> s;
    vector<int> bar;
    int ast;
    for(int i = 0; i < n; i++){
        if(s[i] == '|')bar.push_back(i);
        if(s[i] == '*')ast = i;
    }
    if(bar[0] < ast && bar[1] > ast) cout << "in" << endl;
    else cout << "out" << endl;

}