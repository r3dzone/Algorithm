//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

int c,n;
int cost,customer;
vector<int> city_cost;
vector<int> city_customer;
int memo[1000+5];

int dp(int x){
    if(x <= 0) return 0;
    
    int &ret = memo[x];
    if(ret != -1) return ret;

    int min_cost = 1234567890;

    for(int i = 0; i < n; i++)
        min_cost = min(min_cost,dp(x-city_customer[i])+city_cost[i]);
    return ret = min_cost;
}

int main(){
    cin >> c >> n;
    for(int i = 0; i < n; i++){
        cin >> cost >> customer;
        city_cost.push_back(cost);
        city_customer.push_back(customer);
    }
    memset(memo,-1,sizeof(memo));
    cout << dp(c) << endl;
    return 0;
}