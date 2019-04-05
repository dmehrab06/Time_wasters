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

double getang(double r, double R, int n){
    double ang = asin(r/(R-r));
    return 2.0*ang*(double)n;
}

int main(){
    int t;
    scanf("%d",&t);
    //cout<<"hello "<<asin(1.33333/(4.00-1.33333))*2.0*6<<"\n";
    //cout<<2.0*PI<<"\n";
    for(int cs = 1; cs<=t; ++cs){
        double R; int n;
        scanf("%lf %d",&R,&n);
        double lo = 0.0, hi = R/2.0;
        for(int it = 1; it<=100; ++it){
            //cout<<lo<<" "<<hi<<"\n";
            double r = (lo+hi)/2.0;
            double v = getang(r,R,n);
            if(v<(2.0*PI)){
                lo = r;
            }
            else{
                hi = r;
            }
        }
        printf("Case %d: %.10lf\n",cs,lo);    
    }
    return 0;
}