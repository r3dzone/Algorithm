//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int t,x,y;
unsigned int teleport[50000];
int teleport_num[50000];
int sum[50000];

void pre(){
    sum[1] = 1;
    teleport[1] = 1;
    teleport_num[1] = 1;
    for(int i = 2; i < 46342; i++){
        sum[i] = sum[i-1]+i;
        teleport[i] = sum[i] + sum[i-1];
        teleport_num[i] = teleport_num[i-1] + 2;
    }
}

int main(){
    scanf("%d",&t);
    pre();
    for(int i = 0; i < t; i++){
        scanf("%d %d",&x,&y);
        int diff = y - x;
        int ans;
        int root = lower_bound(teleport,teleport+46341,diff) - teleport;
        if(teleport[root] - root < diff){
            ans = teleport_num[root];
        }else{
            ans = teleport_num[root]-1;
        }
        printf("%d\n",ans);
    }
}