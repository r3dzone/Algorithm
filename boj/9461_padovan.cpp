#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std; 

const int MAXN = 100;
long long memo[MAXN+5];

int t,n;

long long DP(int x){
	if(x <= 3) return 1;
	if(x <= 5) return 2;
	
	long long& ret = memo[x];
	if(ret != -1) return ret;
	return ret = DP(x-1) + DP(x-5);
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&t); 
	for(int i = 0; i < t ; i++){
		scanf("%d",&n);
		printf("%lld\n",DP(n));
	}
}