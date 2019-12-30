//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 300+5;
const int MAXK = 1e4;

int n,m,k;

int arr[MAXN][MAXN];
int memo[MAXN][MAXN];

int func(int i ,int j, int x, int y){
	int tmp = 0;
	for(int t = i-1 ; t <= x-1; ++t){
		tmp += memo[t][y-1] - memo[t][j-2];
	}
	return tmp;
}

void pre(){
	for(int i = 0 ; i < n; ++i){
		memo[i][0] = arr[i][0];
		for(int j = 1 ; j < m; ++j)
			memo[i][j] = memo[i][j-1] + arr[i][j];
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n; ++i)
		for(int j = 0 ; j < m; ++j)
			scanf("%d",&arr[i][j]);
	scanf("%d",&k);
	pre();
	while(k){
		int i = 0, j = 0 ,x = 0, y = 0;
		scanf("%d %d %d %d",&i,&j,&x,&y);
		printf("%d\n",func(i,j,x,y));
		--k;
	}
}