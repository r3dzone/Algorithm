//Made By R3dzone
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1000;

char map[MAXN+5][MAXN+5];
vector<pair<int,int> > graph[MAXN+5][MAXN+5];
int dist[MAXN+5][MAXN+5][2] = {0};

int n,m;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(){
	queue<pair<pair<int,int>,int> > que; //nl.first.first = y, nl.first.second = x, nl.second = 부술 수 있는 벽 수 
	que.push(make_pair(make_pair(1,1),1));
	dist[1][1][1] = 1;
	int y,x,cnt,dist_now;
	while(!que.empty()){
		y = que.front().first.first;
		x = que.front().first.second;
		cnt = que.front().second;
		dist_now = dist[y][x][cnt];
		que.pop();
	
		for(int i = 0; i < 4;i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(map[ny][nx] == '0' && dist[ny][nx][cnt] == 0){
				que.push(make_pair(make_pair(ny,nx),cnt));
				dist[ny][nx][cnt] = dist_now+1;
			}else if(map[ny][nx] == '1' && cnt == 1){
				que.push(make_pair(make_pair(ny,nx),0));
				dist[ny][nx][0] = dist_now+1;
			}
		}
	}
	if(dist[n][m][0] == 0 && dist[n][m][1] == 0) return -1;
	if(dist[n][m][0] > 0 && dist[n][m][1] > 0)
		return min(dist[n][m][0],dist[n][m][1]);
	else return max(dist[n][m][0],dist[n][m][1]);
}

int main(){
	memset(map,-1,sizeof(map));
 	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%s",map[i]+1);
	printf("%d",bfs());
	return 0;
}

/*
4 4
0000
0000
0000
0000

6 4
0000
1110
1000
0000
0111
0000

ans:9
*/
