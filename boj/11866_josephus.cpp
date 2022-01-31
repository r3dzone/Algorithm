//Made By R3dzone
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

vector<int> vec;

void print_vec(){
	printf("<");
	int len = vec.size();
	for(int i = 0; i < len-1; i++)
		printf("%d, ",vec[i]);
	printf("%d>",vec[len-1]);
	return;
}

void josephus(int n, int k){
	list<int> lst;
	
	for(int i = 1; i <= n; i++)
		lst.push_back(i);
	
	list<int>::iterator it = lst.begin();
	int cnt = 1;
	while(true){
		if(it == lst.end())it = lst.begin();
		if(lst.size() == 0)break;
		if(cnt%k == 0){
			vec.push_back(*it);
			it = lst.erase(it);
			cnt++;
			continue;
		}
		it++;
		cnt++;
	}
	print_vec();
	return;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	josephus(n,k);	
	return 0;
}
