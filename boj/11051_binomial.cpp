#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;
const int MOD = 10007;

int memo[MAXN][MAXN];
int n,k;

int dp(int x,int y){
	if(y == 0 || y == x) return 1;
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	
	return ret = (dp(x-1,y)+dp(x-1,y-1))%MOD;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&n,&k);
	printf("%d\n",dp(n,k));
}
