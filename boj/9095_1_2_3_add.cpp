//Made by R3dzone
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 11;
int memo[MAXN+1]; 

int dp(int x){
	if(x < 0) return 0;
	if(x == 0) return 1;
	int& ret = memo[x];
	if(ret != -1) return ret;
	ret = dp(x-1) + dp(x-2) + dp(x-3);
	return ret;
}

int main(){
	int T;
	int n;
	cin >> T;
	memset(memo, -1, sizeof(memo));
	for(int i = 0 ; i < T; i++){
		cin >> n;
		cout << dp(n) << endl;
	}
}