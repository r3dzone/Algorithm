//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
    cin >> n;
    cin >> s;
    int s_size = s.size();
    int o_num = 0,x_num = 0;
    for(int i = 0; i < s_size; i++){
        if(s[i] == 'o') o_num++;
        if(s[i] == 'x') x_num++;
    }
    if(o_num > 0 && x_num == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
