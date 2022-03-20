//Made By R3dzone
#include <cstdio>
#include <map>

using namespace std;

int n,m;
map<int,int> mp;

int main(){
	scanf("%d",&n);
	int inp1;
	for(int i = 0; i < n; i++){
		scanf("%d",&inp1);
		mp.insert(make_pair(inp1,1));
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		scanf("%d",&inp1);
		int flag = 0;
		if(mp.find(inp1) != mp.end())flag = 1;
		printf("%d\n",flag);
	}
}
