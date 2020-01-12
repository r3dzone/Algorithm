//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;
const int MAXK = 1e5+5;

typedef long long lint;

int n,m,t;
int memo[MAXN];
int DPmemo[MAXK];

int last[MAXK];
int nxt[MAXK];

int psum[MAXN]; //prefixsum
int tmp;
lint tmp2;

void prepro(){
	for(int i = 0; i <= n; ++i){
		if(last[psum[i]] != -1) nxt[last[psum[i]]] = i;
		last[psum[i]] = i;
	}
}

int DP(int x){
	if(x >= n) return 0;
	
	int& ret = DPmemo[x];
	if(ret != -1) return ret;
	
	if(nxt[x] != -1) return ret = max(1+DP(nxt[x]),DP(x+1));
	else return ret = DP(x+1);
}

int main(){
	scanf("%d",&t);
	for(int j = 0; j < t; ++j){
		memset(memo,0,sizeof(memo));
		memset(psum,0,sizeof(psum));
		memset(DPmemo,-1,sizeof(DPmemo));
		memset(nxt,-1,sizeof(nxt));
		memset(last,-1,sizeof(last));
		
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
		prepro();
		printf("%lld %d\n",tmp2%20091101,DP(0));
	}
}