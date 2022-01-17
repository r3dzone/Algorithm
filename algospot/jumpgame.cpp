//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;

int ground[MAXN+5][MAXN+5];
int n;
int memo[MAXN+5][MAXN+5];

int func(int y,int x){
	if(y == n-1 && x == n-1) return 1;
	if(y >= n || x >= n)return 0;

	int& ret = memo[y][x];
	if(ret != -1) return ret;

	int len = ground[y][x];
	return ret = (func(y+len,x) + func(y,x+len));
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		memset(memo,-1,sizeof(memo));
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				scanf("%d",&ground[j][k]);
			}
		}
		if(func(0,0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
