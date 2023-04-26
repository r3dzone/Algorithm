//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int x;
int pre[5000];


int main(){
    cin >> x;
    int i = 1;
    int tmp = 0;
    pre[0] = 0;
    while(1){
        pre[i] = pre[i-1] + i;
        if(pre[i] >= 10000000)
            break;
        i++;
    }

    int fst = lower_bound(pre,pre+4472,x) - pre -1;
    int scd = x - pre[fst];
    int thd = fst+2 - scd ;

    if(fst%2 == 0){
        cout << thd << "/" << scd << endl;
    }else{
        cout << scd << "/" << thd << endl;
    }
    
}