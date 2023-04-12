//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int h,w;
vector<string> s;
string tmp;

int main(){
    scanf("%d %d",&h,&w);
    for(int i = 0; i < h; i++){
        cin >> tmp;
        s.push_back(tmp);
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w-1; j++){
            if(s[i][j] == 'T' && s[i][j+1] == 'T'){
                s[i][j] = 'P';
                s[i][j+1] = 'C'; 
            }
        }
    }

    for(int i = 0; i < h; i++)
        cout << s[i] << endl;
    return 0;

}