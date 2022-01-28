//Made By R3dzone
#include <iostream>
#include <list>
#include <string>

using namespace std;

int n;

list<int> que;

void push(int num){
	que.push_back(num);
}

int execute(string& op){
	int ret;
	if(op == "size"){
		return que.size();
	}
	if(op == "empty"){
		if(que.empty())return 1;
		else return 0;
	}
	if(que.size() == 0) return -1;
	if(op == "pop"){
		ret = que.front();
		que.pop_front();
		return ret;
	}
	if(op == "front"){
		return que.front();
	}
	if(op == "back"){
		return que.back();
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
