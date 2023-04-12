//Made By R3dzone
#include <algorithm>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int n,m;
const int MAXN = 1e5;

map<string, int> pdict;
map<int, string> pdict_num;

int main(){
    scanf("%d %d",&n,&m);
    char tmp[MAXN+5];
    for(int i = 1; i <= n; i++){
        scanf("%s",tmp);
        pdict.insert({string(tmp),i});
        pdict_num.insert({i,string(tmp)});
    }

    for(int i = 0; i < m; i++){
        scanf("%s",tmp);
        if(tmp[0] <= '9'){
            printf("%s\n",pdict_num.find(stoi(tmp))->second.c_str());
        }else{
            printf("%d\n",pdict.find(string(tmp))->second);
        }
    }
}