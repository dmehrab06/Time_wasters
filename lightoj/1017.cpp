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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

int dp[205][205];
int mapy[205];
int cnty[205];
int sz;
int W;
PII pts[205];
void init(){
    FREP(i,0,200)FREP(j,0,200)dp[i][j]=-1;
    FREP(i,0,200)cnty[i]=0;
}

int bsl(int key){
    int l=1;
    int r=sz;
    while(true){
        int mid=(l+r)/2;
        if(mapy[mid]<=key){
            if((mid+1)<=sz && mapy[mid+1]<=key){
                l=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            r=mid;
        }
    }
}

int solve(int i, int mv){
    if(i>sz || mv<=0)return 0;
    if(dp[i][mv]!=-1)return dp[i][mv];
    int ret1=0,ret2=0;
    int by=mapy[i];
    int upy=by+W;
    int lst=bsl(upy);
    int total=cnty[lst]-cnty[i-1];
   // printf("from %d total is %d\n",i,)
    ret1=total+solve(lst+1,mv-1);
    ret2=solve(i+1,mv);
    return (dp[i][mv]=max(ret1,ret2));
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,k;
        scanf("%d %d %d",&n,&W,&k);
        FREP(i,1,n){
            int x,y;
            scanf("%d %d",&x,&y);
            PII p=make_pair(y,x);
            pts[i]=p;
        }
        sort(pts+1,pts+1+n);

        //printf("\n");
        init();
        sz=1;
        mapy[1]=pts[1].first;
        cnty[1]=1;
        int cury=mapy[1];
        FREP(i,2,n){
            int yy=pts[i].first;
            if(yy!=cury){
                cury=yy;
                sz++;
            }
            mapy[sz]=yy;
            cnty[sz]++;
        }
        FREP(i,1,sz){
            cnty[i]=cnty[i-1]+cnty[i];
        }

        int ans=solve(1,k);
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}
