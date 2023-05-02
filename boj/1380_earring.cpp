//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> vec;
vector<int> state;
string tmp;
int tmp_num;
char tmp_chr;

int main(){
    int cnt = 1;
    while(1){
        cin >> n;
        cin.ignore();
        if(n == 0)break;
        vec.clear();
        vec.push_back("");
        state.clear();
        state.push_back(0);
        for(int i = 0; i < n; i++){
            getline(cin,tmp);
            vec.push_back(tmp);
            state.push_back(0);
        }
        for(int i = 1; i < 2*n; i++){
            cin >> tmp_num >> tmp_chr;
            state[tmp_num]++;
        }
        for(int i = 1; i <= n; i++){
            if(state[i] == 1) cout << cnt << " " << vec[i] << endl;
        }
        cnt++;
    }
}