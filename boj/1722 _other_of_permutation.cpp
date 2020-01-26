#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20+5;
int arr[MAXN];
int n,m;
long long k;
long long facto[MAXN];
int sol[MAXN];
vector<int> num;

void func(long long x){
	if(x == -1){
		long long tmp = 0;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j)
				if(arr[i] == num[j]){
					cnt = j;
					break;
				}
			num.erase(num.begin()+cnt);
			tmp += cnt*facto[n-i-1];
		}
		printf("%lld",tmp+1);
	}	
	else{
		memset(sol,0,sizeof(sol));
		long long tmp = x;
		for(int i = n; i > 0; --i){
			sol[i] = tmp/facto[i-1];
			tmp = tmp%facto[i-1];
			printf("%d ",num[sol[i]]);
			num.erase(num.begin()+sol[i]);
		}
	}
}

void pre(){
	facto[0] = 1;
	int tmp = 0;
	for(int i = 1; i < 21; ++i){
		facto[i] = facto[i-1] * i;
	}
	for(int i = 0; i < 21; ++i){
		++tmp;
		num.push_back(tmp);
	}
}

int main(){
	pre();
	scanf("%d %d",&n,&m);
	if(m == 1){
		scanf("%lld",&k);
		func(k-1);
	}
	if(m == 2){
		for(int i = 0; i < n;++i)
			scanf("%d",&arr[i]);
		func(-1);
	}
}