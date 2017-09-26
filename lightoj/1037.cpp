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

char damage[18][18];
int health[18];

int dp[70005];

bool allused(int mask, int n){
    int mm = 1;
    FREP(i,1,n){
        if(!(mask&mm))return false;
        mm<<=1;
    }
    return true;
}

int setbit(int mask, int pos){return (mask|(1<<pos));}
bool isset(int mask, int pos){return (mask&(1<<pos));}
void init(){MSET(dp,-1);}

int solve(int mask, int n){
    if(allused(mask,(n+1)))return 0;
    if(dp[mask]!=-1)return dp[mask];
    int mnn = 1000000007;
    FREP(i,0,n){
        if(isset(mask,i)){
            //i th guli or kache ase
            FREP(j,1,n){
                if(!isset(mask,j)){
                    //j ke mere dekhte pari
                    int dmg = damage[i][j]-'0';
                    if(dmg==0)continue;
                    int shotneeded = health[j]/dmg+((health[j]%dmg)?1:0);
                    //cout<<i<<" to kill "<<j<<" needs "<<shotneeded<<"\n";
                    mnn = min(mnn,shotneeded+solve(setbit(mask,j),n));
                }
            }
        }
    }
    return dp[mask] = mnn;
}

void shift(int idx, int n){
    RFREP(i,n,1)damage[idx][i]=damage[idx][i-1];
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        init();
        int n;
        scanf("%d",&n);
        FREP(i,1,n)scanf("%d",&health[i]);
        FREP(i,1,n)scanf("%s",damage[i]);
        FREP(i,1,n)shift(i,n);
        FREP(j,1,n)damage[0][j]='1';
        damage[0][0]='0';

        int ans = solve(1,n);
        /*FREP(i,0,(1<<(n+1))){
            cout<<"dp["<<i<<"]: "<<dp[i]<<"\n";
        }*/
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
