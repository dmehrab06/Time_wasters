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


typedef tree < PII, null_type, less<PII>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

//int dp[10][10];

vector< VI >g;
int vis[203];
int col[203];

void init(int n){
    g.clear();
    FREP(i,0,(n+3)){
        VI line; g.PB(line);
    }
    MSET(col,-1);
}

pair<bool,int> isbipartite(int src){
    queue<int>bipq;
    bipq.push(src);
    col[src] = 0;
    bool fff = true;
    int cnt[2]; MSET(cnt,0);
    cnt[0] = 1;
    while(!bipq.empty()){
        int ff = bipq.front();
        //cout<<"queue front "<<ff<<"\n";
        bipq.pop();
        int curcol = col[ff];
        FREP(i,0,g[ff].size()-1){
            int v = g[ff][i];
            if(col[v]==-1){
                //cout<<v<<" has not been colored\n";
                col[v] = 1-curcol;
                cnt[col[v]]++;
                bipq.push(v);
            }
            else{
                if(col[v]==curcol){
                    //cout<<v<<" has been wrongly colored\n";
                    fff = false;
                }
                else{
                    //cout<<v<<" has been rightly colored\n";
                }
            }
        }
    }
    return make_pair(fff,max(cnt[0],cnt[1]));
}

void takeinp(int n){
    FREP(i,1,n){
        int enemy;
        scanf("%d",&enemy);
        FREP(j,1,enemy){
            int v;
            scanf("%d",&v);
            if(v<=n){
                g[i].PB(v);
                g[v].PB(i);
            }
        }
    }
}

int solve(int n){
    int ss = 0;
    FREP(i,1,n){
        if(col[i]==-1){
            pair<bool,int>chk = isbipartite(i);
            if(chk.first){
                ss+=chk.second;
            }
        }
    }
    return ss;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        takeinp(n);
        printf("%d\n",solve(n));
    }
    return 0;
}
