#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,k,x,y,tmp;

int main(){
	scanf("%d %d %d",&n,&m,&k);	
	x = min(n/2,m); //���Ͻ� �Ȱ��� ����� �ִ� ��
	y = k-((n+m)-(3*x)); //�׿��ΰ� ���Ͻ� ������ �� ���Ͻ� �����µ� �ʿ��� �ο��� 
	if(y <= 0){
	printf("%d",x);
	return 0;
	}
	
	if(y%3 == 0)tmp = y/3;
	else tmp = (y/3)+1;
	printf("%d",x-tmp);
}
