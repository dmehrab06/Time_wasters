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
#define MXX 1000000000000000000;
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

vector<double>lens;

vector< pair<double,double> >pts;

PII marr[16];

double dp[2000005][12];

int m;

double solve(int len, int stripe){
    if(len<=0)return (double)0.0;

    if(stripe>m)return (double)MXX;

    if(dp[len][stripe]>-1.0){
        return dp[len][stripe];
    }

    double ret1=(double)marr[stripe].second+solve(len-marr[stripe].first,stripe);
    double ret2=solve(len,stripe+1);

    return dp[len][stripe]=min(ret1,ret2);
}

void init(){
    lens.clear();
    pts.clear();
    memset(dp,-1,sizeof(dp));
}

void calc(){
    int l=pts.size();
    FREP(i,0,(l-1)){
        double ll=sqrt((pts[i].first-pts[(i+1)%l].first)*(pts[i].first-pts[(i+1)%l].first)+(pts[i].second-pts[(i+1)%l].second)*(pts[i].second-pts[(i+1)%l].second));
        lens.PB(ll);
    }
}

double calc2(){
    int l=lens.size();
    double ans=0.0;
    FREP(i,0,(l-1)){
        double curlen=lens[i];
        int lllen=(int)roundf(curlen);
        //double abslen=fabs(curlen);
        if (fabsf(roundf(curlen) - curlen) <= eps) {
            //printf("integer\n");
        }
        else{
            lllen++;
        }
        ans+=solve(lllen,1);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            int x,y;
            scanf("%d %d",&x,&y);
            pair<double,double>oka=make_pair((double)x,(double)y);
            pts.PB(oka);
        }
        calc();
        scanf("%d",&m);
        FREP(i,1,m){
            scanf("%d %d",&marr[i].first,&marr[i].second);
        }
        double ans=calc2();
        printf("%.0lf\n",ans);

        //printf("%d\n",total);
    }
    return 0;
}
