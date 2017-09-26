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

LLI dp1[200][301][301]; //dp[gcduptonow][seperatorused][prevseperatoridx]
LLI dp2[200][301][301];

char digarr[301];

int mapvals;
int n,x,y,m;

map<LLI,int>cmprs;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

void init(){
    mapvals=1;
    cmprs.clear();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
}

LLI gcd(LLI a, LLI b){
    if(a==0 && b==0){
        return 0;
    }
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

LLI solve(LLI gcduptonow, int used, int prevsep_pos){
    //cout<<"at g: "<<gcduptonow<<", used: "<<used<<", prevpos: "<<prevsep_pos<<"\n";
    if(prevsep_pos==n){
        if(used>=x && used<=y){
            return gcduptonow;
        }
        else{
            return -100;
        }
    }
    if(used>y)return -100;
    if(gcduptonow==1)return 1;
    if(gcduptonow<200){
        if(dp1[gcduptonow][used][prevsep_pos]!=-1){
            return dp1[gcduptonow][used][prevsep_pos];
        }
        LLI s=0;
        LLI ret1=-100;
        for(int i=prevsep_pos+1;i<=min(prevsep_pos+m,n);++i){
            s=s*10+digarr[i]-'0';
            LLI g=gcd(s,gcduptonow);
            ret1=max(ret1,solve(g,used+(i<n?1:0),i));
        }
        return dp1[gcduptonow][used][prevsep_pos]=ret1;
    }
    else{
        int cmprsgcd;
        if(cmprs.find(gcduptonow)!=cmprs.end()){
            cmprsgcd=cmprs[gcduptonow];
        }
        else{
            cmprsgcd=mapvals;
            cmprs[gcduptonow]=cmprsgcd;
            mapvals++;
        }
        if(dp2[cmprsgcd][used][prevsep_pos]!=-1){
            return dp2[cmprsgcd][used][prevsep_pos];
        }
        LLI s=0;
        LLI ret1=-100;
        for(int i=prevsep_pos+1;i<=min(prevsep_pos+m,n);++i){
            s=s*10+digarr[i]-'0';
            LLI g=gcd(s,gcduptonow);
            ret1=max(ret1,solve(g,used+(i<n?1:0),i));
        }
        return dp2[cmprsgcd][used][prevsep_pos]=ret1;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        scanf("%s",digarr);
        RFREP(i,(n),1){
            digarr[i]=digarr[i-1];
        }
        scanf("%d %d %d",&m,&x,&y);
        y++;
        LLI s=0;
        LLI mxx=0;
        for(int i=1;i<=min(n,m);++i){
            s=s*10+digarr[i]-'0';
            mxx=max(mxx,solve(s,(i<n?1:0),i));
        }
        printf("%lld\n",mxx);
    }
    return 0;
}
