//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int n;
int tri[MAXN+5][MAXN+5];
int trimemo[MAXN+5][MAXN+5];
int cntmemo[MAXN+5][MAXN+5];

int tripath(int y,int x){
	if(y == n-1)return tri[y][x];
	
	int& ret = trimemo[y][x];
	if(ret != -1)return ret;
	
	return ret = tri[y][x] + max(tripath(y+1,x),tripath(y+1,x+1));
}

int tripathcnt(int y,int x){
	if(y == n-1)return 1;
	
	int& ret = cntmemo[y][x];
	if(ret != -1)return ret;
	
	int fst = tripath(y+1,x);
	int sec = tripath(y+1,x+1);
	
	int trimax = max(fst,sec);
	if(fst == sec)return ret = tripathcnt(y+1,x) + tripathcnt(y+1,x+1);
	if(fst > sec)return ret = tripathcnt(y+1,x);
	return ret = tripathcnt(y+1,x+1);
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		memset(trimemo,-1,sizeof(trimemo));
		memset(cntmemo,-1,sizeof(cntmemo));
		for(int j = 0; j < n; j++)
			for(int k = 0; k <= j; k++)
				scanf("%d",&tri[j][k]);
		printf("%d\n",tripathcnt(0,0));
	}
	return 0;
}
