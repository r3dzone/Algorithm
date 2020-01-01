#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30+5;

int memo[MAXN];
int n;

int dp(int x){
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(x == 2) return 3; 
	
	int& ret = memo[x];
	if(ret != -1) return ret;

	return ret = (4*dp(x-2)) - dp(x-4);
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%d\n",dp(n));
}