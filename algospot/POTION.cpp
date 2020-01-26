#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXI = 1e3+5;

int c,n;
int r[MAXI];
int p[MAXI];

int gcd(int a,int b){
	if(a%b == 0) return b;
	return gcd(b,a%b);
}

void func(){
	int tmp = r[0]; // gcd r's
	for(int i = 1; i < n; ++i)
		tmp = gcd(tmp,r[i]);
	for(int i = 0; i < n; ++i)
		r[i] /= tmp;
	
	int multi = 1;
	for(int i = 1; i < MAXI; ++i){
		int flag = 1;
		for(int j = 0; j < n; ++j){
			if((r[j]*i) < p[j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			multi = i;
			break;
		}
	}
	//printf("%d\n",multi);
	for(int i = 0; i < n; ++i)
		//printf("%d ",r[i]); 
		printf("%d ",(r[i]*multi)-p[i]);
	puts("");
}

int main(){
	scanf("%d",&c);
	while(c){
		memset(r,0,sizeof(r));
		memset(p,0,sizeof(p));
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d",&r[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d",&p[i]);
		func();
		--c;
	}
}