//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;

int memo[MAXN+5];

int tiling(int x){ //남은 2*x 타일을 채우는 경우의 수 
	if(x == 0) return 1;
	if(x < 0) return 0;
	int& ret = memo[x];
	if(ret != -1) return ret;

	return ret = (tiling(x-1)+tiling(x-2))%MOD;
}

int atiling(int x){ //비대칭 타일링 방법의 수 = (타일링 방법 - 대칭 타일링 방법)
	int ret;
	if(x%2)return ((tiling(x) - tiling(x/2))+MOD)%MOD; //둘다 이미 mod 되어있기 떄문에 mod 불필요 
	ret = ((tiling(x) - tiling(x/2)+MOD)%MOD);
	return ret = (ret - tiling((x-1)/2)+MOD)%MOD; 
	//짝수면 2*n타일링 개수 - 반 나눈거(2*(n/2)) 타일링 갯수 - 반 나눈거(2*((n-1)/2)) 중간이 =으로 걸친 경우)
	//홀수면 2*n타일링 개수 - 반 나눈거(2*(n/2))
}

int n;

int main(){
	int c;
	scanf("%d",&c);
	memset(memo,-1,sizeof(memo));
	//printf("92:%d - 46:%d =%d",tiling(92),tiling(46),(tiling(92) - tiling(92/2)));
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		printf("%d\n",atiling(n));
	}
	return 0;
}
