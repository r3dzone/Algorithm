//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000;

double memo[MAXN+5][MAXN+5];

double snail(int x, int y){ //y일동안 x미터를 오를수 있는 확률 
	if(x <= 0) return 1;
	if(y <= 0) return 0;
	
	double& ret = memo[x][y];
	if(ret != -1.0)	return ret;

	return ret = (0.25*snail(x-1,y-1)) + (0.75*snail(x-2,y-1)); //sunny 0.25 rainy 0.75
}

int main(){
	int c,n,m;	
	scanf("%d",&c);
	for(int i = 0; i < MAXN+5; i++)
		for(int j = 0; j < MAXN+5; j++)
			memo[i][j] = -1.0;
	
	for(int i = 0; i < c; i++){
		scanf("%d %d",&n,&m);
		printf("%.10lf\n",snail(n,m));
	}
}
