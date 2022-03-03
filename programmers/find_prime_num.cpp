//Made By R3dzone
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

const int MAXN = 10000000;

using namespace std;

vector<int> num;
int cnt[MAXN];

void inp_num(string str){
	int tmp = stoi(str);
	if(!cnt[tmp]){
		cnt[tmp]++;
		num.push_back(tmp);
	}
}

void make_num(string& str,int stt,int end){
	if(stt == end){
		inp_num(str);
	}else{
		for(int i = stt; i <= end; i++){
			swap(str[stt],str[i]);
			inp_num(str.substr(0,stt+1));
			make_num(str,stt+1,end);
			swap(str[stt],str[i]);
		}
	}
}

bool judge_prime(int number){ //소수는 1과 자신을 제외한 숫자로 나누어지지 않음  
	if(number == 0 || number == 1) return false;
	for(int i = 2; i < number; i++)
		if(!(number%i))return false;
	return true;
}

int solution(string numbers) {
    int answer = 0;
    num = vector<int>();
    memset(cnt,0,sizeof(cnt));
	make_num(numbers,0,numbers.size()-1);
    for(int i = 0; i < num.size();i++)
		if(judge_prime(num[i]))answer++;
    return answer;
}

int main(){
	cout << solution("17") << "\n";
	cout << solution("011");
	return 0;
}
