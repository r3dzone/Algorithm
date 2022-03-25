//Made By R3dzone
#include <iostream>
#include <string>

using namespace std;

string num;

bool judge(){
	for(int i = 0; i < num.size()/2; i++)
		if(num[i] != num[num.size()-1-i]) return false;
	return true;
}

int main(){
	while(1){
		cin >> num;
		if(num == "0")break;
		if(judge())
			cout << "yes\n"; 
		else
			cout << "no\n"; 
	}
	return 0;
}
