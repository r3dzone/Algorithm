//Made By R3dzone;
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 90;
long long  memo[MAXN+5];

long long  dp(int x){
	if (x == 1) return 1;
	if (x == 2) return 1;
	long long & ret = memo[x]; 
	if (memo[x] != -1) return ret;
	return ret = dp(x-1) + dp(x-2);
}

int main(){
	int t = 0;
	memset(memo, -1, sizeof(memo));
	scanf("%d",&t);
	printf("%lld\n",dp(t));
}