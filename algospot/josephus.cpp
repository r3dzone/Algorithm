//Made By R3dzone
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

pair<int,int> suicide(int n, int k){
	list<int> living;
	list<int>::iterator iter;
	int cnt = k;	

	for(int i = 1; i <= n; i++)
		living.push_back(i);

	iter = living.begin();
	while(n > 2){ //list.size() == O(N)
		if(iter == living.end())iter = living.begin();
		if(cnt%k == 0){
			iter = living.erase(iter);//divide by 0 Á¶½É
			n--;
		}else iter++;
		cnt++;
	}
	
	return make_pair(living.front(),living.back());
}

int main(){
	int c;
	int n,k;
	pair<int,int> tmp;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&n,&k);
		tmp = suicide(n,k); 
		printf("%d %d\n",tmp.first,tmp.second);
	}
}
