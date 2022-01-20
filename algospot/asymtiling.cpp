//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;

int memo[MAXN+5];

int tiling(int x){ //���� 2*x Ÿ���� ä��� ����� �� 
	if(x == 0) return 1;
	if(x < 0) return 0;
	int& ret = memo[x];
	if(ret != -1) return ret;

	return ret = (tiling(x-1)+tiling(x-2))%MOD;
}

int atiling(int x){ //���Ī Ÿ�ϸ� ����� �� = (Ÿ�ϸ� ��� - ��Ī Ÿ�ϸ� ���)
	int ret;
	if(x%2)return ((tiling(x) - tiling(x/2))+MOD)%MOD; //�Ѵ� �̹� mod �Ǿ��ֱ� ������ mod ���ʿ� 
	ret = ((tiling(x) - tiling(x/2)+MOD)%MOD);
	return ret = (ret - tiling((x-1)/2)+MOD)%MOD; 
	//¦���� 2*nŸ�ϸ� ���� - �� ������(2*(n/2)) Ÿ�ϸ� ���� - �� ������(2*((n-1)/2)) �߰��� =���� ��ģ ���)
	//Ȧ���� 2*nŸ�ϸ� ���� - �� ������(2*(n/2))
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
