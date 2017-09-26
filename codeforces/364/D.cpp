#include <bits/stdc++.h>
#define MXX 1000000007
#define eps 0.0000000001
using namespace std;

int main(){
    int n,k; double l,v1,v2;
    cin>>n>>l>>v1>>v2>>k;
    double discoveredwalking=0.0;
    double dislefttocoverbybus=l;
    int left=n;
    double timegone=0.0;
    int it=1;
    int f=1;
    while(left>k){
        cout<<"it "<<it<<"\n";
        left-=k;
        double t1=(dislefttocoverbybus)/v2;
        cout<<t1<<"\n";
        timegone+=t1;
        cout<<timegone<<"\n";
        discoveredwalking=discoveredwalking+v1*t1;
        if(discoveredwalking>=l){
            f=0;
            break;
        }
        cout<<discoveredwalking<<"\n";
        double tt=(l-discoveredwalking)/(v2+v1);
        timegone+=tt;
        cout<<timegone<<"\n";
        discoveredwalking=discoveredwalking+tt*v1;
        cout<<discoveredwalking<<"\n";
        dislefttocoverbybus=l-discoveredwalking;
        cout<<dislefttocoverbybus<<"\n";
        if(discoveredwalking>=l){
            f=0;
            break;
        }
        it++;
    }
    double extra=(dislefttocoverbybus)/v2;
    if(f)timegone+=extra;
    cout<<timegone<<"\n";
}
