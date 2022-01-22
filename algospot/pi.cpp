//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int INF = 987654321;
const int MAXN = 10000;

string str;
int n;
int memo[MAXN+5];

int judgeEz(int x,int y){ //str[x]를 포함한 y글자까지의 난이도 
	string tst = str.substr(x,y);
	if(tst == string(y,tst[0])) return 1; //tst[0]으로만 y만큼 만든것과 비교 

	int diff = tst[1]-tst[0];
	bool ap = true;
	for(int i = 0; i < y-1; i++)
		if(diff != int(tst[i+1] - tst[i])) ap = false;
	
	if(ap && ((diff == -1) || (diff == 1))) return 2;

	bool ot = true;
	for(int i = 0; i < y; i++)
		if(tst[i] != tst[i%2]) ot = false;
	
	if(ot) return 4;
	if(ap) return 5;
	return 10;
}

int pi(int x){ //x부터 끝까지 원주율을 외우는 것의 최소난이도 
	if(x == n) return 0;
	if(x > n || ((n-x) < 3))return INF;	

	int& ret = memo[x];
	if(ret != -1)return ret;
	
	ret = INF;
	
	for(int i = 3; i <= 5; i++)
		if(x+i <= n)ret = min(ret,(judgeEz(x,i)+pi(x+i)));
	
	return ret;
}

int main(){
	int c;
	scanf("%d",&c);
	cin.ignore();
	for(int i = 0; i < c; i++){
		getline(cin,str);
		n = str.length();
		memset(memo,-1,sizeof(memo));
		printf("%d\n",pi(0));
	}
	return 0;
}
