//Made By R3dzone
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> origin = array;
	vector<int> answer;
	for(int x = 0; x < commands.size(); x++){
		vector<int> copy = origin;
		int i = commands[x][0]-1;
		int j = commands[x][1];
		int k = commands[x][2]-1;
		sort(copy.begin()+i,copy.begin()+j);
		answer.push_back(copy[i+k]);	
	}
    return answer;
}

int main(){
	vector<int> array = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int> > commands = {{2, 5, 3}, {4, 4, 1},{1, 7, 3}};
	solution(array,commands);
	return 0;
}
