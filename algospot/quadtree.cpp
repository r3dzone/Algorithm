#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXL = 1000;

string qtree;

string upDownRev(string::iterator& it){
	char firstChar = *it;
	++it;
	if(firstChar == 'b' || firstChar == 'w') return string(1, firstChar);
	
	string LU = upDownRev(it);
	string RU = upDownRev(it);
	string LD = upDownRev(it);
	string RD = upDownRev(it);
	
	//printf("x + %s %s %s %s\n",LU.c_str(),RU.c_str(),LD.c_str(),RD.c_str());	
	return "x" + LD + RD + LU + RU;
}

int main(){
	int C;
	scanf("%d",&C);
	cin.ignore();
	for(int i = 0; i < C; i++){	
		getline(cin,qtree);
		string::iterator it = qtree.begin();
		printf("%s\n",upDownRev(it).c_str());
	}
	return 0;
}
