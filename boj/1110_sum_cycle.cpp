#include <stdio.h>

int n,cnt,fi;
int te,on,ne_on;

int sum_cycle(int x){
	if(x == n) ++fi;
	if(fi == 2) return cnt; 
	te = x/10;
	on = x%10;
	ne_on = (te + on)%10;
	++cnt;
	sum_cycle(on*10+ne_on);
}

int main(){
	scanf("%d",&n);
	printf("%d",sum_cycle(n));
	return 0;
}