//Made By R3dzone
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int,vector<int>,greater<int> > minheap;

int main(){
	int n,tmp;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&tmp);
		if(tmp == 0){
			if(minheap.empty())printf("0\n");
			else{
				printf("%d\n",minheap.top());
				minheap.pop();
			}
		}else minheap.push(tmp);
	}
	return 0;
}
