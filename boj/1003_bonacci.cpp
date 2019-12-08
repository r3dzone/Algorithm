//Made By R3dzone;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 40;
pair<int,int> memo[MAXN+5];


void fibo(int n){
	if (memo[n].first != -1){
		return;
	}
	if( n == 0 ){
		memo[n].first = 1;
		memo[n].second = 0;
		return;
	}
	if( n == 1 ){	
		memo[n].first = 0;
		memo[n].second = 1;
		return;
	}
	fibo(n-1);
	fibo(n-2);
	memo[n].first = memo[n - 1].first + memo[n - 2].first;
	memo[n].second = memo[n - 1].second + memo[n - 2].second;
	return;
}

int main(){
	int t , tmp = 0;
	scanf("%d",&t);
	for(int i = 0; i < MAXN+5; i++ )memo[i] = make_pair(-1,-1);
	//for(int i = 0; i < MAXN+5; i++ )printf("%d",memo[i].first);
	for(int i = 0; i < t ; i++ ){
		scanf("%d",&tmp);
		fibo(tmp);
		printf("%d %d\n",memo[tmp].first,memo[tmp].second);
	}
}