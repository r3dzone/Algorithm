//Made By R3dzone
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

const string wrong = "INVALID HYPOTHESIS";

int n;
vector<string> strs;

vector<vector<int> > adj;

void makePriority(){
	adj = vector<vector<int> >(26,vector<int>(26,0)); //그래프 인접행렬 
	//adj = {0,0,0,0,0...,0 26개}
	//		{0,0,0,0,0...,0 26개}
	//		...
	//		26개 
	int len;
	for(int i = 0; i < n-1;i++){ 
		len = min(strs[i].size(),strs[i+1].size());  
		for(int j = 0; j < len; j++){
			if(strs[i][j] != strs[i+1][j]){//다른 부분 발견
				//strs[i][j]가 strs[i+1][j] 앞임
				int a = strs[i][j] - 'a';
				int b = strs[i+1][j] - 'a';
				adj[a][b] = 1; //a 문자가 b 문자보다 앞임 
				break;
			}
		}
	}
}

vector<int> visited;
vector<int> order;

void dfs(int hear){
	visited[hear] = 1;
	for(int i = 0; i < 26; i++)
		if(adj[hear][i] && !visited[i]) dfs(i);
	order.push_back(hear);
}

void topologicalSort(){
	visited = vector<int>(26,0);
	order.clear();
	for(int i = 0; i < 26; i++)
		if(!visited[i])dfs(i);
	reverse(order.begin(),order.end());
	
	for(int i = 0; i < 26; i++)
		for(int j = i+1; j < 26; j++)
			if(adj[order[j]][order[i]]){
				printf("%s\n",wrong.c_str()); //뒤에 글자가 앞에 나오는 경우가 있으면 
				return;
			}		
			
	for(int i = 0; i < 26; i++)
		printf("%c",order[i]+'a');
	printf("\n");
	return;
}

int main(){
	int c;
	string str;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		strs.clear();
		adj.clear();
		cin.ignore();
		for(int j = 0; j < n; j++){
			cin >> str;
			strs.push_back(str); 
		}
		makePriority();
		topologicalSort();
	}
}
