//Made By R3dzone
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 10000;
int n;

int arr[MAXV+5];
int cnt[MAXV+5] = {0};

int main(){
	int tmp,arrcnt = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp);
		cnt[tmp]++;
		if(cnt[tmp] == 1){
			arr[arrcnt] = tmp;
			arrcnt++;
		}
	}
	sort(arr,arr+arrcnt);
	for(int i = 0; i < arrcnt; i++)
		for(int j = 0; j < cnt[arr[i]];j++)
			printf("%d\n",arr[i]);
}
