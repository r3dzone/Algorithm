//Made By R3dzone
#include <cstdio>
#include <vector>

using namespace std;

const int MAXK = 1e8;

vector<int> coin;

int n,k;

int solve(){
	int ret = 0;
	for(int i = coin.size()-1; i >= 0; i--){
		if(coin[i] > k)continue;
		ret += k/coin[i];
		k %= coin[i];
	}
	return ret;
}

int main(){
	int tmp;
	scanf("%d %d",&n,&k);
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp);
		coin.push_back(tmp);
	}
	printf("%d\n",solve());
	return 0;
}
