//Made By R3dzone;
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;

int ps[MAXN];
int n,m;

int main(){
	int tmp = 0,tmp1,tmp2;
	scanf("%d",&n);
	for(int i = 1; i <= n ; ++i){
		scanf("%d",&tmp);
		ps[i] = tmp+ps[i-1];
	}
	
	scanf("%d",&m);
	for(int i = 1; i <= m ; ++i){
		scanf("%d %d",&tmp1,&tmp2);
		printf("%d\n",ps[tmp2]-ps[tmp1-1]);
	}
	
}