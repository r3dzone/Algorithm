//Made by R3dzone
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	map<string, int> m1;
	map<string, double> m2;
	map<string, string> m3;
	
	m1["a"] = 1;
	m2["b"] = 2.00;
	m3.insert(make_pair("c","three"));

	cout << "Correct Key use" << "\n";
	cout << m1.find("a")->second << "\n";
	cout << m2.find("b")->second << "\n";
	cout << m3.find("c")->second << "\n";

	cout << "Incorrect Key use" << "\n";
	cout << m1.find("d")->second << "\n";
	cout << m2.find("d")->second << "\n";
	cout << m3.find("d")->second << "\n";
}