//Made By R3dzone
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 500;

int memo[MAXN+5][MAXN+5];
int height; 

vector<vector<int>>	inp;

int dp(int x,int y){//x,y위치까지 올때의 최대값 
	int& ret = memo[x][y];
	if(ret != -1)return ret;

	if(x == height)return ret = inp[x][y];
 	return ret = max(dp(x+1,y),dp(x+1,y+1)) + inp[x][y];
}

int solution(vector<vector<int>> triangle) {
	inp = triangle;
    height = triangle.size()-1;
	memset(memo,-1,sizeof(memo));
	int answer = dp(0,0);
    return answer;
}

main(){
	solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
	return 0;
}
