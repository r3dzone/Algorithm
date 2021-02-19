#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int paper[105][105];
int n,res;
int x,y;

void paste(int x,int y){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			paper[x+i][y+j] = 1;
		}
	}
}

int chk(){
	res = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(paper[i][j] == 1) res++; 
		}
	}
	return res;
}

int main(){
	scanf("%d",&n);
	memset(paper,1,sizeof(paper));
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		paste(x,y);
	}
	printf("%d\n",chk());
}