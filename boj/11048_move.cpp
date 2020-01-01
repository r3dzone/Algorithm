#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;

int memo[MAXN][MAXN];
int arr[MAXN][MAXN];
int n,m;

int dp(int x,int y){
	if(x < 0 || y < 0) return 0;
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	
	return ret = max(dp(x-1,y-1),max(dp(x-1,y),dp(x,y-1)))+arr[x][y];
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n ;++i){
		for(int j = 0; j < m ;++j)
			scanf("%d",&arr[i][j]);
	}
	printf("%d\n",dp(n-1,m-1));
}
