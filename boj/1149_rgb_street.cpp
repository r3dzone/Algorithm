//Made By R3dzone;
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int memo[MAXN+5][3];
int n;
int arr[MAXN+5][3];

int dp(int x ,int i){
	if(x == n-1) return arr[x][i];
	int& ret = memo[x][i]; 
	if (memo[x][i] != -1) return ret;
	return ret = arr[x][i]+min(dp(x+1,(i+1)%3),dp(x+1,(i+2)%3));
}

int main(){
	memset(memo, -1, sizeof(memo));
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	printf("%d",min(dp(0,0) , min(dp(0,1),dp(0,2))) );
}