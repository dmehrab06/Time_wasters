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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define NIL -1
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < vector <int> >g;


bool apvisited[10004];
int apdisc[10004];
int aplow[10004];
int apparent[10004];
bool ap[10004];
int cost[10004];
int deg[10004];
vector<PII>costforalgo4;
vector<int>shufflevector;
vector<int>cutvertices;

int randomiteration = 1000;

void takeinput(int n, int m){
    VI line;
    FREP(i,1,(n+4))g.PB(line);
    FREP(i,1,n){scanf("%d",&cost[i]);costforalgo4.PB(make_pair(cost[i],i));}
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v); g[v].PB(u);
        deg[u]++; deg[v]++;
    }
}

bool dfs_algo1(int p, int cur, int msk, int *vis){
    vis[cur]=1;
    int ll=g[cur].size();
    bool ret = true;
    FREP(i,0,(ll-1)){
        int v = g[cur][i];
        if(v==p ||  !(msk & (1<<(v-1))))continue;
        if(vis[v]==1)return false;
        ret = ret & dfs_algo1(cur,v,msk,vis);
    }
    return ret;
}

LLI istree_algo1(int n, int msk){
    int pres[21];
    int vis[21];
    int ff = -1;
    FREP(i,1,n){
        if(msk & (1<<(i-1))){
            pres[i]=1;
            if(ff==-1)ff=i;
        }
        else pres[i]=0;

        vis[i]=0;
    }
    bool chk = dfs_algo1(-1,ff,msk,vis);
    if(chk){
        LLI ss=0;
        FREP(i,1,n){
            if(vis[i]!=pres[i])return (LLI)10000000000000;
            if(pres[i]==0)ss+=cost[i];
        }
        return ss;
    }
    return (LLI)10000000000000;
}

bool dfs_others(int p, int cur, vector<int>& presents, vector<int>& visited){
    visited[cur]=1;
    int ll=g[cur].size();
    bool ret = true;
    FREP(i,0,(ll-1)){
        int v = g[cur][i];
        if(v==p ||  !presents[v])continue;
        if(visited[v]==1)return false;
        ret = ret & dfs_others(cur,v,presents,visited);
    }
    return ret;
}

LLI istree_others(int n, vector<int>& thakbe){
    vector<int>pres;
    vector<int>vis;
    FREP(i,1,(n+3)){pres.PB(0);vis.PB(0);}
    int ll = thakbe.size(); int ll2=cutvertices.size();
    FREP(i,1,ll)pres[thakbe[i-1]]=1;
    FREP(i,1,ll2-1)pres[cutvertices[i-1]]=1;
    bool chk = dfs_others(-1,thakbe[0],pres,vis);
    if(chk){
        LLI ss=0;
        FREP(i,1,n){
            if(vis[i]!=pres[i])return (LLI)10000000000000;
            if(pres[i]==0)ss+=cost[i];
        }
        return ss;
    }
    return (LLI)10000000000000;
}

void solve_algo1(int n){
    int highest_mask=(1<<n)-1;
    LLI mincost = 10000000000000; int minmask = -1;
    FREP(m,1,highest_mask){
        LLI cst=istree_algo1(n,m);
        if(cst<mincost){
            mincost=cst; minmask=m;
        }
    }
    vector<int>vcs;
    FREP(i,0,(n-1))if( !(minmask & (1<<i)) )vcs.PB(i+1);
    printf("%d\n",(int)vcs.size());
    FREP(i,0,(vcs.size()-1)) printf("%d ",vcs[i]);
    printf("\n");
}

bool isdataset4(int n){
    FREP(i,1,n){
        if(deg[i]!=(n-1))return false;
    }
    return true;
}

void solve_algo4(int n){
    SORTV(costforalgo4);
    REVV(costforalgo4);
    if(n<=2)printf("0\n");
    else{
        printf("%d\n",n-2);
        FREP(i,2,(n-1))printf("%d ",costforalgo4[i].second);
        printf("\n");
    }
}

void solve_others(int n){
    srand(time(0));
    FREP(i,1,n)if(!ap[i])shufflevector.PB(i);
    int shufflen=shufflevector.size();
    LLI mincost = 10000000000000;
    vector<int>minstrategy;
    FREP(i,1,randomiteration){
        random_shuffle(shufflevector.begin(),shufflevector.end());
        //cout<<"shufflevector: ";
        /*FREP(k,0,(n-1)){
            printf("%d ",shufflevector[k]);
        }*/
        //printf("\n");
        int take = (shufflen/2)+rand()%(shufflen/2)+1;
        //cout<<take<<"\n";
        vector<int>thakbe;
        //cout<<"thakbe: ";
        FREP(k,1,take){
            thakbe.PB(shufflevector[k-1]);
        }
        /*FREP(k,1,take){
            printf("%d ",thakbe[k-1]);
        }*/
        //printf("\n");
        //cout<<"thakbe te dhukse\n";
        LLI cst = istree_others(n,thakbe);
        //cout<<"dfs cholse\n";
        if(cst<mincost){
            minstrategy.clear();
            FREP(k,(take+1),shufflen){
                minstrategy.PB(shufflevector[k-1]);
            }
            mincost=cst;
        }
    }
    if(minstrategy.size()==0){
        printf("%d\n",n-2);
        SORTV(costforalgo4); REVV(costforalgo4);
        int u = costforalgo4[0].second;
        int ll = g[u].size();
        int mx=0;
        int v = -1;
        FREP(i,0,(ll-1)){
            if(cost[g[u][i]]>mx){
                mx=cost[g[u][i]];
                v=g[u][i];
            }
        }
        FREP(i,1,(n-1))if(costforalgo4[i].second!=v)printf("%d ",costforalgo4[i].second);
        printf("\n");
    }
    else{
        int ll=minstrategy.size();
        printf("%d\n",ll);
        FREP(i,0,(ll-1)){
            printf("%d ",minstrategy[i]);
        }
        printf("\n");
    }
}

void APUtil(int u){
    static int time = 0;
    int children = 0;
    apvisited[u] = true;
    apdisc[u] = aplow[u] = ++time;
    int ll = g[u].size();
    FREP(i,0,(ll-1)){
        int v = g[u][i];
        if (!apvisited[v]){
            children++;
            apparent[v] = u;
            APUtil(v);
            aplow[u]  = min(aplow[u], aplow[v]);
            if (apparent[u] == NIL && children > 1)
               ap[u] = true;
            if (apparent[u]!= NIL && aplow[v] >= apdisc[u])
               ap[u] = true;
        }
        else if (v != apparent[u])
            aplow[u] = min(aplow[u], apdisc[v]);
    }
}

void AP(int V)
{
    FREP(i,1,V){
        apparent[i] = NIL; apvisited[i] = false; ap[i] = false;
    }
    FREP(i,1,V)
        if (apvisited[i] == false)
            APUtil(i);
    FREP(i,1,V){
        if(ap[i])cutvertices.PB(i);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    takeinput(n,m);
    if(n<=2){
        printf("0\n");
    }
    else if(n<=20){
        solve_algo1(n);
    }
    else{
        if(isdataset4(n)){
            solve_algo4(n);
        }
        else{
            randomiteration = (22000000)/n;
            AP(n);
            solve_others(n);
        }
    }
    //randomiteration = (1000000)/n;
    //solve_others(n);
    return 0;
}
