#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e6;
int memo[MAXN + 1];

int f(int x){
	if (x == 1) return 0;
	int& ret = memo[x];
	if (ret != -1) return ret;
	ret = f(x - 1);
	if (x % 3 == 0) ret = min(ret, f(x / 3));
	if (x % 2 == 0) ret = min(ret, f(x / 2));
	return ++ret;
	
}

int main(){
	int num;
	cin >> num;
	memset(memo, -1, sizeof(memo));
	cout << f(num) << endl;
}