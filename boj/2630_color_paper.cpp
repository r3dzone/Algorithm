//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 128;

int n;
int ans[2] = {0,0};
vector<vector<int> > vec(MAXN+5,vector<int>(MAXN+5,-1));

int dq(int x,int y,int z){ //0 = white 1 = blue 2 = noting
    if(z == 1){
        ans[vec[x][y]]++;
        return vec[x][y];    
    }
    
    int box[4];
    box[0] = dq(x-(z/2),y-(z/2),z/2);
    box[1] = dq(x-(z/2),y,z/2);
    box[2] = dq(x,y-(z/2),z/2);
    box[3] = dq(x,y,z/2);

    int tmp_white = 0,tmp_blue = 0;
    for(int i = 0; i < 4; i++){
        if(box[i] == 1)tmp_blue++;
        else if(box[i] == 0) tmp_white++;
    }
    
    if(tmp_white == 4){
        ans[0] -= 3;
        return 0;
    }if(tmp_blue == 4){
        ans[1] -= 3;
        return 1;
    }
    return 2;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d",&vec[i+1][j+1]);
    dq(n,n,n);
    printf("%d\n%d\n",ans[0],ans[1]);
    return 0;
}