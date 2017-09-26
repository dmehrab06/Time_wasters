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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double getc(double x, double y, double c , double w){
    double t1 = acos(w/y); double t2 = acos(w/x);
    double K1 = tan(t1); double K2 = tan(t2);
    double cc = (w*K1*K2)/(K1+K2);

    return cc;
}

double ter_search(double x, double y, double c){
    double lo = 0.0;
    double hi = min(x,y);
    while(fabs(hi-lo)>eps){
        double w = (lo+hi)/2.0;
        double cc = getc(x,y,c,w);
        //printf("cc here %.3lf\n",cc);
        if(fabs(cc-c)<eps)return w;

        else{
            double ccr = getc(x,y,c,w+0.00000001);
            double ccl = getc(x,y,c,w-0.00000001);
            if(cc<c){
                if(ccr>cc){
                    lo=w;
                }
                else{
                    hi=w;
                }
            }
            else{
                if(ccl<cc){
                    hi = w;
                }
                else{
                    lo = w;
                }
            }
        }
    }
    return lo;
}

int main(){

    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        double x,y,c;
        scanf("%lf %lf %lf",&x,&y,&c);
        /*FREP(w,1,min(x,y)){
            printf("for w: %d c is %.3lf\n",w,getc(x,y,c,(double)w));
        }*/
        //cout<<getc(x,y,c,26.0328775442);
        double ans = ter_search(x,y,c);
        printf("Case %d: %.9lf\n",cs,ans);
    }
    return 0;
}
