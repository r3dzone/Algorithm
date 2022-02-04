//Made By R3dzone
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef long long lint;
const int MOD = 20090711;

int n;

priority_queue<int,vector<int>,greater<int> > minheap;
priority_queue<int,vector<int>,less<int> > maxheap;

vector<lint> inp;

lint median(lint x){
	if(maxheap.size() == minheap.size()){//maxheap에 들어가야됨 
		if(maxheap.size() == 0){
			maxheap.push(x);
			return maxheap.top();	
		}
		if(x > minheap.top()){
			maxheap.push(minheap.top());
			minheap.pop();
			minheap.push(x);
			return maxheap.top();
		}
		maxheap.push(x);
		return maxheap.top();
	}else{//minheap에 들어가야됨 
		if(x < maxheap.top()){
			minheap.push(maxheap.top());
			maxheap.pop();
			maxheap.push(x);
			return maxheap.top();
		}
		minheap.push(x);
		return maxheap.top();
	} 
}

lint makeInp(int n,int a,int b){
	inp.clear();
	inp = vector<lint>(n,0);
	inp[0] = 1983; //A[0] = 1983
	lint ret = median(inp[0]);
	for(int i = 1; i < n; i++){
		inp[i] = ((inp[i-1] * a)%MOD + b%MOD)%MOD;
		ret += median(inp[i])%MOD;
	}
	return ret%MOD;
}

int main(){
	int c,a,b;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		minheap = priority_queue<int,vector<int>,greater<int> >();//initialize
		maxheap = priority_queue<int,vector<int>,less<int> >();//initialize
		scanf("%d %d %d",&n,&a,&b);
		printf("%ld\n",makeInp(n,a,b));
	}
}
