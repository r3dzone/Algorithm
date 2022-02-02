//Made By R3dzone
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int> pq;

void maxheap(int x){
	if(x == 0){
		if(pq.size() == 0){
			printf("0\n");
			return;
		}
		printf("%d\n",pq.top());
		pq.pop();
		return;
	}
	pq.push(x);
	return;
}

int main(){
	int n;
	int x;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		maxheap(x);
	}
	return 0;
}
