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
using namespace std;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;


LLI dp[21][4]; //last index , if last index was zero

void init(){
    MSET(dp,-1);
}

LLI solve(int idx, int lastzero, int n, int k){
    if(idx==n){
        if(lastzero==1)return dp[idx][lastzero]=k-1;
        else return dp[idx][lastzero]=k;
    }
    if(dp[idx][lastzero]!=-1)return dp[idx][lastzero];
    LLI sm = 0;
    if(lastzero){
        FREP(i,1,(k-1)){
            sm+=solve(idx+1,0,n,k);
        }
    }
    else{
        FREP(i,0,(k-1)){
            if(i==0){
                sm+=solve(idx+1,1,n,k);
            }
            else{
                sm+=solve(idx+1,0,n,k);
            }
        }
    }
    return dp[idx][lastzero] = sm;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    init();
    LLI ans = solve(1,1,n,k);
    //FREP(i,0,n){
      //  cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    //}
    printf("%lld\n",ans);
    return 0;
}
