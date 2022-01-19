//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;
const int MOD = 1000000007;

int memo[MAXN+5];

int tiling(int x){ //���� 2*xũ���� �簢���� ä��� ����� ���� ��ȯ 
	if(x == 0) return 1; 
	if(x < 0) return 0;
	int& ret = memo[x];
	if(ret != -1) return ret;

	return ret = (tiling(x-1)%MOD + tiling (x-2)%MOD)%MOD; 
	// |���� ��ĭ ���� �� ��� + =���� ��ĭ ������ ���   
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
