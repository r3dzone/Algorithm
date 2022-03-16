//Made By R3dzone
#include <cstdio>

using namespace std;

typedef long long lint;

int a,b,c;

lint multiple(lint x){
	if(x == 1) return a%c;
	lint tmp;
	tmp = multiple(x/2);
	tmp = (tmp*tmp)%c;
	if(x%2) 
		tmp = (tmp*a)%c;
	return tmp;
}

int main(){
	scanf("%d %d %d",&a,&b,&c);
	printf("%ld\n",multiple(b));
	return 0;
}
