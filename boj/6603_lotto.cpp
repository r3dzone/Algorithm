#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int selnum = 6;
const int MAXN = 13;
vector<int> vec;
int arr[MAXN+1000];
int cnt;

void vec_print(vector<int> vec){
	for(int i = 0;i < vec.size();i++){
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void lotto(int i,int j){
	if(j == 0)return vec_print(vec);
	if(i == cnt) return;
	
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
		lotto(0,6);
		cout << "\n";
	} 
	return 0;
}