//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int chr['z'+1];

bool check(){
    memset(chr,0,sizeof(chr));
    int str_size = str.size();
    chr[str[0]]++;
    for(int i = 1; i < str_size; i++){
        if(str[i-1] == str[i]){
            continue;
        }else{
            if(chr[str[i]]) return false;
            chr[str[i]]++;
        }
    }
    return true;
}

int main(){
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(check())ans++;
    }
    cout << ans << endl;
}