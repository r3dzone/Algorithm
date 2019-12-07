//Made by R3dzone
#include <iostream>


using namespace std;

int euclid(int num1, int num2){
	if(num1%num2 == 0) return num2;
	else return euclid(num2,num1%num2);
}

int main(){
	int num1 , num2;
	cin >> num1;
	cin >> num2;
	cout << euclid(num1,num2) << "\n";
}