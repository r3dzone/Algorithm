// Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> vec;
vector<int> button;
int btn_size;
int min_num = 1234567890;

void min_diff(string str, int x){ //x == digit
    if(str.size() == x){
        int diff = abs(n - stoi(str)) + x;
        if(diff < min_num) min_num = diff;
        return;
    }
    for(int i = 0; i < btn_size; i++)
        min_diff(str+to_string(button[i]),x);
    return;
}

int main()
{
    cin >> n >> m;
    int tmp;
    for (int i = 0; i < m; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    int flag;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < vec.size(); j++){
            flag = 1;
            if (vec[j] == i){
                flag = 0;
                break;
            }
        }
        if (flag)
            button.push_back(i);
    }
    btn_size = button.size();
    
    for(int i = 1; i <= 6; i++)
        min_diff(string(),i);
    
    if(m == 0)
        min_num = to_string(n).size();

    if(abs(n-100) < min_num) cout << abs(n-100) << endl;
    else cout << min_num << endl;
    return 0;
}