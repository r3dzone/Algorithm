//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2000+5;
const int MAXM = 1e6+5;

int n,m;
int arr[MAXN];
int memo[MAXN][MAXN];

int DP(int x, int y){
	if((y-x)<= 0) return 1;
	if((y-x) == 1)
		return (arr[x] == arr[y]);
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	
	return ret = (arr[x] == arr[y]) && DP(x+1,y-1); 
}

int main(){
	int tmp0,tmp1;
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	scanf("%d",&m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d",&tmp0,&tmp1);
		printf("%d\n",DP(tmp0-1,tmp1-1));
	}
	
}