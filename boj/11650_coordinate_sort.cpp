//Made By R3dzone
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,x,y;
	scanf("%d",&n);
	vector<pair<int,int> > vec;
	for(int i = 0; i < n; i++){
		scanf("%d %d",&x,&y);
		vec.push_back(make_pair(x,y));
	}
	sort(vec.begin(),vec.end());
	for(int i = 0; i < n; i++)
		printf("%d %d\n",vec[i].first,vec[i].second);
	return 0;
}
