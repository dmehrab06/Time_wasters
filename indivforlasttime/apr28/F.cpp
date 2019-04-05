/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define PDD pair<double,double>
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
#define MSET(a,b) memset(a,b,sizeof(a))
#define MDD 1000000007
#define PI acos(-1.0)
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double xx[50003];
double yy[50003];
double zz[50003];

bool isok(int n, double h, double L, double R){
    //cout<<"trying for height "<<h<<"\n";
    vector < pair<double,int> >litpoints;
    for(int i = 1; i<=n ; ++i){
        if(yy[i]<h)continue;
        else{
            double ang = tan(zz[i]);
            double dx = yy[i]-h;
            double LX = xx[i]-ang*dx;
            double RX = xx[i]+ang*dx;
            litpoints.push_back(make_pair(LX,0));
            litpoints.push_back(make_pair(RX,2));
        }
    }
    litpoints.push_back(make_pair(L,1));
    litpoints.push_back(make_pair(R,1));
    SORTV(litpoints);

    int active = 0;
    /*FREP(i,0,litpoints.size()-1){
        cout<<litpoints[i].first<<" "<<litpoints[i].second<<"\n";
    }*/
    FREP(i,0,litpoints.size()-1){
        double curx = litpoints[i].first;
        if(INRANGED(curx,L,R) && active<=0){
            //cout<<"trying for height "<<h<<"\n";
            return false;
        }
        if(litpoints[i].second==0)active++;
        else if(litpoints[i].second==2)active--;
    }
    return true;
}

double solve(int n, double L, double R, double mxY){
    double lo = 0.0;
    double hi = mxY;
    FREP(i,1,100){
        double m = (lo+hi)/2.0;
        if(isok(n,m,L,R)){
            lo = m;
        }
        else{
            hi = m;
        }
    }
    if(isok(n,hi,L,R))return hi;
    else return lo;
}

int main(){
    int n; double L,R;
    scanf("%d %lf %lf",&n,&L,&R);
    double mxx = 0.0;
    FREP(i,1,n){
        scanf("%lf %lf %lf",&xx[i],&yy[i],&zz[i]);
        zz[i] = (zz[i]*PI)/180.0;
        mxx = max(mxx,yy[i]);
    }
    printf("%.9lf\n",solve(n,L,R,mxx));
    return 0;
}
