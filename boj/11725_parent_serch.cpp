//Made By R3dzone
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

const int MAXN = 100000;

vector<vector<int> > tree;
int visited[MAXN+5];

void dfs(int x){
	for(int i = 0; i < tree[x].size(); i++){
		int next = tree[x][i];
		if(visited[next] == -1){
			visited[next] = x;
			dfs(next);
		}
	}
}

int main(){
	int tmp1,tmp2;
	memset(visited,-1,sizeof(visited));
	scanf("%d",&n);
	tree = vector<vector<int> >(n+1,vector<int>());
	for(int i = 0; i < n-1; i++){
		scanf("%d %d",&tmp1,&tmp2);
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}
	dfs(1);
	for(int i = 2; i <= n; i++)
		printf("%d\n",visited[i]);
	return 0;
}