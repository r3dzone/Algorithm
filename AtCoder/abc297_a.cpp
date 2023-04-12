#include <bits/stdc++.h>

using namespace std;

int n,d;

int main(){
    scanf("%d %d",&n,&d);
    int now,last;
    int ans = -1;
    scanf("%d",&now);
    last = now;
    for(int i = 1; i < n; i++){
        scanf("%d",&now);
        if((now - last) <= d){
            ans = now;
            break;
        }
        last = now; 
    }
    printf("%d\n",ans);
    return 0;
}