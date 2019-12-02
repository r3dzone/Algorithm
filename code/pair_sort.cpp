#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int,double> p1 ,pair<int,double> p2){
	if(p1.first > p2.first){
		return true;
	}else if(p1.first == p2.first){
		return p1.second < p2.second;
	}else return false;
}

int main(){
	
	pair<int,double> p[10];
	for(int i = 0; i < 8; i++ ){
		p[i] = make_pair(i * 2, i * 1.2);
	}
	p[8] = make_pair(7 * 2, 4.5);
	p[9] = make_pair(7 * 2, 2.1);
	
	cout << "pair array sort\n\tfirst:\tsecond:\n";
	for(int i = 0; i < 10; i++ ) cout << "\t" << p[i].first << "\t" << p[i].second << "\n"; 
	
	sort(p,p+10,cmp);
	
	cout << "\tfirst:\tsecond:\n";
	for(int i = 0; i < 10; i++ ) cout << "\t" << p[i].first << "\t" << p[i].second << "\n"; 
	
	vector<pair<int,double> > vec;
	
	for(int i = 8 ; i > 0; i-- ){
		vec.push_back(make_pair(i * 3, i * 1.5));
	}
	vec.push_back(make_pair(7 * 3, 4.5));
	vec.push_back(make_pair(7 * 3, 2.1));
	
	cout << "pair Vector sort\n\tfirst:\tsecond:\n";
	for(int i = 0; i < 10; i++ ) cout << "\t" << vec[i].first << "\t" << vec[i].second << "\n"; 
	
	sort(vec.begin(),vec.end(),cmp);
	
	cout << "\tfirst:\tsecond:\n";
	for(int i = 0; i < 10; i++ ) cout << "\t" << vec[i].first << "\t" << vec[i].second << "\n"; 

}
	