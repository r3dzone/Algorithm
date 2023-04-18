//Made By R3dzone
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 15;
int n,queen_num = 0;

int chess[MAXN+5]; //chess[1]:1 == 1,1에 queen 존재 chess[행]:열

bool promising(int x){//x:행
    for(int i = 0; i < x; i++)
        if(chess[i] == chess[x]|| abs(chess[i] - chess[x]) == abs(i - x)) return false; //행 차이 == 열 차이 : 대각선에 위치
    return true;
}

void queen(int x){ //x:행
    if(x == n){
        queen_num++;
        return;
    }else{
        for(int i = 0; i < n ; i++){
            chess[x] = i;
            if(promising(x)){
                queen(x+1);
            }
        }
    }
    return;
}

int main(){
    memset(chess,0,sizeof(chess));
    scanf("%d",&n);
    queen(0);
    printf("%d\n",queen_num);
    return 0;
}
