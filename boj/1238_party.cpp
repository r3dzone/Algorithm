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

int min_dist[MAXN+5][2]; //[0]:stt���� n������ �ּҰŸ�, [1]: n���� stt������ �ּҰŸ�; 
vector<pair<int,int> > graph[MAXN];

int dijkstra(int src, int dst){
	vector<int> dist(n+5,INF);
	priority_queue<pair<int,int> > pq; //cost,dst;
	
	pq.push(make_pair(0,src));
	dist[src] = 0;
	while(!pq.empty()){
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[here].size(); i++){
			int next = graph[here][i].first;
			int ndist = graph[here][i].second + cost;
			if(dist[next] > ndist){
				dist[next] = ndist;
				pq.push(make_pair(ndist,next));
			}
		}
	}
	if(src == x)
		for(int i = 1; i <= n; i++)
			min_dist[i][0] = dist[i];
	return dist[dst];
}

int main(){

//�����ع��� ���������� X�� �ϴ� dijkstra�� ���� �ִܰŸ��� ������ �Ÿ��� �˼� �ְ�
//���� ������ X�� ���� �ּҰŸ��� ������ ���� �ִ밪�� ��ȯ�ϸ� �ȴ�.
//�ٵ� �ð����⵵�� �ǳ�? 
	int inp1,inp2,inp3;
	scanf("%d %d %d",&n,&m,&x);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d",&inp1,&inp2,&inp3);
		graph[inp1].push_back(make_pair(inp2,inp3));
	}
	for(int i = 1; i <= n; i++)
		min_dist[i][1] = dijkstra(i,x);
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(min_dist[i][0]+min_dist[i][1],ans);
	printf("%d",ans);
	return 0;
}
