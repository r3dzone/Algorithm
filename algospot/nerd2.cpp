#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> parti; //participant

bool isDominant(int p,int q){
	map<int,int>::iterator it;
	it = parti.lower_bound(p);
	if(it == parti.end())return false; //�����ʿ� ���� ���� == �긦 �����ϴ¾ְ� ���� 
	return it->second > q; //�����ʿ� ���� �ִµ� q�� �� ũ�� == ��� ������ϴ� �ִ� 
}

void removeDominated(int p, int q){
	map<int,int>::iterator it;
	map<int,int>::iterator tmp;
	bool flag = false;
	
	it = parti.lower_bound(p);
	if(it == parti.begin())return; //p,q�� �� ���� 
	it--; //�տ� �� ������ �տ��� ����Ų��.
	while(true){
		if(it->second < q){ //���ʿ� �ִµ� q�� �� �۴� == ��� ������Ѵ�. 
			tmp = it; //������ϰ� it--�ع����� erase�ϰ� ���ڿ� it�� �����ؼ� ������ 
			if(it != parti.begin()){
				it--;
				parti.erase(tmp);
			}else{
				parti.erase(tmp);
				return;
			}
		}else return; //���ʿ� �ִµ� q�� �� ũ�� == �꺸�� ������ �� �� ũ��. 
	}
}

int addMap(int p, int q){ //map�� map[p] =q �߰��� ��ȸ ���� �ڰ��� �Ǵ� ����� �� ��ȯ 
	if(!isDominant(p,q))parti[p] = q;//p,q�� ������ϸ� p,q�� �߰����� �ʰ� ��
	else return parti.size();
	removeDominated(p,q);//p,q�� �����ϴ� ���� ����
	return parti.size();//���� ������ ��ȯ 
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
