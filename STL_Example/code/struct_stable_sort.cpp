#include <iostream>
#include <algorithm>

using namespace std;

struct point{
		int x;
		int y;
	};

	
bool cmp(const point &p1 ,const point &p2){
	if(p1.y < p2.y){
		return true;
	}else return false;
}

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
	for(int i = 0; i < 5; i++ ) cout << "\t" << p[i].y << "\t" << p[i].x << "\n"; 
	
	stable_sort(p,p+5,cmp);
	
	cout << "\n\ty:\tx:\n";
	for(int i = 0; i < 5; i++ ) cout << "\t" << p[i].y << "\t" << p[i].x << "\n"; 
}