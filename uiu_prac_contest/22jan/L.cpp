/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
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
//using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

map<string,int>drinkmap;
set<PII>indegs;
vector<VI>Gph;

int mapidx = 0;
int curdeg[30005];

void init(int n){
    drinkmap.clear();
    MSET(curdeg,0);
    indegs.clear();
    mapidx = 0;
    Gph.clear();
    FREP(i,1,n+3){
        VI line;
        Gph.PB(line);
    }
}

int getdi(string name){
    int di;
    if(drinkmap.find(name)==drinkmap.end()){
        drinkmap[name]=(++mapidx);
        di = mapidx;
    }
    else di = drinkmap[name];
    return di;
}

void takeinp(int m){
    string d1, d2;
    FREP(i,1,m){
        cin>>d1>>d2;
        int d1i, d2i;
        d1i = getdi(d1); d2i = getdi(d2);
        curdeg[d2i]++;
        Gph[d1i].PB(d2i);
    }
    FREP(i,1,mapidx){
        indegs.insert(make_pair(curdeg[i],i));
    }
}

bool topo(){
    while(!indegs.empty()){
        PII tp = *(indegs.begin());
        indegs.erase(tp);
        if(tp.first!=0)return false;
        int u = tp.second;
        FREP(i,0,Gph[u].size()-1){
            int v = Gph[u][i];
            int cur = curdeg[v];
            PII tofind = make_pair(cur,v);
            indegs.erase(tofind);
            curdeg[v]--;
            indegs.insert(make_pair(curdeg[v],v));
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        int m;
        scanf("%d",&m);
        init((3*m));
        takeinp(m);
        printf("Case %d: ",cs);
        if(topo())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
