//Made By R3dzone
#include <cstdio>

using namespace std;

const int MAXN = 100;

int map[MAXN+5][MAXN+5]; //[y][x]; 0:no cheese 1:cheese 2:air 

int n,m;
int cheese = 0;
int time = 2;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void air(int x,int y){
	if(map[y][x] == 1 || map[y][x] == time) return;
	map[y][x] = time;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ny >= 0 && nx >= 0 && ny < n && nx < m)
			air(nx,ny);
	}
}

int melt(){
	while(cheese){
		air(0,0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(map[i][j] == 1){
					int cnt = 0;
					for(int c = 0; c < 4; c++){
						int nx = j+dx[c];
						int ny = i+dy[c];
						if(ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] == time)
							cnt++;
					}
					if(cnt >= 2){
						map[i][j] = 0;
						cheese--;
					}
				}else continue;
			}
		}
		time++;
	}
	return time-2;
}

int main(){
	
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d",&map[i][j]);
			if(map[i][j])cheese++;
		}
	}

	printf("%d",melt());
	return 0;
}
