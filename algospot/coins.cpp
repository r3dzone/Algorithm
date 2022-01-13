#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXM = 5000;
const int MOD = 1000000007;

int memo[MAXM+5];
vector<int> coin;

int change(int x){
	memo[0] = 1;
	int tmp;
	for(int i = 0; i < coin.size(); i++){
		for(int j = 0; j <= x ;j++){
			tmp = j - coin[i];
			if(tmp < 0) continue;
			memo[j] = (memo[j]%MOD + memo[tmp]%MOD)%MOD;
		}
		/*
		printf("\n%d번째 반복: ",i);
		for(int j = 0; j <= x ;j++){
			printf("%d ",memo[j]); 
		}
		*/
	}
	return memo[x];
}

int main(){
	int t,m,c;
	int tmp;
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d %d",&m,&c);
		memset(memo,0,sizeof(memo));
		for(int j = 0; j < c; j++){
			scanf("%d",&tmp);
			coin.push_back(tmp);
		}
		sort(coin.begin(),coin.end());
		printf("%d\n",change(m));
		coin.clear();
	}
}
