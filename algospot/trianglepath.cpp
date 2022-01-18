//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int tri[MAXN+5][MAXN+5];
int memo[MAXN+5][MAXN+5];

int n;

int DP(int y,int x){
	if(y == n-1) return tri[y][x];

	int& ret = memo[y][x];
	if(ret != -1) return ret;

	int now = tri[y][x];
	return ret = max((now+DP(y+1,x)),(now+DP(y+1,x+1)));
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		memset(memo,-1,sizeof(memo));
		for(int j = 0; j < n; j++){
			for(int k = 0; k < j+1; k++){
				scanf("%d",&tri[j][k]);
			}
		}
		printf("%d\n",DP(0,0));
	}

	return 0;
}
