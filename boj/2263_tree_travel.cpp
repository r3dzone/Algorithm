//Made By R3dzone
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> pre;
vector<int> in;
vector<int> post;

void print_vec(){
	for(int i = 0; i < pre.size()-1; i++)
		printf("%d ",pre[i]);
	printf("%d",pre.back());
}

void print_pre(int in_stt, int in_end, int post_stt, int post_end){ //[stt,end)
	if(in_end-in_stt <= 0)return;

	int root = post[post_end-1];
	pre.push_back(root);
	int L_size = find(in.begin()+in_stt,in.begin()+in_end,root) - in.begin()-in_stt;
	int R_size = in.size() - L_size - 1;

	print_pre(in_stt, in_stt+L_size, post_stt, post_stt+L_size);
	print_pre(in_stt+L_size+1, in_end, post_stt+L_size, post_end-1);
}

int main(){
	scanf("%d",&n);
	int inp;
	
	for(int i = 0; i < n; i++){
		scanf("%d",&inp);
		in.push_back(inp);
	}
	for(int i = 0; i < n; i++){
		scanf("%d",&inp);
		post.push_back(inp);
	}
	print_pre(0,n,0,n);
	print_vec();
	return 0;
}

/* TC
6
4 2 1 5 3 6
4 2 5 6 3 1

ans:1 2 4 3 5 6
*/
