//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 20000;

vector<vector<int> > graph;

int serched[MAXN+5];
int longest[2] = {0,0}; //[0] = MAX_cnt [1] = cnt;

void bfs(int x){
	queue<int> que;
	int now = x;
	que.push(now);
	int cnt = 0;
	while(!que.empty()){
		int sz = que.size();
		for(int j = 0; j < sz; j++){
			now = que.front();
			if(cnt > longest[0]){
				longest[0] = cnt;
				longest[1] = 0;
			}
			if(cnt == longest[0])
				longest[1]++;
			for(int i = 0; i < graph[now].size(); i++){
				if(!serched[graph[now][i]]){
					serched[graph[now][i]] = 1;
					que.push(graph[now][i]);
				}
			}
			que.pop();
		}
		cnt++;
	}	
}

int solution(int n, vector<vector<int>> edge) {
    memset(serched,0,sizeof(serched));
    graph = vector<vector<int> >(n+1,vector<int>());
    for(int i = 0; i < edge.size(); i++){
		graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
	}
	serched[1] = 1;
	bfs(1);
    return longest[1];
}

int main(){
	cout << solution(6,{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
	return 0;
}
