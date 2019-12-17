//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 500;

int arr[MAXN+5][MAXN+5];
long long memo[MAXN+5][MAXN+5];
	
long long dp(int x, int i){
	if(x == 0) return arr[x][i];
	if(i == 0) return arr[x][i] + dp(x-1,i);
	if(x == i) return arr[x][i] + dp(x-1,i-1);
	long long& ret = memo[x][i]; 
	if (memo[x][i] != -1) return ret;
	return ret = max(dp(x-1,i-1),dp(x-1,i)) + arr[x][i];
	
}

int main(){
	int n;
	long long tmp = 0;
	memset(memo, -1, sizeof(memo));
	scanf("%d",&n);
	for(int i = 0; i < n ; i++){
		for(int j = 0; j <= i ; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i = 0; i < n ; i++){
		tmp = max(tmp,dp(n,i));
	}
	printf("%lld",tmp);
}