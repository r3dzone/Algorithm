//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> paper;

int ink(int x){
    if(x == 0) return 0;
    return 5 + (x * 2);
}

int main(){
    cin >> n >> m;
    int tmp;
    vector<int> tmp_paper(n+1,0);
    paper = tmp_paper;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        paper[tmp] = 1;
    }

/*
    for(int i = 1; i <= n; i++){
	cout << paper[i] << " "; 
    }cout << endl;
*/
    int first_0 = 0;
    int cnt = 0;
    int flag = 1;
    for(int i = 1 ; i <= n; i++){
	if(!first_0){
		if(paper[i] == 0){
			first_0 = i;
		}
		continue;
	}else{
		if(paper[i] == 1){
			cnt++;
		}else{
			if(cnt && cnt <= 2){
				if(flag && i < 3){
					flag = 0;
					cnt = 0;
					continue;
				}
				for(int j = i-cnt; j < i; j++){
					paper[j] = 0;
				}
			}
			cnt = 0;	
		}
	}
    }
/*
    for(int i = 1; i <= n; i++){
	cout << paper[i] << " "; 
    }	cout << endl;
*/
	int ans = 0;
	cnt = 0;
	for(int i = 1; i <= n; i++){
    		if(paper[i] == 0) cnt++; 
		else{
			ans += ink(cnt);
			cnt = 0;
		}
	}
	ans += ink(cnt);
	cnt = 0;

    cout << ans << endl; 
}
