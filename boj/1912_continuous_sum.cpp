//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

long long memo[MAXN+5];
long long arr[MAXN+5];
int n;

long long dp(int x){
	long long& ret = memo[x];
	if(x == 0) return ret = arr[x];
	if(ret != -1) return ret;
	return ret = max( memo[x-1] + arr[x] , arr[x]);
	
}

int main(){
	long long tmp = -10001;
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);
	for(int i = 0; i < n ; i++)scanf("%lld", &arr[i]);
	for(int i = 0; i < n ; i++)tmp = max(dp(i),tmp);
	printf("%lld\n",tmp);
	return 0;
}