//Mdde By R3dzone
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool bracket(string& str){
	int len = str.length();
	vector<char> stk;
	if(len%2)return false;
	for(int i = 0; i < len; i++){
		if(str[i] == '(')stk.push_back(str[i]);
		else{
			if(i == 0)return false;
			if(str[i] == ')' && stk.size() > 0)stk.pop_back();
			else return false;
		}	
	}
	if(stk.size() == 0)return true;
	else return false;
}

int main(){
	int c;
	cin >> c;
	string str;
	for(int i = 0; i < c; i++){
		cin >> str;
		if(bracket(str))cout << "YES\n";
		else cout << "NO\n";
	}
}
