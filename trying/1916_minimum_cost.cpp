//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

int n,m;
int stt,ed;
int min_cost = 1234567890;
int total = 0;

const int MAXN = 100000;

vector<vector<pair<int,int> > > graph;
int visited[MAXN+10] = {0};

void dfs(int x){
	visited[x] = 1;
	if(total >= min_cost){
		visited[x] = 0;
		return;
	}
	if(x == ed){
		if(total < min_cost) min_cost = total;
		visited[x] = 0;
		return;
	}
	for(int i = 0; i < graph[x].size(); i++){
		int next = graph[x][i].first;
		if(visited[next] == 0){
			total += graph[x][i].second;
			dfs(next);
			total -= graph[x][i].second;
		}
	}
	visited[x] = 0;
}

int main(){
	scanf("%d %d",&n,&m);
	int inp1,inp2,inp3;
	graph = vector<vector<pair<int,int> > >(m,vector<pair<int,int> >());
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&inp1,&inp2,&inp3);
		graph[inp1].push_back(make_pair(inp2,inp3));
	}
	scanf("%d %d",&stt,&ed);
	dfs(stt);
	printf("%d",min_cost);
	return 0;
}
