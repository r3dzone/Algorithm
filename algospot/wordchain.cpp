//Made By R3dzone
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> word;
vector<vector<int> > adj; //����
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

void makeGraph(){ //graph�� ���ĺ��� �������� �ϰ� word�� ���۾��ĺ�,�� ���ĺ����� ���� ���� ������ ���� 
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

void makeCircuit(int here){ //here�������� �����ϴ� ��Ŷ 
	for(int i = 0; i < adj[here].size(); i++){
		while(adj[here][i]){
			adj[here][i]--; //�� ���� ���� 
			makeCircuit(i);
		}
	}
	circuit.push_back(here);
	return;
}

bool judgeEuler(){ //���� Ȧ¦ ���� Ʈ�����̳� ��Ŷ ����������� Ȯ��
					//���� �׷������� ��Ŷ�� ��� ������ �ƿ���׸��� �ε�׸��� ���� ���ƾ� ��
					//Ʈ������ ��Ŷ���� ������,���� �� �ƿ���׸��� �ε�׸��� �ϳ��� ���� 
	int outMod = 0, inMod = 0;
	for(int i = 0; i < 26; i++){
		int delta = out[i] - in[i];
		if(delta > 1 || delta < -1) return false;
		if(delta == 1) outMod++;
		if(delta == -1) inMod++;
	}
	if(outMod == 1 && inMod == 1)return true;//Ʈ���� 
	if(outMod == 0 && inMod == 0)return true;//��Ŷ 
	return false;
}

bool adjMod(){
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			if(adj[i][j]) return true;//makeCircuit �ѹ� �����Ŀ��� ������ ���������� �ȵ�; 
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
		if(out[i] == in[i]+1){//������ ������ 1�� ���� == ������ 
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
