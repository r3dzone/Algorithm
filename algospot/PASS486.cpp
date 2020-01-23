#include <cstdio>

typedef long long lint;
using namespace std;

const int MAXN = 400+5;
const int MAXM = 1e7+5;
int factor_num[MAXM];
int c,n,lo,hi;

void pre(){
	for(int i = 1; i <= MAXM; ++i)
		for(int j = i; j <= MAXM; j+=i) //i multipler;
			++factor_num[j];  
}

int func(int n,int lo,int hi){
	int cnt = 0;
	for(int i = lo; i <= hi; ++i)
		if(factor_num[i] == n) ++cnt;
	return cnt;
}

int main(){
	pre();
	scanf("%d",&c);
	while(c){
		scanf("%d %d %d",&n,&lo,&hi);
		printf("%d\n",func(n,lo,hi));
		--c;
	}
}