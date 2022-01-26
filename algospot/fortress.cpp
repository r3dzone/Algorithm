//Made By R3dzone
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int n;
int x[MAXN+5];
int y[MAXN+5];
int r[MAXN+5];

struct treeNode{
	vector<treeNode*> children;
};

int sqr(int x){
	return x*x;
}

bool enclose(int a, int b){ //ch�� now�� �ȿ� �ִ���
	if(a == b || r[b] > r[a])return false;
	int dist = sqr(x[b]-x[a])+sqr(y[b]-y[a]); //���� ������ �Ÿ��� ���� 
	if(dist < sqr(r[a]-r[b]))return true;//�������� ������ ��
	return false; 
}

bool isChild(int parent, int child){
	if(!enclose(parent,child))return false;
	for(int i =0; i < n; i++)
		if((i != parent && i != child) && enclose(parent,i) && enclose(i,child))//parent�� ������ �ٸ� ���̰� child�� �θ��϶� 
			return false;
	return true; 
}

treeNode* getTree(int now){ //now == 0 �϶� root 
	treeNode* ret = new treeNode();
	for(int ch = 0; ch < n; ++ch)
		if(isChild(now,ch))
			ret->children.push_back(getTree(ch));
	return ret;
}

int longest;
 
int node_height(treeNode* now){ //now�� �������� �ϴ� ���� �� subtree�� ���̸� ��ȯ 
	int child_size = now->children.size();
	if(child_size == 0) return 0;
	vector<int> height;
	for(int i = 0; i < child_size; i++)
		height.push_back(node_height(now->children[i]));
	sort(height.begin(),height.end());
	if(child_size >= 2)
		longest = max(longest,(height.back()+ height[height.size()-2] + 2));
	return 1 + height.back();
}

int func(treeNode* tree){
	return max(longest,node_height(tree));
}

int main(){
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		longest = -1;
		for(int j = 0; j < n; j++)
			scanf("%d %d %d",&x[j],&y[j],&r[j]);
		treeNode* tree = getTree(0);
		printf("%d\n",func(tree));
	}
}
