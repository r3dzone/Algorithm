//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
const int INF = 1234567890;

int n,k;

vector<pair<int,int> > graph[MAXN+5]; 

void make_graph(){
	graph[0].push_back(make_pair(1,1));
	for(int i = 1; i < MAXN ; i++){
		graph[i].push_back(make_pair(i-1,1));
		graph[i].push_back(make_pair(i+1,1));
		if(i <= 50000)
			graph[i].push_back(make_pair(i*2,0));
	}
	graph[MAXN].push_back(make_pair(MAXN-1,1));
}

void dijkstra(){
	vector<int> dist(MAXN+5,INF);
	priority_queue<pair<int,int> > pq; //dist,next
	pq.push(make_pair(0,n));
	dist[n] = 0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[here].size();i++){
			int next = graph[here][i].first;
			int ndist = cost + graph[here][i].second; 
			if(ndist < dist[next]){
				dist[next] = ndist;
				pq.push(make_pair(-ndist,next));
			}
		}
	}
	printf("%d",dist[k]);
}

int main(){
	scanf("%d %d",&n,&k);
	make_graph();
	dijkstra();
	return 0;
}
