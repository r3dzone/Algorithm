//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <cstring>

using namespace std;

struct cmpGrt{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.first > b.first;
	}
};

struct cmpLess{ 
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.first < b.first;
	}
};

const int MAXK = 1000000; 
int ptr[MAXK+5];
int ptrCnt;
priority_queue<pair<int,int>,vector<pair<int,int> >,cmpGrt> minQueue;
priority_queue<pair<int,int>,vector<pair<int,int> >,cmpLess> maxQueue;

void inpQueue(int x){
	ptr[ptrCnt] = 1;
	minQueue.push(make_pair(x,ptrCnt));
	maxQueue.push(make_pair(x,ptrCnt));
	ptrCnt++;
}

void delQueue(int x){
	if(x == 1){
		while(!maxQueue.empty() && !ptr[maxQueue.top().second]){
			maxQueue.pop();
		}
		if(!maxQueue.empty()){
			ptr[maxQueue.top().second] = 0;
			maxQueue.pop();
		}
	}else{
		while(!minQueue.empty() && !ptr[minQueue.top().second]){
			minQueue.pop();
		}
		if(!minQueue.empty()){
			ptr[minQueue.top().second] = 0;
			minQueue.pop();
		}
	}
}

void print_queue(){
	while(!maxQueue.empty() && !ptr[maxQueue.top().second]){
		maxQueue.pop();
	}
	while(!minQueue.empty() && !ptr[minQueue.top().second]){
		minQueue.pop();
	}
	if(minQueue.empty()||maxQueue.empty())printf("EMPTY\n");
	else printf("%d %d\n",maxQueue.top().first,minQueue.top().first);
}

int main(){
	int t,k;
	char op;
	int x;

	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		memset(ptr,0,sizeof(ptr));
		ptrCnt = 0;
		minQueue = priority_queue<pair<int,int>,vector<pair<int,int> >,cmpGrt>();
		maxQueue = priority_queue<pair<int,int>,vector<pair<int,int> >,cmpLess>();
		scanf("%d",&k);
		for(int j = 0;j < k; j++){
			getchar(); //flushing
			scanf("%c %d",&op,&x);
			if(op == 'I')inpQueue(x);
			else delQueue(x);
		}
		print_queue();
	}
	return 0;
}
