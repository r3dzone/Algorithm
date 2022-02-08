//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

const int MAXG = 1000;
const int UNWATCHED = 1;
const int WATCHED = 2;

vector<int> adj[MAXG];
vector<int> visited;
int installed;

void dfs(int here,int parent){
	visited[here] = UNWATCHED;
	if(adj[here].size() == 1)return; //간선이 부모랑만 있음 == leaf;
	for(int i = 0; i < adj[here].size(); i++){
		if(visited[i] == -1)dfs(adj[here][i]);
		if(visited[i] == UNWATCHED){//안봐지는게 있으면 
			visited[here] = WATCHED;
			installed++;
		}
	}
	return;
}

int cameraNum(){
	
}

int main(){
	int c,g,h;
	int stt,end;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		adj.clear();
		scanf("%d %d",&g,&h); //갤러리수, 복도수; 
		for(int j = 0; j < h; j++){
			scanf("%d %d",&stt,&end);
			adj[stt].push_back(end);
			adj[end].push_back(stt);
		}
		printf("%d\n",cameraNum());		
	}	
	return 0;
}
