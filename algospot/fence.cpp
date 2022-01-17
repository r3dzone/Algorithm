//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 20000;

int h[MAXN+5];

int getMaxSize(int lo, int hi){ //lo���� hi������ ��Ÿ������ ����� �ִ� �ִ� ���簢���� ������ 
	int ret;
	
	if(lo == hi) return h[lo];
	
	int mid = (lo+hi)/2;				 
	int nlo = mid;
	int nhi = mid+1;
	ret = getMaxSize(lo,mid); 		//���� �������� Ǯ�� = �� ����, �� ����, ��ģ ����� �������� Ȯ��
	ret = max(ret,getMaxSize(nhi,hi));
	
	int height = min(h[nlo],h[nhi]);
	ret = max(ret,height*2);

	while(lo < nlo || hi > nhi){
		if(nhi < hi && (h[nhi+1] > h[nlo-1] || nlo == lo)){ //nhi�� ���� Ŀ���� �ְ� nlo�� �� �̻� Ŀ�� �� ���ų� nhi�� ���̰� �� ������ 
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
