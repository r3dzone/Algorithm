#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> vec;
	for(int i = 0; i < 10; i ++) vec.push_back(i+1);
	int arr[10] = { 0, 9, 8, 7, 6, 5, 1, 2, 3, 4 };
	
	cout << "Original Vector\n";
	for(int i = 0; i < 10; i ++) cout << " " << vec[i];
	
	reverse(vec.begin(),vec.end());
	cout << "\nPost Reverse() Vector\n";
	for(int i = 0; i < 10; i ++) cout << " " << vec[i];
	
	cout << "\nOriginal Array\n";
	for(int i = 0; i < 10; i ++) cout << " " << arr[i];
	
	reverse(arr,arr+10);
	cout << "\nPost Reverse() Array\n";
	for(int i = 0; i < 10; i ++) cout << " " << arr[i];
}