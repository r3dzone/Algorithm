//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

const int MAXG = 1000;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

vector<int> adj[MAXG];
vector<int> visited;
int installed;

int dfs(int here){
	int flag[3] = {0,0,0}; //UNWATCH,WATCH,INSTALL
	visited[here] = UNWATCHED;
	for(int i = 0; i < adj[here].size(); i++){
		int next = adj[here][i];
		if(visited[next] == -1)
			flag[dfs(next)]++;
	}
	if(flag[UNWATCHED]){
		installed++;
		return visited[here] = INSTALLED;
	}
	if(flag[INSTALLED])
		return visited[here] = WATCHED;
	return visited[here];
}

int cameraNum(int x){
	installed = 0;
	visited.clear();
	for(int i = 0; i < x; i++)
		if(visited[i] == -1 && dfs(i) == UNWATCHED)installed++;
	return installed;
}

int main(){
	int c,g,h;
	int stt,end;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&g,&h); //갤러리수, 복도수;
		visited = vector<int>(g,-1);
		for(int j = 0; j < g; j++)
			adj[j].clear();
		for(int j = 0; j < h; j++){
			scanf("%d %d",&stt,&end);
			adj[stt].push_back(end);
			adj[end].push_back(stt);
		}
		printf("%d\n",cameraNum(g));		
	}	
	return 0;
}
