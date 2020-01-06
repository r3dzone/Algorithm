//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;
const int MAXM = 1e3+5;

int arr[MAXN][MAXM];
int pre[2][MAXN][MAXM];
int memo[3][MAXN][MAXM];
int n,m;

void pre(){
	for(int i = 0 ; i < n ; ++i){
			pre[0][i][0] = arr[i][0];
		for(int j = 1; j < m ; ++j){
			pre[0][i][j] = pre[0][i][j-1]+arr[i][j];
		}
	}
	for(int i = 0 ; i < n ; ++i){
			pre[1][i][m-1] = arr[i][m-1];
		for(int j = m-2; j >= 0 ; --j){
			pre[1][i][j] = pre[1][i][j+1]+arr[i][j];
		}
	}
	
}

//int x,y,lr == 0:left 1:right 2:finish;
int DP(int lr,int x,int y){
	if(lr == 0){
		if(y <= 0 )return 0;
	}
	
	int& ret = memo[lr][x][y];
	if(ret != -1) return ret;
	
	int tmp = 0;
	if(lr == 0){
	for(int i = 0 ; i < y ; ++i)
		return tmp = max(DP(2,x-1,i)+(DP(0,x,y-1)-DP(0,x,i-1),tmp);
	return ret = tmp;
	}
	  
	return ret = max(DP(2,x-1,y),max(DP(0,x,y-1),DP(1,x,y+1)));
}

int main(){
	
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("%d\n",DP(2,n-1,m-1));
}
	
	/*
	for(int i = 0 ; i < y ; ++i)
		f(0,x,y) = memo[x-1,i] + (pre0[x][y-1] - pre0[x][i-1]);
	*/