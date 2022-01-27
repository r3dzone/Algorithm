//Made By R3dzone
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;

vector<int> stk;

void push(int num){
	stk.push_back(num);
}

int execute(string& op){
	int ret;
	if(op == "size"){
		return stk.size();
	}
	if(op == "empty"){
		if(stk.empty())return 1;
		else return 0;
	}
	if(stk.size() == 0) return -1;
	if(op == "pop"){
		ret = stk.back();
		stk.pop_back();
		return ret;
	}
	if(op == "top"){
		return stk.back();
	}
}

int main(){
	string op;
	int num = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		cin >> op;
		if(op == "push"){
			cin >> num;
			push(num);
		}else cout << execute(op) << endl;
	} 
}
