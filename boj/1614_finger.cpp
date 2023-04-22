//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9;
typedef long long lint;

int main(){
    int hurt,ok;
    cin >> hurt >> ok;
    lint ans;

    if(hurt == 1 || hurt == 5){
        ans = 8 * lint(ok);
        ans += hurt - 1;
    }else if(hurt == 3){
        ans = (4 * lint(ok)) + 2; 
    }else{
        if(hurt == 2){
            if(ok%2 == 0){ 
                ans = 4 * lint(ok); 
            }else{
                ans = 4 * (ok+1);
                ans -= 2; 
            }
            ans += 2;
            ans--;
        }else{//4
            if(ok%2 == 0){ 
                ans = 4 * lint(ok+1); 
            }else{
                ans = 4 * lint(ok+2);
                ans -= 6; 
            }
            ans--;
        }     
    }
    if(ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}
