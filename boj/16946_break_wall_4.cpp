//Made By R3dzone
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1000;

int n,m;

string map[MAXN+5];
int visited[MAXN+5][MAXN+5];
int group[MAXN*MAXN+5] = {0};
int group_cnt = 0;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int dfs(int x, int y){	
	int ret = 1;
	if(visited[y][x] == -1)
		visited[y][x] = group_cnt;

	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] == '0' && visited[ny][nx] == -1){		
			ret += dfs(nx,ny);	
		}
	}
	return ret;
}

int main(){
	cin >> n >> m;
	memset(visited,-1,sizeof(visited));
	for(int i = 0; i < n; i++){
		cin >> map[i];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == '0' && visited[i][j] == -1){
				group[group_cnt] = dfs(j,i);
				group_cnt++;
			}
		}
	}
	vector<int> vec;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == '1'){
				vec.clear();
				int tmp = 1;
				for(int c = 0; c < 4; c++){
					int flag = 1;
					int nx = j+dx[c];
					int ny = i+dy[c];
					if(nx >= 0 && ny >= 0 && nx < m && ny < n){
						for(int k = 0; k < vec.size(); k++)
							if(vec[k] == visited[ny][nx])
								flag = 0;
						if(flag){
							tmp += group[visited[ny][nx]];
							vec.push_back(visited[ny][nx]);
						}
					}
				}
				cout << tmp%10;
			}else{
				cout << "0";
			}
		}
		cout << "\n";
	}
	return 0;
}
