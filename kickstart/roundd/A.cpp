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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

pair<PII,int> rides[2003];

map<PII,int>dp;

int Ts, Tf, N;

int solve(int city, int nextreachtime){
    if(city==0)return 0;
    if((rides[city].first.first+rides[city].second)>nextreachtime){
        return -10000000;
    }
    PII curkey = make_pair(city,nextreachtime);
    if(dp.find(curkey)!=dp.end()){
        return dp[curkey];
    }
    int ret1 = -10000000, ret2 = -10000000;
    int st1 = (nextreachtime-rides[city].second-Ts);
    int st2 = (nextreachtime-rides[city].second);
    if(st1>=rides[city].first.first)ret1 =1+ solve(city-1,st1);
    if(st2>=rides[city].first.first)ret2 = solve(city-1,st2);
    return dp[curkey] = max(ret1,ret2);

}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        scanf("%d %d %d",&N,&Ts,&Tf);
        dp.clear();
        FREP(i,1,N-1){
            int s,f,d;
            scanf("%d %d %d",&s,&f,&d);
            pair<PII,int>pp = make_pair(make_pair(s,f),d);
            rides[i] = pp;
        }
        int ans = solve(N-1,Tf);
        printf("Case %d: ",cs);
        if(ans<0){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
