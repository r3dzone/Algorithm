//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int n,t,tmp;

int memo[2][MAXN+5];
int arr[2][MAXN+5];

int dp(int x, int y){
	if(y >= n) return 0;
	if(y == n-1) return arr[x][y];
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	if(x == 1) return ret = max(dp(0,y+1),max(dp(1,y+2),dp(0,y+2)))+arr[x][y];
	else return ret = max(dp(1,y+1),max(dp(1,y+2),dp(0,y+2)))+arr[x][y];
}

int main(){
	scanf("%d",&t);
	for(int i = 0; i < t ; i++){
		memset(memo,-1,sizeof(memo));
		memset(arr,0,sizeof(arr));
		n = 0;
		scanf("%d",&n);
		
		for(int i = 0; i < n ; i++)scanf("%d",&arr[0][i]);
		for(int i = 0; i < n ; i++)scanf("%d",&arr[1][i]);
		printf("%d\n", max(max(dp(1,1),dp(0,1)),max(dp(1,0),dp(0,0)) ) );
		int tmpmax = 0;
	}
}