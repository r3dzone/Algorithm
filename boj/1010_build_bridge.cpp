//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30 + 5;

int t,n,m;

typedef long long lint;
lint memo[MAXN][MAXN];

lint dp(int x,int y){
	if(y > (m-n)+x) return 0;
	if(y == (m-n)+x) return 1;
	
	lint& ret = memo[x][y];
	if(ret != -1)return ret;
		
	if(x == n-1){
		if(y == m-1) return ret = 1;
		return ret = dp(x,y+1)+1;
	}
	return ret = dp(x,y+1) + dp(x+1,y+1);
}

int main(){
	scanf("%d",&t);

	while(t--){
		n = 0;
		m = 0;
		memset(memo,-1,sizeof(memo));
		scanf("%d %d",&n,&m);
		printf("%lld\n",dp(0,0));
	}
}