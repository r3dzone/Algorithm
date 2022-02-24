#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> mp;
    map<string,int>::iterator iter;
    for(int i = 0; i < participant.size(); i++){
        string part = participant[i];
        iter = mp.find(part);
        if(iter != mp.end())
        	iter->second++;
        else 
			mp[part] = 0;
    }

	for(int i = 0; i < completion.size(); i++)
        mp[completion[i]]--;

	for(iter = mp.begin(); iter != mp.end(); iter++)
		if(iter->second == 0) return iter->first;
}

int main(){
	vector<string> part;
	part.push_back("mislav");
	part.push_back("stanko");
	part.push_back("mislav"); 
	part.push_back("ana");
	vector<string> comp;
	comp = part;
	comp.pop_back();
	cout << solution(part,comp);
	return 0;
}

