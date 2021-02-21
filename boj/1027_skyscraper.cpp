#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50;
double building[MAXN+5];
int n;

int f(int x,int y){ //x���� y�� ���̸� 1 �ƴϸ� 0 
	if(x == y) return 0;
	if(x > y){
		int tmp = y;
		y = x;
		x = tmp;
	}
	if( x+1 == y) return 1;
	
	double incline[MAXN+5];
	
	for(int i = x; i < y;i++){
		double tmpy = y;
		double tmpi = i;
		incline[i] = (building[y]-building[i])/(tmpy-tmpi);
	}
	for(int i = x+1; i < y;i++){
		if(incline[i] <= incline[x]) return 0;	//���Ⱑ �� �۴ٴ°� ���� x��ǥ�϶� y��ǥ�� �� ���ٴ� �ǹ� 
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	int cnt = n;
	while(cnt--)scanf("%lf",&building[n-cnt-1]);

	int finres = 0;
	
	for(int i = 0; i < n; i++){
		int res = 0;
		for(int j = 0; j < n; j++){
			res += f(i,j);
		}
		finres = max(finres,res);
	}
	printf("%d\n",finres);
}
