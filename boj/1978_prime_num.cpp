#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 105;
int n,cnt;

int arr[MAXN];
bool pri[1001];

void pre(){
	pri[1] = 0;
 	for(int i = 2; i <= 1001; ++i)
		if(pri[i] == 1) // prime num
			for(int j = i*i; j <= 1001; j += i)
				pri[j] = 0; // not prime num

}

int main(){
	scanf("%d",&n);
	memset(pri,1,sizeof(pri));
	pre();
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
		if(pri[arr[i]] == 1) ++cnt;
	}
	printf("%d",cnt);
}