#include <cstdio>
#include <algorithm>

using namespace std;

int n,sum;
int arr[1000+5];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for(int i = 0; i < n; ++i)
		sum += arr[i] * (n - i);
	printf("%d",sum);
}