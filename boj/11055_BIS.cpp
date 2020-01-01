//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e3+5;

int memo[MAXN];
int arr[MAXN];

int n;

int DP(int x){
	int& ret = memo[x];
	if(ret != -1) return ret;
	
	int tmp = 0;
	for(int i = x+1; i < n; i++ )
		if(arr[x] < arr[i])
			tmp = max(DP(i),tmp);
	return ret = tmp+arr[x];
}

int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	int tmp = 0;
	for(int i = 0; i < n; i++)
		tmp = max(tmp,DP(i));
	
	printf("%d\n",tmp);
}