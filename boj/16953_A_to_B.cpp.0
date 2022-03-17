//Made By R3dzone
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 123456890;

typedef long long lint;

int a,b;

lint dp(lint x){ //x부터 B까지 필요한 연산의 최솟값;
	if(x == b) return 1;
	if(x > b) return INF;
	
	return min(dp(x*2)+1,dp((x*10)+1)+1);
}

int main(){
	scanf("%d %d",&a,&b);
	int res = dp(a);
	if(res >= INF)printf("-1\n");
	else printf("%d\n",res);
	return 0;
}
