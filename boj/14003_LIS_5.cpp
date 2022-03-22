#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

int n;
vector<int> vec;
vector<int> order;
vector<int> lis_vec;

void LIS(){
	for(int i = 0; i < vec.size(); i++){
		if(lis_vec.empty() || vec[i] > lis_vec.back()){
			order[i] = lis_vec.size();
			lis_vec.push_back(vec[i]);		
		}else{
			order[i] = lower_bound(lis_vec.begin(),lis_vec.end(),vec[i]) - lis_vec.begin();
			lis_vec[order[i]] = vec[i];
		}
	}
	int lis_len = lis_vec.size();
	printf("%d\n",lis_len);
	int cnt = order.size()-1;
	for(int i = lis_len-1; i >= 0; i--){
		while(true){
			if(order[cnt] == i){
				lis_vec[i] = vec[cnt];
				cnt -= 1;
				break;
			}
			cnt--;
		}
	}
	for(int i = 0; i < lis_vec.size();i++)
		printf("%d ",lis_vec[i]);
}

int main(){
	scanf("%d",&n);
	int inp;
	for(int i = 0; i < n; i++){
		scanf("%d",&inp);
		vec.push_back(inp);
		order.push_back(0);
	}
	LIS();
	return 0;
}

/*
7
2 3 4 1 2 3 4

ans = 
4
1 2 3 4
*/
