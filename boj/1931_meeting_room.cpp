//Made By R3dzone
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n;

vector<pair<unsigned int,unsigned int> > meeting;

int main(){
    scanf("%d",&n);
    int tmp1,tmp2;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&tmp1,&tmp2);
        meeting.push_back(make_pair(tmp2,tmp1));
    }
    sort(meeting.begin(),meeting.end());
    int msize = meeting.size();
    int ans = 1;
    unsigned int lastend = meeting[0].first;
    for(int i = 1; i < n; i++){
        if(meeting[i].second >= lastend){
            lastend = meeting[i].first;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}