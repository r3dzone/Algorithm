//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 10000;

int h_arr[MAXN+5] = {0};

int solution(vector<int> citations) { //H는 최소의 최대값
    int answer = 0;
    int _MAX = 0;
    for(int i = 0; i < citations.size(); i++){
    	if(citations[i] > _MAX)_MAX = citations[i];
		for(int j = 0; j <= citations[i]; j++)
			h_arr[j]++;
	}
	
	for(int i = 0; i < _MAX; i++)
		if(h_arr[i] >= i) answer = i;
    return answer;
}

int main(){
	cout << solution({3, 0, 6, 1, 5});
	return 0;
}
