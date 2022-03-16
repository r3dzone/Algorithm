//Made By R3dzone
#include <cstdio>

using namespace std;

typedef long long lint;

const int MAXN = 1024;

int n,m;
int map[MAXN+5][MAXN+5] = {0};
int sum_map[MAXN+5][MAXN+5] = {0};

void make_sum(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			sum_map[i][j] = sum_map[i][j-1] + map[i][j];
}

lint partial_sum(int x1, int x2, int y1, int y2){
	lint res = 0;
	for(int i = y1; i <= y2; i++)
		res += sum_map[i][x2] - sum_map[i][x1-1];
	return res;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d",&map[j][i]);
		} 
	}
	make_sum();
	int x1,x2,y1,y2;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%ld\n",partial_sum(x1,x2,y1,y2));
	}
	return 0;
}
