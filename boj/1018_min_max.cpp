#include <bits/stdc++.h>
using namespace std;
int main(){
    int maxn = 12345678;
    int n,tmp,min = maxn,max = -maxn;
    cin>>n;
    while(n--){
        cin >> tmp;
        if(tmp < min) min = tmp;
        if(tmp > max) max = tmp;
    }
    cout << min << " " << max << endl; 
    return 0;
}