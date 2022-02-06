//Made By R3dzone
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > absHeap;

void inpAbsHeap(pair<int,int> x){
	if(x.first == 0){
		if(absHeap.size() == 0){
			printf("0\n");
			return;
		}
		printf("%d\n",absHeap.top().second);
		absHeap.pop();
		return;
	}
	if(x.first < 0){
		x.first *= -1;
	}
	absHeap.push(x);
	return;
}

int main(){
	int n,x;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		inpAbsHeap(make_pair(x,x));
	}
}
