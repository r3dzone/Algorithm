#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int selnum = 6;
vector<int> sel;
vector<int> vec;
int aaa;

void vec_print(vector<int> vec){
	//cout << "호출됨\n";
	for(int i = 0;i < vec.size();i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void lotto(int iter,int cnt){
	cout << iter << "===========\n";
	for(int i = iter ; i < cnt; i++){
		if(vec.size() < i)break;
		sel.push_back(vec[i]);
		if(sel.size() == selnum){ 
			vec_print(sel);
			sel.resize(iter);
			cin >> aaa;
		}else{
			lotto(iter+1,cnt);
		}
	}
}

int main(){
	int cnt = 1;
	int tmpint;
	while(1){
		cin >> cnt;
		if(cnt == 0) break;
		for(int i = 0; i < cnt ;i ++){
			cin >> tmpint;
			vec.push_back(tmpint);
		}
		lotto(0,cnt);
		cout << "\n";
		vec.clear();
	} 
	return 0;
}