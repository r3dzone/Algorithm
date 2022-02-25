//Made By R3dzone
#include <string>
#include <vector>
#include <list>

using namespace std;

list<pair<int,int> > q;
list<pair<int,int> >::iterator iter;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ans_cnt = 0;
	int len = progresses.size();
	for(int i = 0; i < len; i++)
		q.push_back(make_pair(progresses[i],speeds[i]));

	while(true){
		if(q.empty())break;
		if(q.front().first >= 100){
			answer.push_back(1);
			q.pop_front();
			while(!q.empty() && q.front().first >= 100){
				answer[ans_cnt]++;
				q.pop_front();			
			}
			ans_cnt++;
		}
		for(iter = q.begin(); iter != q.end(); iter++)
			(*iter).first += (*iter).second;
	}
    return answer;
}

int main(){
	vector<int> prog = {95, 90, 99, 99, 80, 99};
	vector<int> spd = {1, 1, 1, 1, 1, 1};
	solution(prog,spd);
	return 0;
}
