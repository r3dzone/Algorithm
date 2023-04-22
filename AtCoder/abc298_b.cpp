//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > g_a;
vector<vector<int> > g_b;

void rotate(){ //rotate clockwise
    vector<vector<int> > tmp_a = g_a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g_a[i][j] = tmp_a[(n-1)-j][i];
}

bool check(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(g_a[i][j] == 1 && g_a[i][j] != g_b[i][j])return false;
    return true;
}

int main(){
    int tmp;
    scanf("%d",&n);
    vector<vector<int> > a(n,vector<int>());
    vector<vector<int> > b(n,vector<int>());

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&tmp);
            a[i].push_back(tmp);
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&tmp);
            b[i].push_back(tmp);
        }

    g_a = a;
    g_b = b;

    for(int i = 0; i < 4; i++){
        if(check()){
            cout << "Yes" << endl;
            return 0;
        }
        rotate();
    }
    cout << "No" << endl;
    return 0;
}