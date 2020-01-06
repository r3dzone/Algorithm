//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long lint;

const int MAXN = 1e4+5;
const int MOD = 987654321;
lint memo[MAXN];

int n;

lint DP(int x){
	if(x == 0) return 1;
	if(x == 2) return 1;
	
	lint& ret = memo[x];
	if(ret != -1) return ret;
	
	lint tmp = 0;
	for(int i = 2;i <= x ; i += 2){
		tmp = (tmp+(DP(x-i)%MOD * DP(i-2)%MOD*1LL)%MOD)%MOD;	
	}
	return ret = tmp;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%lld\n",DP(n));
}