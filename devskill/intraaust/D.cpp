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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int representative[100005];

vector< pair<int,PII> >edges;

void init(){
    FREP(i,1,100004){
        representative[i]=i;
    }
    edges.clear();
}

int findrep(int a){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        init();
        int n,m;
        scanf("%d %d",&n,&m);
        FREP(i,1,m){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            pair<int,PII> myedg=make_pair(w,make_pair(u,v));
            edges.PB(myedg);
        }
        sort(edges.begin(),edges.end());
        reverse(edges.begin(),edges.end());
        LLI s = 0;
        FREP(i,0,(m-1)){
            pair<int,PII>curedg=edges[i];
            int u = curedg.second.first;
            int v = curedg.second.second;
            int pu=findrep(u);
            int pv=findrep(v);
            if(pu==pv){
                continue;
            }
            unionfind(u,v);
            s+=curedg.first;
        }
        printf("Case %d: %d %lld\n",cs,n-1,s);
    }
    return 0;
}
