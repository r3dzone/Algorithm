//Made By R3dzone
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
const int MAXM = 10000; 
const int INF = 1234567890;

int n,m,x;

int min_dist[MAXN+5][2]; //[0]:stt에서 n까지의 최소거리, [1]: n에서 stt까지의 최소거리; 
vector<pair<int,int> > graph[2][MAXN+5];

void dijkstra(int src, int rev){ //rev:0 정방향 ,1 역방향 
	vector<int> dist(n+5,INF);
	priority_queue<pair<int,int> > pq; //cost,dst;
	
	pq.push(make_pair(0,src));
	dist[src] = 0;
	while(!pq.empty()){
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[rev][here].size(); i++){
			int next = graph[rev][here][i].first;
			int ndist = graph[rev][here][i].second + cost;
			if(dist[next] > ndist){
				dist[next] = ndist;
				pq.push(make_pair(ndist,next));
			}
		}
	}
	for(int i = 1; i <= n; i++)
		min_dist[i][rev] = dist[i];
}

int main(){ 
	int inp1,inp2,inp3;
	scanf("%d %d %d",&n,&m,&x);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&inp1,&inp2,&inp3);
		graph[0][inp1].push_back(make_pair(inp2,inp3));
		graph[1][inp2].push_back(make_pair(inp1,inp3));
	}
	dijkstra(x,0);
	dijkstra(x,1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(min_dist[i][0]+min_dist[i][1],ans);
	printf("%d",ans);
	return 0;
}
