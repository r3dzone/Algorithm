#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,k,x,y,tmp;

int main(){
	scanf("%d %d %d",&n,&m,&k);	
	x = min(n/2,m); //인턴쉽 안갈때 만들수 있는 팀
	y = k-((n+m)-(3*x)); //잉여인간 인턴쉽 보내고 더 인턴쉽 보내는데 필요한 인원수 
	if(y <= 0){
	printf("%d",x);
	return 0;
	}
	
	if(y%3 == 0)tmp = y/3;
	else tmp = (y/3)+1;
	printf("%d",x-tmp);
}
