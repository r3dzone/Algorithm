//Made By R3dzone
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int first[5] = {1, 2, 3, 4, 5};
    int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int correct[3] = {0};
    
    if(first[0] == answers[0])correct[0]++;
	if(second[0] == answers[0])correct[1]++; 
	if(third[0] == answers[0])correct[2]++; 
    
    for(int i = 1; i <= answers.size();i++){
		if(first[(i%5)] == answers[i])correct[0]++;
		if(second[(i%8)] == answers[i])correct[1]++; 
		if(third[(i%10)] == answers[i])correct[2]++; 
	}
	int maximum = 0;
	for(int i = 0 ; i < 3;i++)
		if(maximum < correct[i]) maximum = correct[i];
	for(int i = 0 ; i < 3;i++)
		if(maximum == correct[i]) answer.push_back(i+1);

    return answer;
}

int main(){
	solution({1,2,3,4,5});
	solution({1,3,2,4,2});
	return 0;
}
