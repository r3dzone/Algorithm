//Made By R3dzone
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int n;
vector<int> ori,v;
map<int,int> m;

int main(){
    scanf("%d",&n);
    int tmp;
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);
        v.push_back(tmp);  
    }
    ori = v;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int v_size = v.size();
    for(int i = 0; i < v_size; i++)
        m[v[i]] = i;
    for(int i = 0; i < n; i++)
        printf("%d ",m[ori[i]]);

    return 0;
}