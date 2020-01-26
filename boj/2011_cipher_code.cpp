//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 5000+5;
const int MOD = 1e6;

int n;
int memo[MAXN];
char cipher[MAXN];

int DP(int x){
	if(x >= strlen(cipher)) return 0;
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	
	if(x == strlen(cipher)-1){
		if(cipher[x] >= '1' && cipher[x] <= '9') return ret = 1;
	}
	
	if(x == strlen(cipher)-2){
		int tmp = 0;
		if(cipher[x] == '1' && (cipher[x+1] >= '0' && cipher[x+1] <= '9' )) ++tmp;
		if(cipher[x] == '2' && (cipher[x+1] >= '0' && cipher[x+1] <= '6')) ++tmp;
		if(cipher[x] >= '1' && cipher[x] <= '9' && cipher[x+1] >= '1' && cipher[x+1] <= '9') ++tmp;
		if(ret == 2) return ret = 1 + DP(x+1);
		return ret = tmp;
	}
	
	if(cipher[x] == '1'){
		if(x+1 <= strlen(cipher) && (cipher[x+1] >= '0' && cipher[x+1] <= '9'))
			return ret = (DP(x+2)+DP(x+1))%MOD;
	}
	if(cipher[x] == '2'){
		if(x+1 <= strlen(cipher) && (cipher[x+1] >= '0' && cipher[x+1] <= '6'))
			return ret = (DP(x+2)+DP(x+1))%MOD;
	}
	if(cipher[x] >= '1' && cipher[x] <= '9') return ret = DP(x+1);
	return ret = 0;
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%s",cipher);
	printf("%d\n",DP(0));
}
