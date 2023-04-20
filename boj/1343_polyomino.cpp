//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

string board;
string ans;

void add_a(int x){
    for(int i = 0; i < x; i++){
        ans += "AAAA";
    }
    return;
}

void add_b(int x){
        for(int i = 0; i < x; i++){
        ans += "BB";
    }
    return;
}

int main(){
    cin >> board;
    int b_size = board.size();

    int cnt = 0;
    for(int i = 0; i < b_size; i++){
        if(board[i] == 'X'){
            cnt++;
        }else{
            if(cnt != 0){
                if(cnt%2 != 0){
                    ans = "-1";
                    break;
            }else{
                add_a(cnt/4);
                add_b((cnt%4)/2);
            }
            cnt = 0;
            }
            ans += ".";
        }
    }
    if(cnt != 0){
        if(cnt%2 != 0){
            ans = "-1";
        }else{
            add_a(cnt/4);
            add_b((cnt%4)/2);
        }
    }
    cout << ans << endl;
}
