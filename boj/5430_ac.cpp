//Made By R3dzone
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string p,arr;
int n;
vector<int> vec;

void print_ans(int x,int y,bool rev){ //x부터 y까지 rev == false 정상출력 || rev == true 역출력
	if(x == y){
		cout << "[]\n";
		return;
	}
	
	if(!rev){
		cout << "[";
		for(int i = x; i < y-1; i++)
			cout << vec[i] << ",";
		cout << vec[y-1] << "]\n";
	}else{
		cout << "[";
		for(int i = y-1; i > x; i--)
			cout << vec[i] << ",";
		cout << vec[x] << "]\n";
	}
}

void solve(){
	int left = 0;
	int right = vec.size();
	bool reverse = false;
	for(int i = 0; i < p.size(); i++){
		if(p[i] == 'R')reverse = !reverse;
		else{ // p[i] == 'D'
			if(reverse) right -= 1;
			else left += 1;
		}
		if(right < left){
			cout << "error\n";
			return;
		}
	}
	print_ans(left,right,reverse);
}

void parse(){
	int stt = 1;
	for(int i = 1; i < arr.size(); i++){
		if(arr[i] == ',' || (i != 1 && arr[i] == ']')){
			vec.push_back(stoi(arr.substr(stt,i-stt)));
			stt = i+1;
		}
	}
}

int main(){
	//ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;   
	cin >> t;
	for(int i = 0; i < t; i++){
		vec = vector<int>();
		cin >> p;
		cin >> n;
		cin >> arr;
		parse();
		solve();
	}
	return 0;
}
