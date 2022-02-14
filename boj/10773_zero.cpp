//Made by R3dzone
#include <cstdio>
#include <vector>

using namespace std;

int k;
vector<int> vec;

int solve(){
	int ret = 0;
	for(int i = 0; i < vec.size(); i++)
		ret += vec[i]; 
	return ret;
}

void getNum(int x){
	if(x == 0)
		vec.pop_back();
	else
		vec.push_back(x);
	return;
}

int main(){
	int tmp;
	scanf("%d",&k);
	for(int i = 0; i < k; i++){
		scanf("%d",&tmp);
		getNum(tmp);		
	}
	printf("%d\n",solve());
	return 0;
}
