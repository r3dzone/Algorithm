//Made By R3dzon
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

string str;
vector<int> num; 
vector<string> op; //operator symbol; size == num.size() - 1; 
//-���� + �ٴ°� ���� -(+ + +)���·� ���´� == ���� -���ö����� �����ش� 

int findMin(){ //x��° ���ں��� �����ϴ� �ּڰ� ��ȯ 
	int ret = num[0];
	int tmp = 0;
	bool flag = false;
	if(op.size() == 0)return ret;
	for(int i = 1; i < num.size(); i++){
		if(op[i-1] == "-"){
			flag = true;
			ret -= tmp;
			tmp = 0;
		}
		if(flag) tmp += num[i];
		else ret += num[i];
	}
	return ret -= tmp;
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
	cout << findMin() << "\n";
	return 0;
}
