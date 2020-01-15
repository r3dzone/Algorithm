//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int n;
int memo[5005];

int DP(int x){
	if(x < 0) return INF;
	if(x == 0) return 0;
	
	int& ret = memo[x];
	if(ret != -1)return ret;
	
	return ret = min(DP(x-3)+1,DP(x-5)+1);
}


int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	int tmp = DP(n);
	if(tmp >= INF) tmp = -1;
	printf("%d",tmp);
}