/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int setbit(int n, int i){return (n|(1<<i));}
int resetbit(int n, int i){return (n&(~(1<<i)));}
bool isset(int n, int i){return (n&(1<<i));}
int cnt(int n){ int c=0; FREP(i,0,18)if(n&(1<<i))c++; return c;}

bool iscolinear(PII pt1, PII pt2, PII pt3){
    int x1 = pt1.first; int y1 = pt1.second;
    int x2 = pt2.first; int y2 = pt2.second;
    int x3 = pt3.first; int y3 = pt3.second;

    int val1 = (y3-y1)*(x2-x1);
    int val2 = (x3-x1)*(y2-y1);

    return (val1==val2);
}

PII points[20];
int dp[70005];
int N;
int linemask[21][21];

void init(){
    MSET(dp,-1);
    MSET(linemask,0);
}

void pre(int n){
    FREP(i,0,n-1){
        FREP(j,0,n-1){
            if(i==j)continue;
            FREP(k,0,n-1){
                if(iscolinear(points[i],points[j],points[k])){
                    linemask[i][j] = setbit(linemask[i][j],k);
                }
            }
        }
    }
    //FREP(i,0,(n-1))FREP(j,0,(n-1))cout<<"linemask["<<i<<"]["<<j<<"] = "<<linemask[i][j]<<"\n";
}

int solve(int mask, int N, int MAXMASK){
    if(mask==MAXMASK)return 0;

    if(dp[mask]!=-1)return dp[mask];

    int ret=MXX;

    int f = 0;
    FREP(i,0,N-1){
        //fixing one point
        if(!isset(mask,i)){
            //cout<<"doing for i = "<<i<<"\n";
            f = 1;
            //ei point ke fix dhore sob test korbo.... and no other
            FREP(j,0,(N-1)){
                if(i==j)continue;
                int sweep = linemask[i][j];
                int nmask  = mask|sweep;
                ret = min(ret,1+solve(nmask,N,MAXMASK));
            }
        }

        if(f)break;
    }
    dp[mask]=ret;
    return dp[mask];

}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        //int n;
        int N, MAXMASK;
        scanf("%d",&N);
        FREP(i,0,(N-1)){
            //int x,y;
            scanf("%d %d",&points[i].first,&points[i].second);
        }
        init();
        MAXMASK=(1<<N)-1;
        pre(N);
        //cout<<"pre hoise\n";
        int ans=solve(0,N,MAXMASK);
        if(N==1)ans = 1;
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
