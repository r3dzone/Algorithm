//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 20;
vector<int> tree[MAXN + 5];

int cnt = 0;
int targ;
int height;

void dfs(int x, int y,int prev){
	if(x == height){
		if((prev+tree[x][y]) == targ){
			cnt++;
			cout << x <<", " << y <<"\n";
		}
		return;
	}
	dfs(x+1,y*2,prev+tree[x][y]);
	dfs(x+1,(y*2)+1,prev+tree[x][y]);
}

void make_tree(vector<int> inp){
	tree[0].push_back(inp[0]);
	tree[0].push_back(-inp[0]);
	
	for(int i = 1; i < inp.size(); i++){
		for(int j = 0; j < tree[i-1].size(); j++){
			tree[i].push_back(inp[i]);
			tree[i].push_back(-inp[i]);
		}
	}
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
	height = numbers.size()-1;
	make_tree(numbers);
	targ = target;
	dfs(0,0,0);
	dfs(0,1,0);
	answer = cnt;
    return answer;
}

int main(){
	cout << solution({4, 1, 2, 1},4) << "\n"; 
	//cout << solution({1, 1, 1, 1, 1},3) << "\n";
	return 0;
}
