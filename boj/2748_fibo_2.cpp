#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long lint;

lint memo[100];
int n;

lint fibo(int n){
	if(n <= 1) return n;

	lint& ret = memo[n];
	if(ret != -1) return ret;

	ret = fibo(n-1) + fibo(n-2);
	return ret;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%lld\n",fibo(n));
}