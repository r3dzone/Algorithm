//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 50;

int map[MAXN+5][MAXN+5];

int n,m,k;
int cnt;

void func(int x,int y){
	if(x < 0 || y < 0)return;
	if(map[y][x] != 1)return;
	else{
		map[y][x] = cnt;
		func(x-1,y);
		func(x+1,y);
		func(x,y+1);
		func(x,y-1);
	}
}

int main(){
	int t,x,y;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		memset(map,0,sizeof(map));
		cnt = 1;
		scanf("%d %d %d",&m,&n,&k);
		for(int j = 0; j < k; j++){
			scanf("%d %d",&x,&y);
			map[y][x] = 1;
		}
		for(int j = 0; j < n; j++)
			for(int c = 0; c < m; c++){
				if(map[j][c] == 1)cnt++;
				func(c,j);
			}
		printf("%d\n",cnt-1);
	}
}
