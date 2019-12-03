//Made by R3dzone
#include <iostream>


using namespace std;

int euclid(int num1, int num2){
	int mintmp = min(num1,num2);
	int num1rem = num1 % mintmp;
	int num2rem = num2 % mintmp;
	
	if( num1rem == 0 && num2rem == 0) return mintmp;//finish!
	
	if(num1rem == 0){
		euclid(num1,num2rem);
	}else euclid(num2,num1rem);
	
}

int main(){
	int num1 , num2;
	cin >> num1;
	cin >> num2;
	cout << euclid(num1,num2) << "\n";
}