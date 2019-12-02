#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	vector<int> vec;
	priority_queue<int> pq;
	pq.push(1);
	pq.push(50);
	pq.push(60);
	pq.push(30);
	pq.push(22);
	
	while(pq.empty() == false){
		vec.push_back(pq.top());
		pq.pop();
	}
	
	for(int i = 0 ; i < vec.size() ; i++){
		cout << vec[i] << "\n";
	} 
	
}