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


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int dp[100005][320];
int path[100005][320];

int sm[320];

void init(){
    sm[0]=0;
    FREP(i,1,319)sm[i]=sm[i-1]+i;
}

int solve(int val, int idx, int n){
    if(idx>n && val==0)return 0;
    if(idx>n)return 100000;
    if(dp[val][idx]!=-1)return dp[val][idx];
    int ret1 = 100000,ret2 = 100000;
    if((val-sm[idx])>=0)ret1 = 1+solve(val-sm[idx],idx,n);
    ret2 = solve(val,idx+1,n);
    if(ret1<ret2)path[val][idx]=1;
    else path[val][idx]=0;
    return dp[val][idx] = min(ret1,ret2);
}

void check(){
    FREP(i,1,100000){
        if(dp[i][1]>26){cout<<"hobe na\n";cout<<dp[i][1]<<"\n";}
    }
}

void printpath(int val, int idx){
    if(idx>319)return;
    if(path[val][idx]==1){
        cout<<sm[idx]<<" ";
        printpath(val-sm[idx],idx);
    }
    else{
        printpath(val,idx+1);
    }
    return;
}

vector<int>partitiions;

int greedy(int val){
    int idx = 319;
    int cnt = 0;
    while(val>0){
        if(sm[idx]>val)idx--;
        else{
            cnt++;
            val-=sm[idx];
            partitiions.PB(idx);
        }
    }
    //cout<<"\n";
    return cnt;
}

void checkgreedy(){
    int mxx = -1;
    FREP(i,1,100000){
        if(greedy(i)>26)cout<<"hobe na\n";
        mxx = max(mxx,greedy(i));
    }
    cout<<mxx<<"\n";
}

int main(){
    init();
    //memset(dp,-1,sizeof(dp));
    //checkgreedy();
    int k;
    scanf("%d",&k);
    int sz = greedy(k);
    FREP(i,0,sz-1){
        FREP(j,1,partitiions[i]+1){
            printf("%c",(i+'a'));
        }
    }
    printf("\n");
    //printpath(k,1);
    return 0;
}
