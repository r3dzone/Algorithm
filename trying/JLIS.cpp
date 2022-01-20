//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long lint;

const lint MAXN = 100;

int n,m;
lint A[MAXN+5];
lint B[MAXN+5];

void print_vec(vector<lint>& vec){
	printf("ÇöÀçº¤ÅÍ:");
	for(int i = 0; i < vec.size(); i++)
		printf("[%d] ",vec[i]);
	printf("\n");
}

lint JLIS(){
	vector<lint> LIS;
	vector<lint>::iterator it;
	lint idxA,idxB;
	
	lint ret = -1;
	for(lint x = 0; x < n; x++){
		for(lint y = 0; y < m; y++){
			LIS.clear();
			idxA = x;
			idxB = y;
			LIS.push_back(min(A[idxA],B[idxB]));
			while(idxA < n || idxB < m){
				if(idxA < n && (idxB == m || A[idxA] < B[idxB])){
					if(LIS.back() < A[idxA])LIS.push_back(A[idxA]);
					else{
						it = lower_bound(LIS.begin(),LIS.end(),A[idxA]);
						*it = A[idxA];
					}
					idxA++;
				}else{
					if(LIS.back() < B[idxB])LIS.push_back(B[idxB]);
					else{
						it = lower_bound(LIS.begin(),LIS.end(),B[idxB]);
						*it = B[idxB];
					}
					idxB++;
				}
				//print_vec(LIS); 
			}
			lint tmp = LIS.size();
			ret = max(ret,tmp);
		}
	}
	return ret;
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d %d",&n,&m);
		for(int j = 0; j < n; j++)
			scanf("%lld",&A[j]);
		for(int j = 0; j < m; j++)
			scanf("%lld",&B[j]);
		printf("%lld\n",JLIS());
	} 
	return 0;	
}
