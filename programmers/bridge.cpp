//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

const int MAXN = 10000;

int bridge[MAXN+5] = {0};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int len = bridge_length;
    int onBridge = 0;
    int total = truck_weights.size();
    list<int> truck;
	for(int i = 0; i < total; i++)
		truck.push_back(truck_weights[i]);
    
    while(total){
    	if(!truck.empty() && onBridge+truck.front()-bridge[0] <= weight){
			bridge[len] = truck.front();
			onBridge += truck.front();
			truck.pop_front();
		}else bridge[len] = 0;
		if(bridge[0]){
			total--;
			onBridge -= bridge[0];
		}
		for(int i = 0; i < len; i++){
			bridge[i] = bridge[i+1];
		}		
		answer++;
	}
    return answer;
}

int main(){
	cout << solution(2,10,{7,4,5,6}) << "\n";
	cout << solution(100,100,{10}) << "\n";
	cout << solution(100,100,{10,10,10,10,10,10,10,10,10,10}) << "\n";
	return 0;
}
