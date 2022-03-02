//Made By R3dzone
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string x,string y){
	return (x+y > y+x);
}

string solution(vector<int> numbers) {
	vector<string> vec;
	for(int i = 0; i < numbers.size(); i++)
		vec.push_back(to_string(numbers[i]));
	sort(vec.begin(),vec.end(),cmp);
	string answer = "";
	for(int i = 0; i < vec.size();i++)
		answer += vec[i];
	
	//First char is 0?
	int ori = answer.size();
	int first = ori;
	for(int i = 0; i < answer.size();i++)
		if(answer[i] != '0'){
			first = i;
			break;
		}
	answer = answer.substr(first,ori-first);
	if(answer.size() == 0) return "0";
    return answer;
}

main(){
	cout << solution({0,0,0}) << "\n";
	cout << solution({6, 10, 2}) << "\n";
	cout << solution({3, 30, 34, 5, 9}) << "\n";
	cout << solution({356,35,355,351}) << "\n";
	cout << solution({35,355}) << "\n";
	cout << solution({355,35}) << "\n";
	return 0;
}

