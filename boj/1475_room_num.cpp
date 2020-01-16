#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n,tmp;
int num[10];
char room[8];

int main(){
	scanf("%s",&room);
	int inum = atoi(room);
	for(int i = 0 ; i < strlen(room); ++i){
		++num[inum%10];
		inum /= 10;
	}
	num[6] += num[9];
	num[6] = (num[6]/2)+(num[6]%2);
	for(int i = 0 ; i < 9; ++i){
		tmp = std::max(tmp,num[i]);
	}
	printf("%d\n",tmp);
}
