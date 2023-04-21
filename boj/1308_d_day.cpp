//Made By R3dzone
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int yy,mm,dd;
    int dday_yy,dday_mm,dday_dd;
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};    
    scanf("%d %d %d",&yy,&mm,&dd);
    scanf("%d %d %d",&dday_yy,&dday_mm,&dday_dd);

    int gapy = dday_yy - yy;
    int gapm = dday_mm - mm;
    int gapd = dday_dd - dd;
    int leap_d = 0;

    int cnt = yy;
    if(mm > 2)cnt++;
    if(dday_mm <= 2){
        dday_yy--;
    }
    while(cnt <= dday_yy){
        if(cnt%100 == 0){
            if(cnt%400 == 0){
                leap_d++;
                cnt++;
                continue;
            }
            cnt++;
            continue;
        }
        if(cnt%4 == 0){
            leap_d++;
        }
        cnt++;
    }

    if(gapd < 0){
        gapm--;
        gapd += month[(12+dday_mm-2)%12];
    }
    if(gapm < 0){
        gapy--;
        gapm += 12;
    }

    //cout << "yy:" << gapy << "mm:" << gapm << "dd:" << gapd << endl;

    if(gapy >= 1000) cout << "gg" << endl;
    else{
        int tmp = 0;
        for(int i = mm; i < mm+gapm; i++){
            tmp += month[(12+i-1)%12];
            //cout << month[(12+i-1)%12] << endl;
        }
        cout << "D-" << (gapy*365)+gapd+leap_d+tmp << endl;
    }
}