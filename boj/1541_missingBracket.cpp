//Made By R3dzon
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

string str;
vector<int> num; 
vector<string> op; //operator symbol; size == num.size() - 1; 
int findMin(int x);
int findMax(int x);

//식의 값이 최소가 되려면 - 뒤의 값이 최대가 되야함!
//-(이 안의 값에서 -가 나오면 이 뒤는 최대여야함)
//this is Wrong Answer
//Counter Example is 50+50-100+100-100-100 By midascha

int findMin(int x){ //x번째 숫자부터 시작하는 최솟값 반환 
	if(x == num.size()-1)return num[x]; 
	if(op[x] == "+") return num[x] + findMin(x+1);
	return num[x] - findMax(x+1);
}

int findMax(int x){
	if(x == num.size()-1)return num[x]; 
	if(op[x] == "+") return num[x] + findMax(x+1);
	return num[x] - findMin(x+1);
}

void parse(){
	int numSt = 0;
	int numEd = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '+' || str[i] == '-' || i == str.size()-1){
			numEd = i-1;
			if(i != str.size()-1)
				op.push_back(str.substr(i,1));
			else numEd = i;
			num.push_back(atoi(str.substr(numSt,(numEd-numSt)+1).c_str()));
			numSt = i+1;
		}
	} 
}

int main(){
	cin >> str;
	parse();
	cout << findMin(0) << "\n";
	return 0;
}
