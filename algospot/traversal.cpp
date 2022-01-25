//Made By R3dzone
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(vector<int>& vec,int x,int y){//sliced by [x,y)
	return vector<int>(vec.begin()+x,vec.begin()+y);	
}

void print_vec(vector<int>& vec){
	for(int i = 0; i < vec.size(); i++){
		printf("%d ",vec[i]);
	}
	printf("\n");
}

void print_post(vector<int>& pre,vector<int>& in){
	int all_size = pre.size();
	if(pre.empty())return;
	
	int root = pre[0];
	int L_size = find(in.begin(),in.end(),root)	- in.begin();
	int R_size = all_size - L_size - 1; //LÀÌ¶û root Á¦¿Ü
	
	vector<int> L_pre = slice(pre,1,L_size+1);
	vector<int> L_in = slice(in,0,L_size);
	
	vector<int> R_pre = slice(pre,L_size+1,L_size+1+R_size);
	vector<int> R_in = slice(in,L_size+1,L_size+1+R_size);
	
	print_post(L_pre,L_in); //print L by postorder
	print_post(R_pre,R_in); //print R by postorder 
	printf("%d ",root); 
}

int main(){
	int c,n,tmp;
	vector<int> preorder;
	vector<int> inorder;
	
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		preorder.clear();
		inorder.clear();
		for(int j = 0; j < n; j++){
			scanf("%d",&tmp);
			preorder.push_back(tmp);
		}
		for(int j = 0; j < n; j++){
			scanf("%d",&tmp);
			inorder.push_back(tmp);
		}
		print_post(preorder,inorder);
		printf("\n");
	}
	
}
