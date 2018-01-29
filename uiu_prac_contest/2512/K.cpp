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

int rep[1003];

PII citycoord[1003];

vector < pair<int,PII> >edg;

vector < vector <int> >subnetworks;

void makeedg(int n){
    edg.clear();
    FREP(i,1,n){
        scanf("%d %d",&citycoord[i].first,&citycoord[i].second);
    }
    FREP(i,1,n){
        FREP(j,(i+1),n){
            int dis1 = (citycoord[i].first-citycoord[j].first);
            int dis2 = (citycoord[i].second-citycoord[j].second);
            edg.PB(make_pair(((dis1*dis1)+(dis2*dis2)),make_pair(i,j)));
        }
    }
    SORTV(edg);
}

void takesubs(int subnets){
    subnetworks.clear();
    vector<int>line;
    FREP(i,1,(subnets+4)){
        subnetworks.PB(line);
    }
    FREP(i,0,subnets-1){
        int here,cost;
        scanf("%d %d",&here,&cost);
        subnetworks[i].PB(cost);
        FREP(j,1,here){
            int a;
            scanf("%d",&a);
            subnetworks[i].PB(a);
        }
    }
}

int processmask(int mask, int subnets, int n){
    LLI totcost = 0;
    int cur = 1;
    int curcomponent = n;
    FREP(i,1,n){
        rep[i] = i;
    }
    FREP(i,1,subnets){
        if(mask&cur){
            //subnet is here
            totcost+=subnetworks[i-1][0];
            FREP(j,2,subnetworks[i-1].size()-1){
                int v = subnetworks[i-1][j];
                int u = subnetworks[i-1][1];
                if(findrep(v)!=findrep(u)){
                    unionfind(u,v);
                    curcomponent--;
                }
            }
        }
        cur<<=1;
    }
    int edgit = 0;
    while(curcomponent>1){
        pair<int,PII> curedg = edg[edgit];
        int w = curedg.first;
        int u = curedg.second.first; int v = curedg.second.second;
        if(findrep(u)!=findrep(v)){
            totcost+=w;
            unionfind(u,v);
            curcomponent--;
        }
        curedg++;
    }
    return totcost;
}

int

int findrep(int n){
    if(rep[n]==n){
        return rep[n];
    }
    return rep[n]=findrep(rep[n]);
}

void unionfind(int x, int y){
    int px = findrep(x);
    int py = findrep(y);
    if(px!=py)rep[py]=px;
}

void kruskal(int n, int m){
    int it = 0;
    while((it<m)){
        pair<int,PII>curedg = edg[it];
        int u = curedg.second.first;
        int v = curedg.second.second;
        int w = curedg.first;
        if(findrep(u)!=findrep(v)){
            mstgraph[u].PB(make_pair(v,w));
            mstgraph[v].PB(make_pair(u,w));
            //cout<<"taking edge "<<u<<","<<v<<"\n";
            unionfind(u,v);
        }
        it++;
    }
}

int curans;

void dfs(int cur, int par, int dest,  int curdis){
    if(cur==dest){
        curans = curdis;
        return;
    }
    for(int i = 0; i<mstgraph[cur].size(); ++i){
        int v = mstgraph[cur][i].first;
        int w = mstgraph[cur][i].second;
        if(v==par)continue;
        dfs(v,cur,dest,max(curdis,w));
    }
}

int main(){
    int n,m,q;
    int cs = 1;
    while(scanf("%d %d %d",&n,&m,&q)==3){
        if(n==0 && m==0 && q==0)break;
        takeinp(n,m);
        kruskal(n,m);
        if(cs>1)printf("\n");
        printf("Case #%d\n",cs++);
        FREP(i,1,q){
            int src,dest;
            scanf("%d %d",&src,&dest);
            curans = -1;
            dfs(src,-1,dest,-1);
            if(curans==-1)printf("no path\n");
            else printf("%d\n",curans);
        }
    }
    return 0;
}
