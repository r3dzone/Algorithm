//Made By R3dzone
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,v;

vector<vector<int> > adj;
vector<int> dfs_visited;
vector<int> dfs_order;
vector<int> bfs_order;

void dfs(int x){
	dfs_order.push_back(x);
	dfs_visited[x] = 1;
	sort(adj[x].begin(),adj[x].end());
	for(int i = 0; i < adj[x].size(); i++){
		int next = adj[x][i];
		if(dfs_visited[next] == -1)dfs(next);
	}
}

void print_order(){
	for(int i = 0; i < dfs_order.size();i++)
		printf("%d ",dfs_order[i]);
	printf("\n");
	for(int i = 0; i < bfs_order.size();i++)
		printf("%d ",bfs_order[i]);
	printf("\n");
}

void bfs(int x){
	vector<int> discoverd(n+1,0);
	queue<int> q;
	int here;
	q.push(x);
	discoverd[x] = 1;
	while(!q.empty()){
		here = q.front();
		bfs_order.push_back(here);
		q.pop();
		sort(adj[here].begin(),adj[here].end());
		for(int i = 0; i < adj[here].size(); i++){
			int next = adj[here][i];
			if(!discoverd[next]){
				discoverd[next] = 1;
				q.push(next);
			}
		}
	}
}

int main(){
	int inp1,inp2;
	scanf("%d %d %d",&n,&m,&v);
	adj = vector<vector<int> >(n+1,vector<int>());
	dfs_visited = vector<int>(n+1,-1);
	for(int i = 0; i < m;i++){
		scanf("%d %d",&inp1,&inp2);
		adj[inp1].push_back(inp2);
		adj[inp2].push_back(inp1);
	}
	dfs(v);
	bfs(v);
	print_order();
	return 0;
}
