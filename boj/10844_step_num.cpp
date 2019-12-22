//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int MOD = 1e9;
int n;

int memo[MAXN+5][10];

int dp(int x,int y){
	if(y < 0 || y > 9 || (x == 0 && y == 0)) return 0;
	if(x == 0) return 1;
    int& ret = memo[x][y];
	if(ret != -1) return ret;
	return ret = (dp(x-1,y-1) + dp(x-1,y+1)) % MOD; 
}

int main(){
	int tmp = 0;
	memset(memo, -1, sizeof(memo));
	scanf("%d",&n);	
	for(int i = 0 ; i < 10 ; i++) tmp = (tmp + dp(n-1,i)) % MOD;
	printf("%d",tmp);
}

/*
	printf("called %d %d\n", x ,y );
f(x,y) = 현재 자리수(x)에서 현재숫자(y)를 만들수 있는 가지수
		== x번째자리에 y가 나올 수 있는 경우의 수
		= ret f(x-1,y-1) + f(x-1,y+1) 
for(int i = 0 ; i < n ; i++){ 
		for(int j = 0; j < 10; j++)
		printf("memo[%d][%d]:%d ",i ,j,memo[i][j]);
	printf("\n");
	}
*/
