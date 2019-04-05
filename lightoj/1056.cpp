#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MAXN 10003
#define MAXIT 20

using namespace std;
using namespace __gnu_pbds;

typedef tree < pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double sq(double a){
    return a*a;
}

double calcr(double a, double b){
    return sqrt(sq(a)+sq(b));
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int a,b;
        char s[2];
        scanf("%d %s %d",&a,s,&b);
        double loa = 0;
        double hia = (double)(1e18);
        for(int it = 1; it<=100; ++it){
            //cout<<loa<<" "<<hia<<"\n";
            double mida = (loa+hia)/2.0;
            double midb = (mida*b)/(double)a;
            double alph = 2.0*atan(midb/mida);
            double peri = alph*calcr(mida,midb)+2.0*mida;
            if(peri<(double)400){
                loa = mida;
            }
            else{
                hia = mida;
            }
        }
        double lob = (loa*b)/(double)a;
        printf("Case %d: %.6lf %.6lf\n",cs,loa,lob);
    }
    return 0;
}