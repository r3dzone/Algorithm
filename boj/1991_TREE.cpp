#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n,cnt,nodelen;
char data[26];
vector<vector<int> > tre;
vector<int> vectmp;
char tmp1,tmp2,tmp3;

void preorder(int x){
	printf("%c",data[x]);
	if(tre[x][0] != 0)preorder(tre[x][0]);
	if(tre[x][1] != 0)preorder(tre[x][1]);
}

void postorder(int x){
	if(tre[x][0] != 0)postorder(tre[x][0]);
	if(tre[x][1] != 0)postorder(tre[x][1]);
	printf("%c",data[x]);
}

void inorder(int x){
	if(tre[x][0] != 0)inorder(tre[x][0]);
	printf("%c",data[x]);
	if(tre[x][1] != 0)inorder(tre[x][1]);
}

int main(){
	scanf("%d",&n);
	data[0] = 'A';
	nodelen = 1;
	int tmpch1,tmpch2,tmpch3;
	
	for(int i = 0 ; i < 26 ; ++i)
		tre.push_back(vector<int>());
	
	for(int i = 0 ; i < n ; ++i){
		scanf("\r%c %c %c",&tmp1,&tmp2,&tmp3);
		tmpch1 = tmp1-'A';
		tmpch2 = tmp2-'A';
		tmpch3 = tmp3-'A';
		
		if(tmp2 != '.'){
			tre[tmpch1].push_back(tmpch2);
			data[tmpch2] = tmp2;
			++nodelen;
		}else{
			tre[tmpch1].push_back(0);
		}
		if(tmp3 != '.'){
			tre[tmpch1].push_back(tmpch3);
			data[tmpch3] = tmp3;
			++nodelen;
		}else{
			tre[tmpch1].push_back(0);
		}
	}
	
	preorder(0);
	puts("");
	inorder(0);
	puts("");
	postorder(0);
	puts("");
	
	return 0;
}