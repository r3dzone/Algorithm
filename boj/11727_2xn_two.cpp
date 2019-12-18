#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3;
const int MOD = 10007;

int memo[MAXN+5];
int n;

int recurDP(int x){
	if(x <= 0) return 0;
	if(x == 1) return 1;
	if(x == 2) return 3;
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	
	return ret = (recurDP(x-1)+ (2 * recurDP(x-2)))%MOD;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%d\n",recurDP(n));
}

/*
f(x):f(x-1) + 2f(x-2)
	:2xN 타일을 채우는 방법의 수
*/