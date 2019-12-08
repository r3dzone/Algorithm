//Made By R3dzone;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 300;
int memo[MAXN+5][2];
int arr[MAXN+5];
int n;

int dp(int x,int j){
	int& ret = memo[x][j];
	if (ret != -1) return ret;
	if(x == n) return ret = arr[x];
	if(x == n-1 && j == 0) return ret = arr[x] + arr[x+1];
	if(x == n-1 && j == 1) return ret = 0;
	if(x == n-2) return ret = arr[x] + arr[x+2];
	if(j == 0) return ret = max(dp(x+1,1),dp(x+2,0)) + arr[x];
	return ret = dp(x+2,0) + arr[x];
}

int main(){
	scanf("%d",&n);
	memset(memo, -1, sizeof(memo));
	--n;
	for(int i = 0; i<= n ;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",max(dp(0,0),dp(1,0) ));
}