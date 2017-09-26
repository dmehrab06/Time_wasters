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

ifstream fin("I.IN");

vector < vector <PII> >g;
vector < vector <PII> > childinfo;
VI maxchild;
VI maxchild2;
VI maxfinal;

void init(int n){
    g.clear();
    childinfo.clear();
    FREP(i,1,(n+3)){
        vector<PII>line;
        g.PB(line); childinfo.PB(line);
        maxchild.PB(-1);
        maxchild2.PB(-1);
        maxfinal.PB(-1);
    }
}

void takeinp(int n){
    FREP(i,1,(n-1)){
        int u,v,w;
        fin>>u>>v>>w;
        g[u].PB(make_pair(v,w));
        g[v].PB(make_pair(u,w));
    }
}

void dfs1(int cur, int par){ //find maxdis in subtree
    int deg = g[cur].size();
    int curmax = 0;
    FREP(i,0,(deg-1)){
        int v = g[cur][i].first; int ww = g[cur][i].second;
        if(v==par)continue;
        dfs1(v,cur);
        curmax = max(curmax,ww+maxchild[v]);
        childinfo[cur].PB(make_pair(ww+maxchild[v],v));
    }
    SORTV(childinfo[cur]);
    maxchild[cur] = curmax;
    return;
}

void dfs2(int cur, int par, int edgefrompar){ //find maxdis in subtree
    if(par!=-1){
        int dd = childinfo[par].size();
        int nwval = 0;
        RFREP(i,dd-1,0){
            int v = childinfo[par][i].second;
            if(v==cur)continue;
            nwval = edgefrompar+childinfo[par][i].first;
            break;
            //maxchildfinal[cur]=max(maxchild[cur],thisdis);
        }
        childinfo[cur].PB(make_pair(nwval,par));
        SORTV(childinfo[cur]);
    }
    int deg = g[cur].size();
    FREP(i,0,(deg-1)){
        int v = g[cur][i].first; int ww = g[cur][i].second;
        if(v==par)continue;
        dfs2(v,cur,ww);
    }
    return;
}

int main(){
    int n;
    fin>>n;
    init(n);
    takeinp(n);
    dfs1(1,-1);
    /*FREP(i,1,n){
        printf("%d\n",maxchild[i]);
    }
    printf("\n");*/
    dfs2(1,-1,0);
    /*FREP(i,1,n){
        printf("%d\n",maxchild2[i]);
    }
    printf("\n");*/
    FREP(i,1,n){
        printf("%d\n",childinfo[i][childinfo[i].size()-1].first);
    }
    fin.close();
    return 0;
}
