#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;

int memo[MAXN][MAXN];
char str0[MAXN];
char str1[MAXN];
int str0len;
int str1len;

int n;

int DP(int x , int y){
	if(x >= str1len || y >= str0len) return 0;
	
	int& ret = memo[x][y];
	if(ret != -1) return ret;
	
	if(str1[x] == str0[y])return ret = 1+DP(x+1,y+1);
	return ret = max(DP(x+1,y),DP(x,y+1));
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%s",str0);
	str0len = strlen(str0);
	scanf("%s",str1);
	str1len = strlen(str1);
	printf("%d\n",DP(0,0));
}
