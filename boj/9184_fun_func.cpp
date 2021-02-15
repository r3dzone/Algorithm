#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 50+5;

int memo[MAXN][MAXN][MAXN];

int w(int a,int b,int c){
	
	if( a <= 0 || b <= 0 || c <= 0){
		return 1;
	}else if(a > 20 || b > 20 || c > 20){
		return w(20, 20, 20);
	}
	
	int &ret = memo[a][b][c];
	if(ret != -1) return ret;
	
	if(a < b && b < c){
		ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return ret;
	}else{
		ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		return ret;
	}
}

int main(){
	int a,b,c;
	
	memset(memo,-1,sizeof(memo));
	
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		if(a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
}

/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns: //음수가 있으면 
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns: //20 넘는 수가 있으면 
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns: // a가 b보가 작고 b가 c 보다 작으면 
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:	// 다 아니 
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
*/
