//Made By R3dzone
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
int n;

int arr[MAXN+5];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for(int i = 0; i < n; i++)
		printf("%d\n",arr[i]);
}
