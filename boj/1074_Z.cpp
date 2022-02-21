//Made By R3dzone
#include <cstdio>

using namespace std;

const int MAXN = 15;

int pow2[MAXN+5];

void pre_pow(){
	pow2[0] = 1;
	for(int i = 1; i <= MAXN; i++)
		pow2[i] = pow2[i-1]*2;
}

/*
1|2
3|4
*/
int func(int n, int r, int c){
	int area_end = pow2[n-1] * pow2[n-1];
	if(r == 1 && c == 1) return 0;
	if(pow2[n-1] < r){ //area3 || area4
		if(pow2[n-1] < c){//area4
			return (area_end*3)+func(n-1,r-pow2[n-1],c-pow2[n-1]);
		}else{//area3
			return (area_end*2)+func(n-1,r-pow2[n-1],c);
		}
	}else{ //area1 || area1
		if(pow2[n-1] < c){//area2
			return area_end+func(n-1,r,c-pow2[n-1]);
		}else{//area1
			return func(n-1,r,c);
		}
	}
}

int main(){
	int n,r,c;
	pre_pow();
	scanf("%d %d %d",&n,&r,&c);
	printf("%d\n",func(n,r+1,c+1));
	return 0;	
}
