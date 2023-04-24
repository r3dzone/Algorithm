//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

string s;
map<char,int> m;

int main(){
    cin >> s;
    int s_size = s.size();

    for(int i = 0; i < s_size; i++){
        if(m.find(s[i]) == m.end()){
            m[s[i]] = 1;
        }else{
            m[s[i]]++;
        }
    }

    int odd = 0;
    char odd_chr;
    s = "";   
    for(auto iter: m){
        if(iter.second%2 != 0){
            odd++;
            if(odd > 1){
                cout << "I'm Sorry Hansoo" << endl;
                return 0;
            }
            odd_chr = iter.first;
        }
        for(int j = 0; j < (iter.second/2); j++){
            s += iter.first;
        }
    }
    string ans;
    if(odd) ans = s + odd_chr;
    else ans = s;
    reverse(s.begin(),s.end());
    ans += s;
    cout << ans << endl;
    return 0;
}