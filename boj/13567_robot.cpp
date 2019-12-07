#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

long long int x = 0;
long long int y = 0;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,-1,0,1};

int move(int rot, long long int dst){
	x += dX[rot] * dst;
	y += dY[rot] * dst;
}

int main(){
	int n,m;
	long long int tmpdst;
	string tmpstr;
	int flag = 0;
	int rot = 0;
	
	scanf("%d %d" ,&m ,&n );
	for(int i = 0; i < n; i++){
		cin >> tmpstr;
		cin >> tmpdst;
		
		if(flag == 1) continue;
		if(tmpstr == "MOVE") move(rot,tmpdst);
		if(tmpstr == "TURN"){
			if(!tmpdst){
				if(!rot){
					rot = 3;
				}else rot -= 1;	
			}else{
				rot = (rot + 1)% 4;
			}
		}
		if(x < 0 || y <0 || x > m || y > m){
			flag = 1;
		}
	}
	
	if(flag == 1){
		printf("-1\n");
	}else printf("%lld %lld\n",x , y);
}