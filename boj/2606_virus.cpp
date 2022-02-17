//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100;

int  comN,directN;
vector<int> com[MAXN+5];
int visited[MAXN+5] = {0};
int cnt = 0;

int dfs(int x){
	cnt++;
	visited[x] = 1;
	for(int i = 0; i < com[x].size(); i++)
		if(!visited[com[x][i]])dfs(com[x][i]);
	return cnt;
}

int main(){
	int tmp1,tmp2;
	scanf("%d %d",&comN, &directN);
	for(int i = 0; i < directN; i++){
		scanf("%d %d",&tmp1,&tmp2);
		com[tmp1].push_back(tmp2);
		com[tmp2].push_back(tmp1);
	}
	printf("%d\n",dfs(1)-1);
	return 0;
}
