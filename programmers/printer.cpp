//Made By R3dzone
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int> > que;
    int priority[10] = {0};
    
    for(int i = 0; i < priorities.size(); i++){
		que.push(make_pair(priorities[i],i));
		priority[priorities[i]]++;
	}
			
	while(!que.empty()){
		int maxp = 0;
		for(int i = 1; i < 10; i++)
			if(priority[i] && i > maxp)maxp = i;
		pair<int,int> j = que.front();
		if(j.first == maxp){
			answer++;
			if(j.second == location) return answer;
			priority[j.first]--;
			que.pop();
		}else{
			que.push(que.front());
			que.pop();
		}
	}
}

int main(){
	cout << solution({2, 1, 3, 2},2) << "\n";
	cout << solution({1, 1, 9, 1, 1, 1},0);
	return 0;
}
