/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int speeds[103];

double eq(int n, double lambda){
    
    double s = 0.0;

    for(int i = 1; i<=n; ++i){
        double lob = speeds[i];
        double hor = (1.0-lambda*lambda*speeds[i]*speeds[i]);
        s = s+(lob)/sqrt(hor);
    }

    return lambda*100*s;
}

double solve(int n, int d){
    //cout<<"ekhane\n";
    int mxx = 0;
    
    for(int i = 1; i<=n; ++i){
        mxx = max(mxx, speeds[i]);
    }

    double lo = -1.0/((double)mxx);
    double hi = 1.0/((double)mxx);

    for(int it = 1; it<=40; ++it){
        double m = (lo+hi)/2.0;
        double fx = eq(n,m);
        if(fx>d){
            hi = m;
        }
        else{
            lo = m;
        }
    }
    return lo;
}

double solve_eq(int n, int d, int s){
    double vumi = (double)d*(double)d;
    double lombo = (double)n*100.00;
    double otivuj = sqrt(vumi+lombo*lombo);
    return otivuj/(double)s;
}

double get_time(int n, double l){
    double s = 0.0;
    for(int i = 1; i<=n; ++i){
        double x = (100.0*l*speeds[i])/(sqrt(1.0-l*l*speeds[i]*speeds[i]));
        s = s+(sqrt(10000.0+x*x))/(double)speeds[i];
    }
    return s;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; ++cs){
        int n,d;
        scanf("%d %d",&n,&d);
        bool iseq = true;
        for(int i = 1; i<=n; ++i){
            scanf("%d",&speeds[i]);
            if(i>=2 && speeds[i]!=speeds[i-1]){
                iseq = false;
            }
        }

        if(iseq){
            printf("Case %d: %.8lf\n",cs,solve_eq(n,d,speeds[1]));
        }
        else{
            double lambda = solve(n,d);

            //cout<<"lambda: "<<lambda<<"\n";
            printf("Case %d: %.8lf\n",cs,get_time(n,lambda));
        }
        
    }
    return 0;
}
