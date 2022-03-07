//Made By R3dzone
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	string inp;
	map<string,int> brand;
	map<string,int> no_brand;
	int cnt = 0;

	for(int i = 0; i < n; i++){
		cin >> inp;
		brand.insert(make_pair(inp,0));
	}
	for(int i = 0; i < m; i++){
		cin >> inp;
		if(brand.find(inp) != brand.end()){
			cnt++;
			no_brand.insert(make_pair(inp,0));
		}
	}
	cout << cnt << "\n";
	for(map<string,int>::iterator iter = no_brand.begin(); iter != no_brand.end(); iter++){
		cout << iter->first << "\n";
	}
	return 0;
}
