//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
lint n,tmp;

int main(){
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vec[i] = tmp;
    }

    sort(vec.begin(), vec.end());
    lint ans = 0;
    for(int i = 1; i < n; i++)
        ans += lint(vec[0]) + lint(vec[i]);
    cout << ans << endl;
    return 0;
}