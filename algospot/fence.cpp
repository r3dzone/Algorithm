//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20000;

int h[MAXN+5];

int getMaxSize(int lo, int hi){ //lo부터 hi까지의 울타리에서 만들수 있는 최대 직사각형의 사이즈 
	int ret;
	
	if(lo == hi) return h[lo];
	
	int mid = (lo+hi)/2;				 
	int nlo = mid;
	int nhi = mid+1;
	ret = getMaxSize(lo,mid); 		//분할 정복으로 풀이 = 앞 절반, 뒤 절반, 겹친 경우의 세가지로 확인
	ret = max(ret,getMaxSize(nhi,hi));
	
	int height = min(h[nlo],h[nhi]);
	ret = max(ret,height*2);

	while(lo < nlo || hi > nhi){
		if(nhi < hi && (h[nhi+1] > h[nlo-1] || nlo == lo)){ //nhi가 아직 커질수 있고 nlo가 더 이상 커질 수 없거나 nhi쪽 높이가 더 높으면 
			height = min(height,h[nhi+1]);
			ret = max(ret,height*(nhi+1-nlo+1));
			nhi++;
		}else{
			height = min(height,h[nlo-1]);
			ret = max(ret,height*((nhi-nlo)+2));
			nlo--;
		}
	}
	return ret;		
}

int main(){
	int c,n;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		memset(h,-1,sizeof(h));
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%d",&h[j]);
		}
		printf("%d\n",getMaxSize(0,n-1));
	}
}
