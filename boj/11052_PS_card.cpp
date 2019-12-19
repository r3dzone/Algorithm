#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3;
int memo[MAXN+5];
int arr[MAXN+5];

int n;

int DP(int x){
	if(x <= 0) return 0;
	if(x == 1) return arr[x];
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	int tmp = 0;
	for(int i = 1; i <= x ; i++)
		tmp = max(DP(x-i)+arr[i],tmp);
	return ret = tmp;
	
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	for(int i = 1; i <= n ; i++)
		scanf("%d",&arr[i]);
	printf("%d\n",DP(n));
}