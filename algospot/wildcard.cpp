//Made By R3dzone
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string> 
#include <iostream>
#include <vector>

using namespace std;

const int MAXL = 100;

string W,S; 
int memo[MAXL+5][MAXL+5];
vector<string> res; 

int dp(int w,int s){
	int& ret = memo[w][s];
	if(ret != -1) return ret;
	
	while(w < W.size() && s < S.size()){
		if(W[w] == S[s] || W[w] == '?'){
			w++;
			s++;
		}else if(!(W[w] == '*')){
			return ret = 0;
		}else{ //W[w] == '*'
			break;
		}
	}
	if(w == W.size() && s == S.size())return ret = 1;
		
	if(W[w] == '*')
		for(int i = s; i <= S.size(); i++)
			if(dp(w+1,i))return ret = 1;

	return ret = 0;
}

int main(){
	int c,n;
	scanf("%d",&c);
	cin.ignore();
	for(int i = 0; i < c; i++){
		getline(cin,W);
		scanf("%d",&n);
		cin.ignore();
		for(int j = 0; j < n; j++){
			getline(cin,S);
			memset(memo,-1,sizeof(memo));
			if(dp(0,0))res.push_back(S);
		}
		sort(res.begin(),res.end());
		for(int j = 0; j < res.size(); j++)
			printf("%s\n",res[j].c_str());
		res.clear();
	}
	return 0;
}
