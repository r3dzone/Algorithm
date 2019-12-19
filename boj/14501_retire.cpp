#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
int memo[MAXN+5];
int T[MAXN+5];
int P[MAXN+5];

int n;

int DP(int x){
	if(x >= n) return 0;
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	
	int tmp = 0;
	if(T[x] <= n - x){
		tmp = max(DP(x+T[x])+P[x],DP(x+1));
		return ret = tmp;
	}else return ret = DP(x+1);
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	++n;
	for(int i = 1; i < n ; i++)
		scanf("%d %d",&T[i] ,&P[i]);
	printf("%d\n",DP(1));
}