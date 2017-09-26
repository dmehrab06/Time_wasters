/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define MAXSTICK 21
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int setbit(int mask, int pos){return (mask|(1<<pos));}
int resetbit(int mask, int pos){return (mask&(~(1<<pos)));}
bool isset(int mask, int pos){return (mask&(1<<pos));}

int bakiase(int mask, int sz){
    int dummy = 1;
    int cnt = 0;
    FREP(i,1,sz){
        if(!(mask&dummy))cnt++;
        dummy<<=1;
    }
    return cnt;
}

int sticklen[MAXSTICK];
int dp[1<<MAXSTICK];

void init(){
    memset(dp,-1,sizeof(dp));
}

bool can(int len, int mask, int sum, int tot){
    if(dp[mask]!=-1)return dp[mask];
    if(len>(sum/4))return 0;
    if(len==(sum/4)){
        if(bakiase(mask,tot)==0)return 1; //sob stick use kora sesh
        else len = 0; //ager ta fixed notun set of stick now
    }
    FREP(i,1,tot){
        if(!isset(mask,(i-1))){
            if(can((len+sticklen[i]),setbit(mask,(i-1)),sum,tot)){
                return (dp[mask]=1);
            }
        }
    }
    return (dp[mask]=0);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sm = 0;
        FREP(i,1,n){
            scanf("%d",&sticklen[i]);
            sm+=sticklen[i];
        }
        init();
        printf("%s\n",(sm%4==0 && can(0,0,sm,n))?"yes":"no");
    }
    return 0;
}
