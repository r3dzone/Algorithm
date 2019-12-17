//Made By R3dzone;
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const long long MAXN = 10000;
long long memo[MAXN+5];
int arr[MAXN+5];
int n;

long long dp(int x){
	long long& ret = memo[x];
	if(x > n) return ret = 0;
	if(x == n) return ret = arr[x];
	if (ret != -1) return ret;
	return ret = max(arr[x+1] + dp(x+3), max(arr[x+1] + dp(x+4), dp(x+2) ) ) + arr[x];	
}

int main(){
	long long tmp = 0;
	scanf("%d",&n);
	memset(memo, -1, sizeof(memo));
	--n;
	for(int i = 0; i <= n ;i++){
		scanf("%d",&arr[i]);
	}
	printf("%lld\n",max(dp(0),dp(1)));
}

//f(x) = x부터 끝까지 제일 마니 마시는 양
//첫잔 마시고 하나 건너띄고 마시는 경우 dp(x+2)
//두잔 마시고 두잔 건너띄고 마시기 arr[x+1] + dp(x+4)
//두잔 마시고 한잔 건너띄고 마시기 arr[x+1] + dp(x+3)