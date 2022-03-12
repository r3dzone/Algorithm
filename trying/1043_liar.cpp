//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

int n,m,kn;
vector<int> know;
vector<int> parent;
vector<vector<int> > party;

int solve(){
	int cnt = 0;
	for(int i = 0; i < m; i++){
		bool isKnow = false;
		for(int j = 0; j < party[i].size(); j++) //진실을 아는 사람이 있나? 
			if(know[party[i][j]]){
				isKnow = true;
				break;
			}
		if(!isKnow)cnt++;
	}
	return cnt;
}

int find(int x){ // return root
	if(parent[x] == x)return x;
	return find(parent[x]);
}

void merge(int x, int y){//union
	int u = find(x);
	int v = find(y);
	if(u == v) return;
	parent[v] = u;
	return; 
}

int main(){
	scanf("%d %d",&n,&m);
	scanf("%d",&kn);
	know = vector<int>(n+1,0);
	for(int i = 0; i <= n; i++)
		parent.push_back(i);
	int inp,inp2;
	int first = -1;
	for(int i = 0; i < kn; i++){
		scanf("%d",&inp);
		know[inp] = 1;
		if(first == -1) first = inp;
		else merge(first,inp);
	}
	party = vector<vector<int> >(m,vector<int>());
	for(int i = 0; i < m; i++){
		scanf("%d",&inp);
		first = -1;
		for(int j = 0; j < inp; j++){
			scanf("%d",&inp2);
			party[i].push_back(inp2);
			if(first == -1) first = inp2;
			else merge(first,inp2);
		}
	}
	int known_group_root = -1;
	for(int i = 1 ; i <= n; i++){
		if(know[i] == 1){
			known_group_root = find(i);
			break;
		}
	}
	for(int i = 1 ; i <= n; i++){
		parent[i] = find(i);
		if(parent[i] == known_group_root) know[i] = 1;
	}
	printf("%d\n",solve());			
	return 0;
}
