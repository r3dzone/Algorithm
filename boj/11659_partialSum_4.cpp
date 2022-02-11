//Made By R3dzone
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100000;

int n,m;

int arr[MAXN+5];
int partialSum[MAXN+5];

void makePartialSum(){ //partialSum[i] = i-1까지의 합이 저장 
	partialSum[0] = 0;
	for(int i = 1; i <= n; i++)
		partialSum[i] = partialSum[i-1] + arr[i-1];
}

int solve(int x,int y){ //i는 0부터 시작, 입력은 1부터 시작 
	return partialSum[y] - partialSum[x-1];
}

int main(){
	int x,y;
	memset(arr,0,sizeof(arr));
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	makePartialSum();
	for(int i = 0; i < m; i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",solve(x,y));
	}
}
