//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long lint;

const int MAXN = 1e6+5;
const int MOD = 15746;
int n;
int memo[MAXN];

int DP(int x){
	memo[0] = 1;
	memo[1] = 1;
	
	for(int i = 2 ; i <= x ; ++i){
		memo[i] = (memo[i-1]+memo[i-2])%MOD;
	}
	return memo[x];
}
int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%d\n",DP(n));
}
