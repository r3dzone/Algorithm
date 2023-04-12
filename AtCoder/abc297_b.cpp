//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

string S;

void judge(){
    int lb = 9,rb,k,q,lr=9,rr;
    for(int i = 0; i < 8; i++){
        if(S[i] == 'R'){
            if(lr == 9)lr = i;
            else rr = i;
        }else if(S[i] == 'B'){
            if(lb == 9)lb = i;
            else rb = i;
        }else if(S[i] == 'K'){
            k = i;
        }else if(S[i] == 'Q'){
            q = i;
        }
    }

    if(((lr<k) && (k<rr))&&(lb%2 != rb%2)){
        cout << "Yes" << endl;
        return;
    }
    else{ 
        cout << "No" << endl;
    return;
    }
}

int main(){
    cin >> S;
    judge();
    return 0; 
}