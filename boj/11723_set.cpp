//Made By R3dzone
#include <iostream>
#include <string>

using namespace std;

const int MAXX = 20;

int S[MAXX+5] = {0};

void add(int x){
	S[x] = x;
}

void remove(int x){
	S[x] = 0;
}

void check(int x){
	if(S[x]) cout << "1\n";
	else cout << "0\n";
}

void toggle(int x){
	if(S[x]) S[x] = 0;
	else S[x] = x;
}

void all(){
	for(int i = 1; i <= MAXX;i++)
		S[i] = i;
}

void empty(){
	for(int i = 1; i <= MAXX;i++)
		S[i] = 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	string op;
	int x;

	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> op;
		if(op == "all"){
			all();
			continue;
		}
		if(op == "empty"){
			empty();
			continue;
		}
		cin >> x;
		if(op == "add"){
			add(x);
			continue;
		}
		if(op == "remove"){
			remove(x);
			continue;
		}
		if(op == "check"){
			check(x);
			continue;
		}
		if(op == "toggle"){
			toggle(x);
			continue;
		}
	}
	return 0;
}
