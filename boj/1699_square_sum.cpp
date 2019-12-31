//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;
const int square = 340;
const int INF = 1e9;
int n;
int memo[MAXN];
int square_num[square];

void pre(){
	for(int i = 0; i <= square;++i)
		square_num[i] = i*i;
}

int DP(int x){
	if(x < 0) return INF;
	if(x == 0) return 0;
	if(x == 1) return 1;
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	
	int tmp = INF;
	for(int i = 1; i <= square; ++i){
		if(square_num[i] > x) break;
		tmp = min(DP(x-square_num[i])+1,tmp);
	}
	return ret = tmp;
}

int main(){
	pre();
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	printf("%d\n",DP(n));
}