//Made By R3dzone
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n,m;
deque<int> q;
deque<int> tmp_q;
vector<int> vec;

int rotate_L(int x){
	int ans = 0;
	while(1){
		if(q.front() == x)
			break;
		else{
			ans++;
			q.push_front(q.back());
			q.pop_back();
		}
	}
	return ans;	
}

int rotate_R(int x){
	int ans = 0;
	while(1){
		if(q.front() == x)
			break;
		else{
			ans++;
			q.push_back(q.front());
			q.pop_front();
		}
	}
	q.pop_front();
	return ans;	
}

int main(){
	cin >> n >> m;
	int tmp;
	for(int i = 0; i < m; i++){
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	for(int i = 1; i <= n; i++)
		q.push_back(i);

	int ans = 0;
	int tmpl,tmpr;
	for(int i = 0; i < m; i++){
		tmp_q = q;
		tmpl = rotate_L(vec[i]);
		q = tmp_q;
		tmpr = rotate_R(vec[i]);
		if(tmpl <= tmpr)
			ans += tmpl;
		else
			ans += tmpr;
	}
	cout << ans << endl;
	return 0;
}
