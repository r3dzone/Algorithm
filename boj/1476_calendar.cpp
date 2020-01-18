//Made By R3dzone
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXE = 15;
const int MAXS = 28;
const int MAXM = 19;

int E,S,M;
//BruteForce
int esm(int e,int s,int m){
	for(int i = 1; i < 1e4; ++i)
		if(i%MAXE == e || (i%MAXE == 0 && e == MAXE))
			if(i%MAXS == s || (i%MAXS == 0 && s == MAXS))
				if(i%MAXM == m || (i%MAXM == 0 && M == MAXM))
					return i; 
}

int main(){
	scanf("%d %d %d",&E,&S,&M);
	printf("%d\n",esm(E,S,M));
	return 0;
}
