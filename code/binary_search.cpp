#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	vector<int> vec;
	vec.push_back(50);
	vec.push_back(23);
	vec.push_back(10);
	vec.push_back(95);
	vec.push_back(34);
	//{ 50 , 23 , 10 , 95 , 34}
	for(int i = 0 ; i < 5; i++){cout << vec[i] << "\n";}
	sort(vec.begin(),vec.end());
	for(int i = 0 ; i < 5; i++){cout << vec[i] << "\n";}
	if(binary_search(vec.begin(),vec.end(),34)){ 
		cout << "Binary_search Detected!\n";
		cout << *lower_bound(vec.begin(),vec.end(),34) << "\n";
		cout << *upper_bound(vec.begin(),vec.end(),34) << "\n";
	}
		else cout << "NoN!\n";

	
	int arr[5] = { 4,5,1,8,6 };
	for(int i = 0 ; i < 5; i++){cout << arr[i] << "\n";}
	sort(arr,arr+5);
	for(int i = 0 ; i < 5; i++){cout << arr[i] << "\n";}
	if(binary_search(arr,arr+5,5)){
		cout << "Binary_search Detected!\n";
		cout << *lower_bound(arr,arr+5,5) << "\n";
		cout << *upper_bound(arr,arr+5,5) << "\n";
	}
	else cout << "NoN!\n";
	
	
}