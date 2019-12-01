//Made by R3dzone
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> vec;
	
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(24);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(25);
	vec.push_back(33);
	vec.push_back(21);
	vec.push_back(8);
	vec.push_back(1);
	
	sort(vec.begin(),vec.end());
	
	vec.resize(unique(vec.begin(),vec.end()) - vec.begin());
	
	for(int i = 0; i < vec.size();i++){
		cout << vec[i]  << "\n";
	}
}