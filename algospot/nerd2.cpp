#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> parti; //participant

bool isDominant(int p,int q){
	map<int,int>::iterator it;
	it = parti.lower_bound(p);
	if(it == parti.end())return false; //오른쪽에 뭐가 없다 == 얘를 지배하는애가 없다 
	return it->second > q; //오른쪽에 뭐가 있는데 q도 더 크다 == 얘는 지배당하는 애다 
}

void removeDominated(int p, int q){
	map<int,int>::iterator it;
	map<int,int>::iterator tmp;
	bool flag = false;
	
	it = parti.lower_bound(p);
	if(it == parti.begin())return; //p,q가 맨 앞임 
	it--; //앞에 뭐 있으면 앞에거 가르킨다.
	while(true){
		if(it->second < q){ //왼쪽에 있는데 q가 더 작다 == 얘는 지배당한다. 
			tmp = it; //복사안하고 it--해버리면 erase하고 난뒤에 it에 접근해서 에러남 
			if(it != parti.begin()){
				it--;
				parti.erase(tmp);
			}else{
				parti.erase(tmp);
				return;
			}
		}else return; //왼쪽에 있는데 q가 더 크다 == 얘보다 왼쪽은 다 더 크다. 
	}
}

int addMap(int p, int q){ //map에 map[p] =q 추가후 대회 참가 자격이 되는 사람의 수 반환 
	if(!isDominant(p,q))parti[p] = q;//p,q가 지배당하면 p,q를 추가하지 않고 끝
	else return parti.size();
	removeDominated(p,q);//p,q가 지배하는 점들 삭제
	return parti.size();//맵의 사이즈 반환 
}


int main(){
	int c,n;
	int p,q;
	int res;
	scanf("%d",&c);
	for(int i = 0; i < c; i++){
		scanf("%d",&n);
		res = 0;
		parti.clear();
		for(int j = 0; j < n; j++){
			scanf("%d %d",&p,&q);
			res += addMap(p,q);
		}
		printf("%d\n",res);
	}
	return 0;
}
