#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 750;

int mine[MAXN+5][MAXN+5][5]; //[y][x][4]: 광산 [y][x][0]: x,y를 시작으로 왼쪽위쪽(LU)으로 향하는대각선 [1]:RU  [2]:RD [3]:LD
int r,c;

int dx[4] = {-1,1,1,-1};
int dy[4] = {1,1,-1,-1};

int f(int y,int x,int dir){ //x,y에서 dir방향으로의 대각선 길이 
	if(mine[y][x][4] != 1){ 
		return 0;
	}
	int res = 1;
	while(1){
		if(x+dx[dir] < 0 || y+dy[dir] < 0 || x+dx[dir] >= c || y+dy[dir] >= r) return res;
		x += dx[dir];
		y += dy[dir];
		if(mine[y][x][4] != 1) return res;
		res++;
	}
}

void pre(){ //4*O(N^2)
	for(int k = 2;k < 4;k++){
		for(int i = r-1;i >= 0;i--){
			for(int j = 0;j < c;j++){
				mine[i][j][k] = f(i,j,k);
			}
		}
	}
}

int diamond(int y,int x){ //x,y를 위쪽 꼭지점으로 갖는 다이아몬드의 최대크기 
	int maxlen = min(mine[y][x][2],mine[y][x][3]);
	while(maxlen > 0){
		if(mine[y+((maxlen-1)*dy[3])][x+((maxlen-1)*dx[3])][2] >= maxlen && mine[y+((maxlen-1)*dy[2])][x+((maxlen-1)*dx[2])][3] >= maxlen) return maxlen;
		maxlen--;
	}
	return 0;
}

int main(){
	scanf("%d %d",&r,&c);
	for(int i = r-1;i >= 0;i--){
		for(int j = 0;j < c;j++){
			scanf("%1d",&mine[i][j][4]);
		}
	}
	pre();
	int res = 0;
	for(int i = r-1;i >= 0;i--){
		for(int j = 0;j < c;j++){
			res = max(res,diamond(i,j));
		}
	}
	printf("%d\n",res);
}
