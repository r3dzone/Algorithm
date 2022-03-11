//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

int n,m,kn;
vector<int> know;
vector<vector<int> > party;

void isTruth(int x){
	bool isKnow = false;
	for(int i = 0; i < party[x].size(); i++) //진실을 아는 사람이 있나? 
		if(know[party[x][i]]){
			isKnow = true;
			break;
		}
	
	if(isKnow){
		for(int i = 0; i < party[x].size(); i++)
			know[party[x][i]] = 1; //파티에 있던 애들 전부 사실을 알게됨 
		return;
	}else{
		return;
	}
}

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

int main(){
	scanf("%d %d",&n,&m);
	scanf("%d",&kn);
	know = vector<int>(n+1,0);
	int inp,inp2;
	for(int i = 0; i < kn; i++){
		scanf("%d",&inp);
		know[inp] = 1;
	}
	party = vector<vector<int> >(m,vector<int>());
	for(int i = 0; i < m; i++){
		scanf("%d",&inp);
		for(int j = 0; j < inp; j++){
			scanf("%d",&inp2);
			party[i].push_back(inp2);
		}
		isTruth(i);
	}
	printf("%d",solve());
	return 0;
}
