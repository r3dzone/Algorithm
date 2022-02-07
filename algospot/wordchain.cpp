//Made By R3dzone
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> word;
vector<vector<int> > adj; //간선
vector<int> out,in; 
vector<string> graph[26][26];
vector<int> circuit;

bool printVec(){ 
	vector<string> print;
	for(int i = circuit.size()-1; i > 0; i--){
		cout << graph[circuit[i]][circuit[i-1]].back() << " ";
		graph[circuit[i]][circuit[i-1]].pop_back();
	}
	cout << "\n";
	return true;
}

void makeGraph(){ //graph는 알파벳을 정점으로 하고 word의 시작알파벳,끝 알파벳으로 가는 방향 간선을 가짐 
	int stt, end;
	adj =  vector<vector<int> >(26,vector<int>(26,0));
	out = vector<int>(26,0);
	in = vector<int>(26,0);
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			graph[i][j].clear();
	for(int i = 0; i < word.size(); i++){
		stt = word[i][0] - 'a';
		end = word[i][word[i].size()-1] - 'a';
		adj[stt][end] += 1;
		graph[stt][end].push_back(word[i]);
		out[stt]++;
		in[end]++;
	}
}

void makeCircuit(int here){ //here정점에서 시작하는 서킷 
	for(int i = 0; i < adj[here].size(); i++){
		while(adj[here][i]){
			adj[here][i]--; //갈 간선 삭제 
			makeCircuit(i);
		}
	}
	circuit.push_back(here);
	return;
}

bool judgeEuler(){ //간선 홀짝 세서 트레일이나 서킷 만들어지는지 확인
					//방향 그래프에서 서킷은 모든 정점이 아웃디그리와 인디그리의 수가 같아야 함
					//트레일은 서킷에서 시작점,끝점 만 아웃디그리와 인디그리가 하나씩 많음 
	int outMod = 0, inMod = 0;
	for(int i = 0; i < 26; i++){
		int delta = out[i] - in[i];
		if(delta > 1 || delta < -1) return false;
		if(delta == 1) outMod++;
		if(delta == -1) inMod++;
	}
	if(outMod == 1 && inMod == 1)return true;//트레일 
	if(outMod == 0 && inMod == 0)return true;//서킷 
	return false;
}

bool adjMod(){
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			if(adj[i][j]) return true;//makeCircuit 한번 실행후에는 간선이 남아있으면 안됨; 
	return false;
}

void solve(){
	bool flag = false;
	makeGraph();
	if(!judgeEuler()){
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
	for(int i = 0; i < 26; i++){
		if(out[i] == in[i]+1){//나가는 간선이 1개 많다 == 시작점 
			makeCircuit(i);
			flag = true;
			break;
		} 
	}
	if(flag){
		if(adjMod()){ 
			cout << "IMPOSSIBLE" << "\n";
			return;
		}
		printVec();
		return;
	}

	for(int i = 0; i < 26; i++){
		if(out[i]){
			makeCircuit(i);
			break;
		}
	}
	if(adjMod()){ 
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
	printVec();
	return;
}

int main(){
	int c,n;
	string str;
	cin >> c;
	for(int i = 0; i < c; i++){
		cin >> n;
		word.clear();
		adj.clear();
		circuit.clear();
		for(int j = 0; j < n; j++){
			cin >> str;
			word.push_back(str);
		}
		solve();
	}
	return 0;
}
