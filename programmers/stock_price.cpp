//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
	int idx = 0;
	while(idx != prices.size()){
		bool flag = false;
		for(int i = idx+1; i < prices.size(); i++){
			if(prices[idx] > prices[i]){
				answer.push_back(i-idx);
				idx++;
				flag = true;
				break;
			}
		}
		if(flag)continue;
		answer.push_back(prices.size()-idx-1);
		idx++;		
	}
    return answer;
}

int main(){
	vector<int> vec = solution({1, 2, 3, 2, 3});
	for(int i = 0; i < vec.size();i++)
		cout << vec[i] << ", ";
	return 0;
}
