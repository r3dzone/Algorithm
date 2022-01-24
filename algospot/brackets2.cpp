//Mdde By R3dzone
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void bracket(string& str){
	int len = str.length();
	vector<char> stk;
	if(len%2){
		printf("NO\n");
		return;
	}
	for(int i = 0; i < len; i++){
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')stk.push_back(str[i]);
		else{
			if(i == 0){
				printf("NO\n");
				return;
			}
			if((str[i] == ')' && stk.back() == '(')||
			(str[i] == '}' && stk.back() == '{')||
			(str[i] == ']' && stk.back() == '[')){
				stk.pop_back();
			}else{
				printf("NO\n");
				return;
			}
		}	
	}
	if(stk.size() == 0)printf("YES\n");
	else printf("NO\n");
	return;
}

int main(){
	int c;
	scanf("%d",&c);
	cin.ignore();
	string str;
	for(int i = 0; i < c; i++){
		getline(cin,str);
		bracket(str);
	}
}
