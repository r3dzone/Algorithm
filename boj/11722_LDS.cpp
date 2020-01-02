#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3;

int memo[MAXN+5][MAXN+5];
int arr[MAXN+5];

int n;

int iterDP(){
	for(int i = n-1 ; i >=0 ; i--){
		for(int j = i; j < n; j++){
			if(i == j || i == n-1){
				memo[i][j] = 1;
				memo[i][n] = 1;
				continue;
			}if(arr[i] <= arr[j]){ memo[i][j] = 0;
			}else{
				memo[i][j] = memo[j][n] + 1;
				memo[i][n] = max(memo[i][n],memo[i][j]);
			}
		}
	}
	int tmp = 0;
	for(int i = 0; i < n;i++) tmp = max(tmp,memo[i][n]);
	return tmp;
}

int main(){
	scanf("%d",&n);
	memset(memo,-1,sizeof(memo));
	for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
	printf("%d\n",iterDP());
}