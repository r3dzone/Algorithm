//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n,k,tmp;
deque<pair<int,int> > dq;

bool judge(){
    int zero = 0;
    for(int i = 0; i < (2*n); i++){ 
        if(dq[i].first == 0) zero++;
        if(zero == k) return false;
    }
    return true;
}    

void go_robot(){
    for(int i = n-1; i > 0; i--){
        if(dq[i].first > 0 && dq[i].second == 0 && dq[i-1].second == 1){
            dq[i].first--;
            dq[i].second = 1;
            dq[i-1].second = 0;
            dq[n-1].second = 0; 
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < (2*n); i++){
        cin >> tmp;
        dq.push_back({tmp,0});
    }
    int ans = 1;
    //in = 0; out = n-1;
    while(1){
        dq.push_front(dq.back());
        dq.pop_back(); //rotate conveyor
        dq[n-1].second = 0;        
        go_robot();
        if(dq[0].first > 0){
            dq[0].second = 1;
            dq[0].first--;
        }
        if(!judge())break;
        ans++;
    }
    cout << ans << endl;
}