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

LLI curdis[103];

int rep[103];

vector < vector <PII> > g;

void initdis(int n){
    FREP(i,1,n)curdis[i] = 1000000000000;
}

void initgraph(int n){
    vector<PII>line;
    FREP(i,1,(n+3))g.PB(line);
    FREP(i,1,n)rep[i] = i;
}

int findrep(int n){
    if(rep[n]==n)return n;
    return rep[n]=findrep(rep[n]);
}

bool union_find(int u, int v){
    int pu = findrep(u);
    int pv = findrep(v);
    if(pu==pv){
        return true;
    }
    rep[pu] = pv;
    return false;
}

void addedge(int u, int v, int w){
    g[u].PB(make_pair(v,w));
    g[v].PB(make_pair(u,w));
    //cout<<"edge dilam\n";
    union_find(u,v);
    //cout<<"union korlam\n";
}

LLI dijkstra(int src, int dest, int n){
    set< pair<LLI,int> > pq;
    initdis(n);
    curdis[src] = 0;
    pq.insert(make_pair(0,src));
    while(true){
        pair<LLI,int> minnode = *(pq.begin());
        pq.erase(pq.begin());
        int v = minnode.second;
        //cout<<v<<" "<<curdis[v]<<"\n";
        if(v==dest){
            //cout<<"paisi\n";
            return curdis[v];
        }
        FREP(i,0,g[v].size()-1){
            int u = g[v][i].first;
            int w = g[v][i].second;
            LLI curudis = curdis[u];
            LLI disfromhere = curdis[v]+w;
            if(disfromhere<curudis){
                pq.insert(make_pair(disfromhere,u));
                curdis[u] = disfromhere;
            }
        }
    }
    return -1; //ekhane asar kotha na
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    initgraph(n);
    int f = 1;
    FREP(i,1,m){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        //printf("scan kortesi\n");
        if(f){
            if(findrep(u)!=findrep(v)){
                addedge(u,v,w);
            }
            else{
                LLI curmindis = dijkstra(u,v,n);
                if(w>curmindis){
                    //cout<<"hobe na\n";
                    f = 0;
                }
                else{
                    //cout<<"edge add kori\n";
                    addedge(u,v,w);
                }
            }
            //cout<<"clause sesh\n";
        }

    }
    if(f==0){
        printf("-1\n");
        return 0;
    }
    //cout<<"scan sesh\n";
    set<int>comps;
    FREP(i,1,n){
        comps.insert(findrep(i));
    }
    vector<int>compv;
    set<int>::iterator it;
    for(it = comps.begin(); it!=comps.end(); ++it){
        compv.PB(*it);
    }
    for(int i = 0; i< ((int)compv.size()-1) ; ++i ){
        addedge(compv[i],compv[i+1],1000);
    }
    set< pair < PII,int > >alledg;
    FREP(i,1,n){
        FREP(j,0,g[i].size()-1){
            int u = i;
            int v = g[i][j].first;
            int w = g[i][j].second;
            if(u>v)swap(u,v);
            alledg.insert(make_pair(make_pair(u,v),w));
        }
    }
    printf("%d\n",(int)alledg.size());
    set< pair < PII,int > >::iterator it2;
    for(it2 = alledg.begin(); it2!=alledg.end(); ++it2){
        pair< PII,int >eg = *it2;
        printf("%d %d %d\n",eg.first.first,eg.first.second,eg.second);
    }
    return 0;

}
