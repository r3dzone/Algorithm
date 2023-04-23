//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e5;
const int MAXT = 1e9;

int n,t;
vector<int> c;
vector<int> r;

int main(){
    cin >> n >> t;
    int tmp;
    vector<pair<int,int> > player1;
    vector<pair<int,int> > maincolor;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        c.push_back(tmp);
    } 
    for(int i = 0; i < n; i++){
        cin >> tmp;
        r.push_back(tmp);
    }
    int t_num = 0;
    for(int i = 0; i < n; i++){
        if(c[i] == t){
            t_num++;
            maincolor.push_back(make_pair(-r[i],i));           
        }
        if(c[i] == c[0]){
            player1.push_back(make_pair(-r[i],i));           
        }
    }

    sort(maincolor.begin(),maincolor.end());
    sort(player1.begin(),player1.end());

    if(t_num){
        cout << maincolor[0].second+1 << endl;
    }else{
        cout << player1[0].second+1 << endl;
    }
}