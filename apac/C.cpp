//ds--
//algo--binary search

#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#define eps 0.0000000001
using namespace std;

vector<double>costs;
int M;
double calc(double r){
    double init=1.00;
    double val=0.000;
    for(int i=M;i>0;i--){
        val=val+costs[i]*init;
        init=init*(1.00+r);
    }
    val=val-costs[0]*init;
    return val;
}

double calcr(double low, double high){
    double mid=(low+high)/(2.00);
    double getval=calc(mid);
    cout<<getval<<"\n";
    if(fabs(getval-0.00)<eps){
        return mid;
    }
    else{
        double nowdis=fabs(getval-0.00);
        double getr=calc(mid+0.000000000000001);
        double getl=calc(mid-0.000000000000001);
        double ldis=fabs(getl-0.00);
        double rdis=fabs(getr-0.00);
        if(rdis<ldis){
            return calcr(mid+0.000000000000001,high);
        }
        else{
            return calcr(low,mid-0.000000000000001);
        }
    }
}

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        //int n;
        cin>>M;
        costs.clear();
        for(int i=0;i<=M;++i){
            double val;
            cin>>val;
            costs.push_back(val);
        }
       // sort(all.begin(),all.end());
        double v=calcr(-2.000,2.000);
        printf("Case #%d: %.10lf\n",cs++,v);
    }
    return 0;
}
