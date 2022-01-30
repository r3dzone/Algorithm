//Made By R3dzone
#include <iostream>
#include <list>
#include <string>

using namespace std;

int n;

list<int> deque;

void push_front(int num){
	deque.push_front(num);
}

void push_back(int num){
	deque.push_back(num);
}

int execute(string& op){
	int ret;
	if(op == "size"){
		return deque.size();
	}
	if(op == "empty"){
		if(deque.empty())return 1;
		else return 0;
	}
	if(deque.size() == 0) return -1;
	if(op == "pop_front"){
		ret = deque.front();
		deque.pop_front();
		return ret;
	}
	if(op == "pop_back"){
		ret = deque.back();
		deque.pop_back();
		return ret;
	}
	if(op == "front"){
		return deque.front();
	}
	if(op == "back"){
		return deque.back();
	}
}

int main(){
	string op;
	int num = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		cin >> op;
		if(op == "push_front"){
			cin >> num;
			push_front(num);
		}else if(op == "push_back"){
			cin >> num;
			push_back(num);
		}else cout << execute(op) << endl;
	} 
}
