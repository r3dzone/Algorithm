#include <cstdio>

using namespace std;
typedef long long lint;

const int MAXN = 1e6+5;
const int MAXM = (2e9)+5;

int n;
int m;
int val[MAXN];

bool f(int x){
	lint sum = 0;
	for(int i = 0; i < n; ++i){
		if(val[i] - x >= 0)sum += val[i] - x;
	}
	return sum >= m; 
}

int binsearch(){
	int l = 0;
	int r = MAXM;
	int mid = 0;
	
	while(l+1 != r){
		mid = (l+r) >> 1;
		if(f(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	
	return l;	
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; ++i){
		scanf("%d",&val[i]);
	}
	printf("%d",binsearch());	
}