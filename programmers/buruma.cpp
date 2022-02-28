//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 30;

int buruma[MAXN+5];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i <= n+1; i++)
    	buruma[i] = 1;
    for(int i = 0; i < reserve.size(); i++)
    	buruma[reserve[i]]++;
    for(int i = 0; i < lost.size(); i++)
    	buruma[lost[i]]--;
    	
    for(int i = 1; i <= n; i++)
    	if(buruma[i] == 0){ //[n+1]과 [0]은 언제나 1임 
    		if(buruma[i-1] == 2){ 
				buruma[i]++;
    			buruma[i-1]--;
    			continue;
    		}
			if(buruma[i+1] == 2){ 
				buruma[i]++;
    			buruma[i+1]--;
    			continue;
    		}
    	}
    for(int i = 1; i <= n; i++)
    	if(buruma[i])answer++;
    return answer;
}

int main(){
	cout << solution(5,{2,4},{1,3,5}) << "\n";
	cout << solution(5,{2,4},{3}) << "\n";
	cout << solution(3,{3},{1}) << "\n";
	return 0;
}
