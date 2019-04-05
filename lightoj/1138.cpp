#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAXN 10003
#define MAXIT 20
#define PI acos(-1.0)
#define eps 1e-5

using namespace std;
using namespace __gnu_pbds;

typedef tree < pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

long long getzero(long long v){
    long long z = 0;
    long long c = 5;
    while(c<=v){
        z = z+v/c;
        c = c*5;
    }
    return z;
}

int main(){
    int t;
    scanf("%d",&t);
    //cout<<"hello "<<asin(1.33333/(4.00-1.33333))*2.0*6<<"\n";
    //cout<<2.0*PI<<"\n";
    for(int cs = 1; cs<=t; ++cs){
        int Q;
        scanf("%d",&Q);
        long long lo = 0, hi = 2e18;
        while(lo+1<hi){
            long long mid = lo + (hi-lo)/2;
            if(getzero(mid)<Q){
                lo = mid;
            }
            else{
                hi = mid;
            }
        }
        if(getzero(lo)==Q){
            printf("Case %d: %lld\n",cs,lo);    
        }
        else if(getzero(hi)==Q){
            printf("Case %d: %lld\n", cs,hi);
        }
        else{
            printf("Case %d: impossible\n",cs);
        }
        
    }
    return 0;
}