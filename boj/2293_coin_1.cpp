#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 100+5;
const int MAXK = 1e4+5;

int n,k;
int memo[2][MAXK];
int arr[MAXN];

int iterDP(int x,int y){
	for(int i = 0;i < x;i++){
		for(int j = 0;j <= y;j++){
			int& ret = memo[i%2][j];
			if(i == 0){
				if(j%arr[i] == 0){
					ret = 1;
					continue;
				};
				ret = 0;
				continue;
			}
			if(j-arr[i] < 0){
				ret = memo[(i+1)%2][j];
				continue;
			}
			ret = memo[i%2][j-arr[i]]+memo[(i+1)%2][j];
		}
	}
	return memo[(x-1)%2][y];
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0;i < n;i++) scanf("%d",&arr[i]);
	printf("%d\n",iterDP(n,k));
}