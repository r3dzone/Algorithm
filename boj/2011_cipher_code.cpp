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
	if(x > strlen(cipher)) return 0;
	if(x == strlen(cipher)-1 && cipher[x] >= '1' && cipher[x] <= '9') return 1;
	
	int& ret = memo[x];
	if(ret != -1) return ret;
	
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
	for(int i = 1 ; i < strlen(cipher); ++i )
		printf("%d:%d\n",i,DP(i));
}
