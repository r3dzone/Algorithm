//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 500;

int n;
int arr[MAXN+5];

int LIS(){
	vector<int> vec;
	vec.push_back(arr[0]);
	for(int i = 1; i < n; i++){
		if(vec.back() < arr[i]) vec.push_back(arr[i]);
		else{
			vector<int>::iterator it = lower_bound(vec.begin(),vec.end(),arr[i]);
			*it = arr[i];
		}
	}
	return vec.size();
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		for(int j = 0; j < n; j++){
			scanf("%d",&arr[j]);
		}
		printf("%d\n",LIS());
	}
	return 0;
}
