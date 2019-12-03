//Made by R3dzone
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	vector<int> vec; // equal { 45 , 30 , 50 , 90 , 80 ,5}
	vec.push_back(45);
	vec.push_back(30);
	vec.push_back(50);
	vec.push_back(90);
	vec.push_back(80);
	vec.push_back(5);
	
	int maxtmp = vec[0];
	int mintmp = vec[0];
	
	for(int i = 1; i < vec.size(); i++){
		maxtmp = max(maxtmp,vec[i]);
		mintmp = min(mintmp,vec[i]);		
	}
	cout << "MaxNum is : " << maxtmp << "\n";
	cout << "MinNum is : " << mintmp << "\n";
}