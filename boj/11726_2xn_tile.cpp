//Made By R3dzone;
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int memo[MAXN+5];

int dp(int x){
	if (x == 1) return 1;
	if (x == 2) return 2;
	int& ret = memo[x]; 
	if (memo[x] != -1) return ret;
	return ret = (dp(x-1)%10007 + dp(x-2)%10007)%10007;
}

int main(){
	int t , tmp = 0;
	memset(memo, -1, sizeof(memo));
	scanf("%d",&t);
	printf("%d\n",dp(t));
}