#include <vector>
#include <iostream>
#include <string>

int time(std::string t){
    int h=(t[0]-'0')*10+(t[1]-'0');
    int m=(t[3]-'0')*10+(t[4]-'0');
    int tt=h*60+m;
    return tt;
}
int parkingCost(std::string timeIn, std::string timeOut) {
    int ti=time(timeIn);
    int to=time(timeIn);
    int dif=to-ti;
    if(dif<0){
        dif+=24*60;
    }
    std::cout<<dif<<"\n";
    int cost=0;
    dif-=30;
    int nextval=40;
    for(;nextval<=120 && dif>=10;nextval+=10){
        cost+=1;
        dif-=10;
    }
    if(nextval<=120 && dif>0){
        cost+=1;
        dif=0;
    }
    if(dif>0){
        while(dif>=10){
            cost+=2;
            dif-=10;
        }
        if(dif>0){
            cost+=2;
        }
    }
    return cost;
}

int main(){
    std::cout<<parkingCost("07:02","07:42")<<"\n";
}
