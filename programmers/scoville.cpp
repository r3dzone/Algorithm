//Made By R3dzone
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

typedef unsigned int uint;

priority_queue<uint,vector<uint>,greater<uint> > heap;
int answer = 0;

int mix(){
	int mix1 = heap.top();
	heap.pop();
	
	if(heap.empty())return -1;
	int mix2 = heap.top();
	heap.pop();
	
	answer++;
	heap.push(mix1+(mix2*2));
	return 0;
}

int solution(vector<int> scoville, int K) {
    for(int i = 0; i < scoville.size(); i++)
		heap.push(scoville[i]);
	while(!heap.empty() && heap.top() < K)
		if(mix() == -1) return -1; 
    return answer;
}

int main(){
	vector<int> scoville = {1, 2, 3, 9, 10, 12};
	cout << solution(scoville,7);
	return 0;
}
