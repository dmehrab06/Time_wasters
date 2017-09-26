/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

double ini_pow[100005];
double lose_rate[100005];
int needcharge[100005];

bool can(double desired_time, double c_pow, int n){
    memset(needcharge,0,sizeof(needcharge));
    int f=1;
    FREP(i,1,n){
        double tikbe=ini_pow[i]/lose_rate[i];
        if(tikbe<desired_time){
            f=0;
            needcharge[i]=1;
        }
    }
    if(f)return true;
    long double tot_charge=(long double)c_pow*desired_time;
    FREP(i,1,n){
        if(needcharge[i]){
            long double tot_lagbe=(long double)lose_rate[i]*desired_time;
            long double diff=tot_lagbe-ini_pow[i];
            if(diff>tot_charge){
                return false;
            }
            tot_charge-=diff;
        }
    }
    return true;
}

int main(){
    int n;
    double cp;
    scanf("%d %lf",&n,&cp);
    double oka=0.0;
    FREP(i,1,n){
        scanf("%lf %lf",&lose_rate[i],&ini_pow[i]);
        oka+=lose_rate[i];
    }
    if(cp>oka || fabs(cp-oka)<eps){
        printf("-1\n");
        return 0;
    }
    double lo=eps;
    double hi=100000000000.00;
    FREP(it,1,100){
        double mid=(lo+hi)/2.0;
        if(can(mid,cp,n)){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    printf("%.9lf\n",lo);
    return 0;
}
