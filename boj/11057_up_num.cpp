//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e3+5;
const int MOD = 10007;
int memo[MAXN][10];
int dp(int x, int y){
	if(x == 0) return 1;
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	
	int tmp = 0;
	for(int i = 0; i <= y; ++i)
		tmp = (tmp + dp(x-1,i))%MOD;
	return ret = tmp;
}

int main(){
	memset(memo,-1,sizeof(memo));
	int n,tmp = 0;
	scanf("%d",&n);
	printf("%d\n",dp(n,9));
}