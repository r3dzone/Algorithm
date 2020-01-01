#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100+5;
const int MAXK = 1e4+5;
const int INF = 1e9;

typedef long long lint;

int n,k;
lint memo[MAXN][MAXK];
int arr[MAXN];

lint iterDP(int x,int y){
	for(int i = 0;i < x;i++){
		for(int j = 0;j <= y;j++){
			lint& ret = memo[i][j];
			if(i == 0){
				if(j%arr[i] == 0){
					ret = j/arr[i];
					continue;
				};
				ret = INF;
				continue;
			}
			if(j-arr[i] < 0){
				ret = memo[i-1][j];
				continue;
			}
			ret = min(memo[i][j-arr[i]]+1,memo[i-1][j]);
		}
	}
	return memo[x-1][y];
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
	
	lint tmp = iterDP(n,k);
	if(tmp < INF)
		printf("%lld\n",tmp);
	else puts("-1");
}