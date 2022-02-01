//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

list<int> lst;
list<int>::iterator iter;
vector<int> vec;
vector<int> origin;
int n;

void insertReverse(){
	int size = n - 1;
	while(size >= 0){
		iter = lst.begin();
		for(int i = 0; i < size-vec[size]; i++)
			iter++;
		origin.push_back(*iter);
		lst.erase(iter);
		size--;
	}
	for(int i = origin.size()-1; i >= 0; i--)
		printf("%d ",origin[i]);
	printf("\n");
}

int main(){
	int c,tmp;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		lst.clear();
		vec.clear();
		origin.clear();
		for(int j = 1; j <= n; j++){
			lst.push_back(j);
			scanf("%d",&tmp);
			vec.push_back(tmp);
		}
		insertReverse(); 
	}
	return 0;
}
