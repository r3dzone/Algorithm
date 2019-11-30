//Made by R3dzone
#include <iostream>

using namespace std;

int fibo(int a){
	if( a == 0 ) return 0;
	if( a == 1 ) return 1;
	if( a > 1 ){
		return fibo(a - 1) + fibo(a - 2);
	}	
}

int main(){
	int cnt = 0;
	cin >> cnt;
	//cout << fibo(cnt - 1) << "\n"; // print FibonacciNum
	for(int i = 0; i < cnt ; i++ ) cout << fibo(i) << "\n"; // print Fibonacci Sequence
}