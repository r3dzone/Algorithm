//Made By R3dzone
#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int n;
 
int main(){
    cin >> n >> s;
    int max_dango = -1;
    int now = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            now++;
        }
        if(s[i] == '-'){
            if(now != 0 && max_dango < now) max_dango = now;
            now = 0;
        }
    }
    now = 0;
    reverse(s.begin(),s.end());
    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            now++;
        }
        if(s[i] == '-'){
            if(now != 0 && max_dango < now) max_dango = now;
            now = 0;
        }
    }
    cout << max_dango << endl;
}