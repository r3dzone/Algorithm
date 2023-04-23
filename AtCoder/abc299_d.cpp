//Made By R3dzone
#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
int main(){
    cin >> n;
    int left = 1 ,mid,right = n;
    int tmp;

    while(left != right-1){
        mid = (left + right) >> 1;
        cout << "? " << mid << endl;
        cin >> tmp;
        if(tmp == 0) left = mid;
        else right = mid;
    }
    cout << "! " << left << endl;
}