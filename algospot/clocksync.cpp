#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int clk[16];
const int INF = 1234567890;

const int sync[10][6] = { //sync[i][5] = sync[i]`s original size
	{0, 1, 2,0,0,     3},
	{3, 7, 9, 11,0,   4},
	{4, 10, 14, 15,0, 4}, 
	{0, 4, 5, 6, 7,   5},
	{6, 7, 8, 10, 12, 5},
	{0, 2, 14, 15,0,  4},
	{3, 14, 15,0,0,   3},
	{4, 5, 7, 14, 15, 5},
	{1, 2, 3, 4, 5,   5},
	{3, 4, 5, 9, 13,  5},
};

bool judgeAllZero(){
	for(int i = 0; i < 16; i++)
		if(clk[i] != 0)return false;
	return true;
}

int minSwitch(int n, int cnt){//n번 스위치를 cnt번 눌렀을 때 모든시계를 12시로 맞출수있는 최소 횟수 cnt == 4는 최소 구하는데 사용 
	int ret = INF;
	
	if(n >= 10){
		if(judgeAllZero()) return 0;
		else return INF;
	}
	
	if(cnt == 4){
		for(int i = 0; i < 4; i++)
			ret = min(ret,minSwitch(n,i));
		return ret;
	}
	
	int size = sync[n][5];
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < size; j++){
			clk[sync[n][j]] = (clk[sync[n][j]]+3)%12;
		}
	}

	ret = cnt + minSwitch(n+1,4);
	if(ret >= INF) ret = INF;

	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < size; j++){
			clk[sync[n][j]] = (clk[sync[n][j]]+12-3)%12;
		}
	}
	return ret;
}

int main(){
	int C;
	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		for(int j = 0; j < 16; j++){
			scanf("%d",&clk[j]);
			clk[j] = clk[j]%12; 
		}
		int tmp = minSwitch(0,4);
		if(tmp >= INF)tmp = -1;
		printf("%d\n",tmp);
	}
	return 0;
}
