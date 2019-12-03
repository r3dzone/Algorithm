#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<vector<int> > vec2d;
	vector<int> vec1;
	vector<int> vec2;
	
	for(int i = 0 ; i < 5; i++) vec1.push_back(i);
	for(int i = 9 ; i >= 0; i--) vec2.push_back(i);
	
	vec2d.push_back(vec1);
	vec2d.push_back(vec2);
	
	cout << vec2d[0][2] << "\n"; //print vec1[2](equal 2)
	cout << vec2d[1][2] << "\n"; //print vec2[2](equal 7)
	
}