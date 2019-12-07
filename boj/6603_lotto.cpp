#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int selnum = 6;
const int MAXN = 13;
vector<int> vec;
int arr[MAXN+5];
int cnt;

void vec_print(vector<int> vec){
	for(int i = 0;i < vec.size();i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void lotto(int i,int j){
	if(j == 0) vec_print(vec);
	if(j == cnt) return;
	
	vec.push_back(arr[i]);
	lotto(i+1,j-1);
	vec.pop_back();
	lotto(i+1,j);
}

int main(){
	while(1){
		cin >> cnt;
		if(cnt == 0) break;
		for(int i = 0; i < cnt ;i ++){
			cin >> arr[i];
		}
		lotto(0,selnum);
		cout << "\n";
	} 
	return 0;
}