//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;

long long memo[MAXN+5];
long long arr[MAXN+5];
int n;

long long dp(int x){
	if(x == 0) return arr[x];
	long long& ret = memo[x];
	if(ret != -INF) return ret;
	return ret = max( dp(x-1) + arr[x] , arr[x]);
}

int main(){
	long long tmp = -INF;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) memo[i] = -INF;
	for(int i = 0; i < n ; i++)scanf("%lld", &arr[i]);
	for(int i = 0; i < n ; i++)tmp = max(dp(i),tmp);
	printf("%lld\n",tmp);
	return 0;
}