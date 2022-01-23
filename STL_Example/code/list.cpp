//Made By R3dzone
#include <cstdio>
#include <list>

using namespace std;

list<int> lst;
list<int>::iterator iter = lst.begin();

void print_list(){
	for(iter = lst.begin();iter != lst.end();iter++)
		printf("%d ",*iter);
	printf("\n");
}

int main(){
	
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	print_list();
	
	lst.push_front(1);
	lst.push_back(6);
	print_list();
	
	iter = lst.begin();
	for(int i = 1; i < 2;i++)
		iter++;       //iter는 두번째 리스트 가르킴
	printf("*iter:%d\n",*iter);
	lst.insert(iter,2); //iter앞에 원소가 넣어짐
	print_list();
	
	lst.pop_back();
	lst.pop_front();
	print_list();

	return 0;
}
