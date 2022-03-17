//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int n,k;

vector<int> graph[MAXN+5]; 

void make_graph(){
	graph[0].push_back(1);
	for(int i = 1; i <= MAXN ; i++){
		graph[i].push_back(i-1);
		graph[i].push_back(i+1);
		if(i <= 50000)
			graph[i].push_back(i*2);
	}
}

void bfs(){
	int cnt = 0;
	int visited[MAXN+5] = {0};
	queue<pair<int,int> > que; //next,dist
	que.push(make_pair(n,0));
	visited[n] = 1;
	int max_dist = MAXN+1;
	while(!que.empty()){
		int here = que.front().first;
		int dist = que.front().second;
		if(max_dist != MAXN+1 && dist > max_dist) break;
		if(here == k){
			if(max_dist == MAXN+1)
				max_dist = dist;
			cnt++;
		}
		que.pop();
		visited[here] = 1;
		for(int i = 0; i < graph[here].size();i++){
			int next = graph[here][i];
			if(visited[next] != 1){
				que.push(make_pair(next,dist+1));
			}
		}
	}
	printf("%d\n%d",max_dist,cnt);
}

int main(){
	scanf("%d %d",&n,&k);
	make_graph();
	bfs();
	return 0;
}
