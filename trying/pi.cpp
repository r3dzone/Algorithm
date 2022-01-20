//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int INF = 1234567890;
const int MAXN = 10000;

string str;
int n;
int memo[MAXN+5];

int pi(int x){ //x부터 끝까지 원주율을 외우는 것의 최소난이도 
	if(x == n) return 0;
	if(x > n || ((n-x) < 3)){
		//printf("기저조건 반환!\n");
		return INF;	
	}

	int& ret = memo[x];
	if(ret != -1)return ret;

	//printf("%d 첫 소환!\n",x);
	
	ret = INF;

	int idx = 0;
	while(idx < 5 && str[x+idx] == str[x])
		idx++;
	if(idx >= 3){
		printf("%d에서 한번 모든숫자가 같음\n",x); 
		ret = min(ret,1+pi(x+idx));	
	}

	idx = 0;
	int diff = str[x+1] - str[x];
	int w = 5;
	if(diff == -1 || diff == 1) w = 2;
	while(idx < 5 && (int(str[x+idx]+diff) == (int(str[x+idx+1]))))
		idx++;
	idx++;
	if(idx >= 3){
		printf("%d에서 한번 등차임\n",x);
		ret = min(ret,w+pi(x+idx));
	}

	idx = 0;
	char rep[2] = {str[x],str[x+1]};
	while(idx < 5 && str[x+idx] == rep[idx%2])
		idx++;
	if(idx >= 3){
		printf("%d에서 한번 반복됨\n",x); 
		ret = min(ret,4+pi(x+idx));
	}

	ret = min(ret,10+pi(x+3));
	ret = min(ret,10+pi(x+4));
	ret = min(ret,10+pi(x+5));
	
	return ret;
}

int main(){
	int c;
	scanf("%d",&c);
	cin.ignore();
	for(int i = 0; i < c; i++){
		getline(cin,str);
		n = str.length();
		printf("반복:%s\n",str.c_str());
		memset(memo,-1,sizeof(memo));
		printf("출력!%d\n",pi(0));
	}
	return 0;
}
