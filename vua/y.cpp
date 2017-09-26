#include <iostream>
#define MAXXX 100000000007
using namespace std;
int main(){
    int n;
    cin>>n;
    int cashierhas=0;
    int cashiernotes[100];
    cashiernotes[1]=0;
    cashiernotes[5]=0;
    cashiernotes[10]=0;
    cashiernotes[20]=0;
    cashiernotes[50]=0;
    int go[5]={1,5,10,20,50};
    int f=1;
    while(n--){
        int k,f1,f2,f3,f4,f5;
        cin>>k>>f1>>f2>>f3>>f4>>f5;
        int gives=f1+f2*5+f3*10+f4*20+f5*50;
        int toreturn=(gives-k);
        if(toreturn>cashierhas){
            f=0;
        }
        else{
            //cashierhas-=toreturn;
            cashierhas+=gives;
            int tmp=toreturn;
            cashiernotes[1]+=f1;
            cashiernotes[10]+=f3;
            cashiernotes[5]+=f2;
            cashiernotes[20]+=f4;
            cashiernotes[50]+=f5;
            for(int i=0;i<5;++i){
                int cur=go[i];
                int need=toreturn/cur;
                int cashiergives=min(cashiernotes[cur],need);
                int given=cur*cashiergives;
                cashiernotes[cur]-=cashiergives;
                toreturn=toreturn-(given);
            }
            if(toreturn!=0){
                f=0;
            }
            else{
                cashierhas-=tmp;
            }
        }
    }
    if(f){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}
