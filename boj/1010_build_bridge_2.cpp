//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30 + 5;

int t,n,m;

typedef long long lint;
lint memo[MAXN][MAXN];

int main(){
	scanf("%d",&t);

	while(t--){
		n = 0;
		m = 0;
		memset(memo,-1,sizeof(memo));
		scanf("%d %d",&n,&m);
		lint tmp = 1;
		for(int i = 1 ; i <= n ; i++){
			tmp = (tmp * (m - i +1))/i; 
		}
		printf("%lld\n",tmp);
	}
}