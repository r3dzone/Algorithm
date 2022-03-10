//Made By R3dzone
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n,m;
const int MAXN = 1000;
const int INF = 1234567890;

vector<pair<int,int> > graph[MAXN+5];

int dijkstra(int src,int dst){
	vector<int> dist(n+5,INF);
	priority_queue<pair<int,int> > pq;
	dist[src] = 0;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if(dist[here] < cost)
			continue;
		for(int i = 0; i < graph[here].size(); i++){
			int next = graph[here][i].first;
			int nDist = cost + graph[here][i].second;
			if(dist[next] > nDist){
				dist[next] = nDist;
				pq.push(make_pair(-nDist,next));
			}
		}
	}
	return dist[dst];
}

int main(){
	scanf("%d %d",&n,&m);
	int inp1,inp2,inp3;
	int stt,ed;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&inp1,&inp2,&inp3);
		graph[inp1].push_back(make_pair(inp2,inp3));
	}
	scanf("%d %d",&stt,&ed);
	printf("%d",dijkstra(stt,ed));
	return 0;
}
