#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main(){
	bitset<128> bit;
	
	bit.reset();
	cout << "0 initialized bit : " << bit << "\n";
	bit.set();
	cout << "1 initialized bit : " << bit << "\n";
	
	bit.set(3,false);
	cout << "bit.set(3,true) : " << bit << "\n";
	
	bit.flip();
	cout << "bit flip : " << bit << "\n";
	
	string str = bit.to_string();
	cout << "String Output : " << str << "\n";
	cout << "Numeric Output : " << bit.to_ulong() << "\n";	
	
}