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

int g[103][103];
int dp[15][10005];
PII requests[15];

void init(int n){
    memset(dp,-1,sizeof(dp));
    FREP(i,1,n){
        FREP(j,1,n){
            if(i==j){
                g[i][j]=0;
            }
            else{
                g[i][j]=1000000009;
            }
        }
    }
}

void floyd(int n){
    FREP(k,1,n){
        FREP(i,1,n){
            FREP(j,1,n){
                int dis = g[i][k]+g[k][j];
                if(dis<g[i][j]){
                    g[i][j]=dis;
                }
            }
        }
    }
}

void takeg(int n, int m){
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(g[v][u],w);
    }
}

int takerequests(int z, int home){
    int actual = 0;
    FREP(i,1,z){
        int u,v,parcel;
        scanf("%d %d %d",&u,&v,&parcel);
        FREP(k,1,parcel){
            requests[++actual] = make_pair(u,v);
        }
    }
    requests[0]=make_pair(home,home);
    return actual;
}

int solve(int prevreq, int bitmask, int totalreq, int home){
    int cur = requests[prevreq].second;
    int left = bakiase(bitmask,totalreq);
    if(left==0){
        return dp[prevreq][bitmask] = g[cur][home];
    }
    if(dp[prevreq][bitmask]!=-1)return dp[prevreq][bitmask];
    int mnn = 1000000009;
    FREP(i,0,totalreq-1){
        if(!isset(bitmask,i)){
            //ei request ekhn o kora hoy nai, kore dekha jete pare
            int src = requests[i+1].first;
            int des = requests[i+1].second;
            int nmask = setbit(bitmask,i);
            mnn = min(mnn, g[cur][src]+g[src][des]+solve(i+1,nmask,totalreq,home));
        }
    }
    //cout<<"returning min "<<mnn<<" from "<<"( "<<prevreq<<","<<bitmask<<" )\n";
    return dp[prevreq][bitmask] = mnn;
}

void print(int n){
    FREP(i,1,n){
        FREP(j,1,n){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,b,m;
        scanf("%d %d %d",&n,&m,&b);
        init(n); takeg(n,m);
        int req; scanf("%d",&req);
        int tot = takerequests(req,b);
        floyd(n); int ans = solve(0,0,tot,b);
        printf("%d\n",ans);
    }

    return 0;
}
