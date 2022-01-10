#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> combination;
const int MAXN = 10;

int fpair[MAXN][MAXN]; //friend pair
int visited[10];
int ans;

void makePairing(int now,int n,vector<int>& vec){	
	if(now >= n) return;
	if(visited[now]) return;
		
	for(int i = now+1; i < n; i++){
		if(fpair[now][i] && (!visited[now]) && (!visited[i])){
			vec.push_back(now);
			vec.push_back(i);
			visited[now] = 1;
			visited[i] = 1;
			if(vec.size() == n){
				ans++;
			}
			for(int j = now+1; j < n; j++)
				makePairing(j,n,vec);
			vec.pop_back();
			vec.pop_back();
			visited[now] = 0;
			visited[i] = 0;
		}
	}
}

int main(){
	int C,n,m;
	int tmp1,tmp2;
	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		memset(fpair,0,sizeof(fpair));
		memset(visited,0,sizeof(visited));
		ans = 0;
		scanf("%d %d",&n,&m);
		for(int j = 0; j < m; j++){
			scanf("%d %d",&tmp1,&tmp2);
			fpair[tmp1][tmp2] = 1;
			fpair[tmp2][tmp1] = 1;
		}
		makePairing(0,n,combination);
		printf("%d\n",ans);
	}
	
	return 0;
}
