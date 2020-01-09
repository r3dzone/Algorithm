//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long lint;

const int MAXN = 1e6+5;
const int MAXM = 1e3+5;

int n,m;
int memo[MAXN];
int psum[MAXN]; //prefixsum
int tmp;
lint tmp2;

int main(){	
	memo[0] = 1;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&tmp);
		psum[i] = (psum[i-1] + tmp)%m;
		memo[psum[i]] += 1;
	}
	
	tmp2 = 0;
	for(int i = 0; i < m; ++i){
		if(memo[i] >= 2) tmp2 += (1LL*(memo[i]-1)*(memo[i]))/2;
	}
	printf("%lld\n",tmp2);
}