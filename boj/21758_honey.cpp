//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> honey;
vector<int> psum;

void partial_sum(){
    psum.push_back(honey[0]);
    for(int i = 1; i < n; i++){
        psum.push_back(psum[i-1]+honey[i]);
    }
}

int max_honey(){
    int maxhoney = 0,now;

    for(int i = 1; i < n-1;i++){
        //barrel .... bee2 .... bee1
        now = psum[n-2] - honey[i]; //bee1's honey
        now += psum[i-1]; //bee2's honey;
        if(now > maxhoney) maxhoney = now;
    }

    for(int i = 1; i < n-1;i++){
        //bee1 .... bee2 .... barrel
        now = psum[n-1] - honey[0] - honey[i]; //bee1's honey
        now += psum[n-1] - psum[i]; //bee2's honey;
        if(now > maxhoney)
            maxhoney = now;
    }

    for(int i = 1; i < n-1;i++){
        //bee1 .... barrel .... bee2
        now = psum[i] - honey[0]; //bee1's honey
        now += psum[n-2] - psum[i-1]; //bee2's honey;
        if(now > maxhoney)
            maxhoney = now;
    }

    return maxhoney;
}

int main(){
    scanf("%d",&n);
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);
        honey.push_back(tmp);
    }
    partial_sum();
    printf("%d\n",max_honey());
    return 0;    
}