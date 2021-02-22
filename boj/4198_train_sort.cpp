//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2000+5;

int memoi[MAXN];
int memod[MAXN];
int arr[MAXN];

int n;

int lis(int x){ //x번째 숫자를 시작으로 하는 가장 긴 증가하는 부분수열의 길이 
	int& ret = memoi[x];
	if(ret != -1) return ret;
	
	int tmp = 0;
	for(int i = x+1; i < n; i++)
		if(arr[x] < arr[i])
			tmp = max(lis(i),tmp);
	return ret = tmp + 1;
}

int lds(int x){ //x번째 숫자를 시작으로 하는 가장 긴 감소하는 부분수열의 길이
	int& ret = memod[x];
	if(ret != -1) return ret;
	
	int tmp = 0;
	for(int i = x+1; i < n; i++)
		if(arr[x] > arr[i])
			tmp = max(lds(i),tmp);
	return ret = tmp + 1;
}

int main(){
	memset(memoi,-1,sizeof(memoi));
	memset(memod,-1,sizeof(memod));
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	int tmp = 0;
	for(int i = 0; i < n; i++)
		tmp = max(tmp,lis(i));
	printf("LIS:%d\n",tmp);
	tmp = 0;
	for(int i = 0; i < n; i++)
		tmp = max(tmp,lds(i));
	printf("LDS:%d\n",tmp);
	
	tmp = 0;
	for(int i = 0; i < n; i++)
		printf("i:%d)LIS:%d LDS:%d\n",i,lis(i),lds(i));
}
