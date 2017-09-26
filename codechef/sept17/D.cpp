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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector< vector <PII> > g;
set< pair<PII,int> >edges;

vector<int>dis; vector<int>vis;

void fillmatrix(){
    set< pair<PII,int> >::iterator it;
    for(it = edges.begin(); it!=edges.end(); ++it){
        pair<PII,int>e = *it;
        int u = e.first.first; int v = e.first.second;
        int w = e.second;
        g[u].PB(make_pair(v,w));
        g[v].PB(make_pair(u,w));
    }
}

void init(int n){
    g.clear();edges.clear();dis.clear();vis.clear();
    FREP(i,1,n+4){
        vector <PII> line;
        g.PB(line);
        dis.PB(0); vis.PB(0);
    }
}

void dfs(int src, int lev){
    dis[src]=lev;
    vis[src]=1;
    int l = g[src].size();
    FREP(i,0,(l-1)){
        int v = g[src][i].first;
        int w = g[src][i].second;
        if(!vis[v]){
            pair<PII,int>edg = make_pair(make_pair(min(src,v),max(src,v)),w);
            //cout<<edg.first.first<<" "<<edg.first.second<<"\n";
            if(edges.find(edg)!=edges.end()){
                edges.erase(edg);
            }
            else{
                printf("dhongsho hoye gesi\n");
            }
            edg.second = 2;
            edges.insert(edg);
            dfs(v,(lev+w)&1);
        }
    }
}

bool still_valid(){
    set< pair<PII,int> >:: iterator it;
    for(it = edges.begin(); it!=edges.end(); ++it){
        pair<PII,int> e = *it;
        if(e.second==2)continue;
        else{
            //cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<"\n";
            int ulev = dis[e.first.first];
            int vlev = dis[e.first.second];
            int w = e.second;
            int thisval = (ulev+vlev)%2;
            if(thisval!=w)return false;
        }
    }
    return true;
}

void go(int n){
    FREP(i,1,n){
        if(!vis[i]){
            dfs(i,0);
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        int flg  = 1;
        init(n);
        FREP(i,1,q){
            int u,v,val;
            scanf("%d %d %d",&u,&v,&val);
            if(u==v){
                if(val){
                    flg = 0;
                }
                continue;
            }
            if(u>v)swap(u,v);
            pair<PII,int> notdesire = make_pair(make_pair(u,v),1-val);
            pair<PII,int> edg = make_pair(make_pair(u,v),val);
            if(edges.find(notdesire)!=edges.end()){
                flg = 0;
            }
            edges.insert(edg);
        }
        if(!flg)printf("no\n");
        else{
            fillmatrix();
            go(n);
            if(still_valid()){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
}
