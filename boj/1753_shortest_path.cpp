//Made By R3dzone
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 20000;
const int INF = 1234567890;

int v,e,k;

vector<pair<int,int> > graph[MAXN+5]; 
vector<int> dist;

void print_dist(){
	for(int i = 1; i <= v;i++){
		if(dist[i] == INF)printf("INF\n");
		else printf("%d\n",dist[i]);
	}
}

void dijkstra(int stt){
	priority_queue<pair<int,int> > pq; //first = -dist , second = next 
	pq.push(make_pair(0,stt));
	dist = vector<int>(v+5,INF);
	dist[stt] = 0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[here].size(); i++){
			int next = graph[here][i].first;
			int ndist = cost+graph[here][i].second;
			if(ndist < dist[next]){
				dist[next] = ndist;
				pq.push(make_pair(-ndist,next));
			}
		}
	}
	print_dist();
}

int main(){
	int inp1,inp2,inp3;
	scanf("%d %d %d",&v,&e,&k);
	for(int i = 0; i < e; i++){
		scanf("%d %d %d",&inp1,&inp2,&inp3);
		graph[inp1].push_back(make_pair(inp2,inp3));
	}
	dijkstra(k);
	return 0;
}
