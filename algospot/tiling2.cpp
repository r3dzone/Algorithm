//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MOD = 1000000007;

int memo[MAXN+5];

int tiling(int x){ //남은 2*x크기의 사각형을 채우는 경우의 수를 반환 
	if(x == 0) return 1; 
	if(x < 0) return 0;
	int& ret = memo[x];
	if(ret != -1) return ret;

	return ret = (tiling(x-1)%MOD + tiling (x-2)%MOD)%MOD; 
	// |으로 한칸 차지 한 경우 + =으로 두칸 차지한 경우   
}

int main(){
	int c,n;
	scanf("%d",&c);
	memset(memo,-1,sizeof(memo));
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		printf("%d\n",tiling(n));
	} 
	return 0;
}
