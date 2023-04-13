//Made by R3dzone
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
const int MAXM = 1e5;

vector<int> vec[MAXN+5];
int visited[MAXN+5];
int n,m,height;

void dfs(int x){
    visited[x] = 1;
    height++;
    int c_size = vec[x].size();
    for(int i = 0; i < c_size; i++)
        if(visited[vec[x][i]] == 0)
            dfs(vec[x][i]);
    return;
}

int main(){
    scanf("%d %d",&n,&m);
    int tmp1,tmp2;
    for(int i = 0; i < m; i++){
        scanf("%d %d",&tmp1,&tmp2);
        vec[tmp2].push_back(tmp1);
    }
    int max_height = -1;
    vector<int> ans[MAXN+5];

    for(int i = 1; i <= n; i++){
        height = 0;
        memset(visited,0,sizeof(visited));
        dfs(i);
        ans[height].push_back(i);
        if(max_height < height) max_height = height;
    }

    sort(ans[max_height].begin(),ans[max_height].end());
    int ans_size = ans[max_height].size();

    for(int i = 0; i < ans_size; i++)
        printf("%d ",ans[max_height][i]);

    return 0;
}