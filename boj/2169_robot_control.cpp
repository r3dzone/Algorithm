//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;
const int MAXM = 1e3+5;
const int INF = 1e9;

int arr[MAXN][MAXM];
int memo[3][MAXN][MAXM];
int n,m;

//int x,y,lr == 0:left 1:down 2:right;
int DP(int lr,int i,int j){
	if(i == 0 && j == 0) return arr[i][j];
	if(i < 0 || j < 0 || i >= n || j >= m) return -INF;
	
	int& ret = memo[lr][i][j];
	if(ret != -1) return ret;
	
	if(lr == 0) return ret = max(DP(0,i,j-1),DP(1,i,j-1))+arr[i][j];
	if(lr == 1) return ret = max(DP(0,i-1,j),max(DP(1,i-1,j),DP(2,i-1,j)))+arr[i][j];
	return ret = max(DP(1,i,j+1),DP(2,i,j+1))+arr[i][j];
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("%d\n",max(DP(0,n-1,m-1),DP(1,n-1,m-1)));
}