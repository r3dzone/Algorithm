#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct point{
   int x, y;
	
   bool operator<(point& rhs){
		if(y < rhs.y){
			return true;
		}else if(y == rhs.y){
			return x > rhs.x;
		}else return false; 
   	}
};

int main(){
 	point p[5];
	
	p[0].x = 9;
	p[0].y = 3;
	p[1].x = 4;
	p[1].y = 6;
	p[2].x = 2;
	p[2].y = 6;
	p[3].x = 3;
	p[3].y = 6;
	p[4].x = 10;
	p[4].y = 2;
	cout << "\ty:\tx:\n";
	for(int i = 0; i < 5; i++ ) cout << "\tp[" << i  << "]: "<< p[i].y << "\t" << p[i].x << endl;
	for(int i = 0; i < 4; i++ ){
		string a = ">";
		if(p[i] < p[i+1]) a = "<";		
		cout << "\tp[" << i <<"]" << a <<"p[" << i+1 <<"]"<< endl;
	}
}