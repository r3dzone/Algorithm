//Made By R3dzone
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXL = 64;

int x,cnt;

//i is sum of stick len; 
//j is smallest stick;
int stick(int i,int j){
	if(i > x){
		j /= 2;
		cnt += 1;
		if((i - j)>= x){
			i -= j;
			cnt -= 1;
		}
		return stick(i,j);
	}else return cnt;
}

int main(){
	cnt = 1;
	scanf("%d",&x);
	printf("%d\n",stick(MAXL,MAXL));
}