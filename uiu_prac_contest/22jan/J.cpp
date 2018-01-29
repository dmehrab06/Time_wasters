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

int rep[500005];
LLI regionpop[500005];
PII edgidx[500005];
bool enabled[500005];

pair<int,PII> queries[500005];
LLI queryans[500005];
set< pair<LLI,int> >populset;
vector< VI > populationtrack;
vector< int > populationtrackit;

void init(int n, int m){
    VI line;
    FREP(i,1,(n+3)){populationtrack.PB(line);populationtrackit.PB(0);}
    FREP(i,1,n)rep[i]=i;
    FREP(i,1,n){
        scanf("%lld",&regionpop[i]);
        populationtrack[i].PB(regionpop[i]);
    }
    FREP(i,1,m){
        scanf("%d %d",&edgidx[i].first, &edgidx[i].second);
        enabled[i] = true;
    }
}

int findrep(int x){
    if(rep[x]==x)return x;
    return rep[x]=findrep(rep[x]);
}

void unionfind(int x, int y){
    //cout<<"trying to unite "<<x<<" and "<<y<<"\n";
    int px = findrep(x); //cout<<"parent of x "<<px<<"\n";
    int py = findrep(y); //cout<<"parent of y "<<py<<"\n";
    if(px!=py){
        rep[py]=px;
        pair<LLI,int>tofind = make_pair(-regionpop[px],px);
        pair<LLI,int>tofind2 = make_pair(-regionpop[py],py);
        if(populset.find(tofind)!=populset.end())populset.erase(tofind);
        if(populset.find(tofind2)!=populset.end())populset.erase(tofind2);
        regionpop[px]+=regionpop[py];
        populset.insert(make_pair(-regionpop[px],px));
    }
}

void processfront(int q,int n, int m){
    char comm[3];
    FREP(i,1,q){
        scanf("%s",comm);
        if(comm[0]=='D'){
            //road disable
            int roadidx;
            scanf("%d",&roadidx);
            enabled[roadidx] = false;
            queries[i] = make_pair(0,make_pair(edgidx[roadidx].first,edgidx[roadidx].second));
        }
        else{
            //population change
            int city; LLI newpop;
            scanf("%d %lld",&city,&newpop);
            populationtrack[city].PB(newpop);
            populationtrackit[city]++;
            regionpop[city] = newpop;
            queries[i] = make_pair(1,make_pair(city,(int)newpop));
        }
    }
    FREP(i,1,n){
        populset.insert(make_pair(-regionpop[i],i));
    }
    FREP(i,1,m){
        if(enabled[i]){
            int u = edgidx[i].first;
            int v = edgidx[i].second;
            unionfind(u,v);
        }
    }
}

void processback(int q,int n, int m){
    RFREP(i,q,1){
        /*cout<<"after query "<<i<<"\n";
        set< pair<LLI,int> >:: iterator it;
        cout<<"set contains the followings: \n";
        for(it = populset.begin();it!=populset.end();++it){
            pair<LLI,int> kk = *it;
            cout<<-kk.first<<" "<<kk.second<<"\n";
        }*/
        queryans[i] = (*(populset.begin())).first;
        if(queries[i].first==0){ //eitar effect k cancel korte hobe
            //road disable
            int u = queries[i].second.first;
            int v = queries[i].second.second;
            unionfind(u,v);
        }
        else{
            //population change //eitar effect k cancel korte hobe
            int city = queries[i].second.first;
            int curit = populationtrackit[city];
            LLI curpop = populationtrack[city][curit];
            LLI prevpop = populationtrack[city][curit-1];
            populationtrackit[city]--;
            LLI chng = (prevpop-curpop);
            int currep = findrep(city);
            LLI curpopregion = regionpop[currep];
            pair<LLI,int>tofind = make_pair(-curpopregion,currep);
            if(populset.find(tofind)!=populset.end())populset.erase(populset.find(tofind));
            regionpop[currep]+=chng;
            populset.insert(make_pair(-regionpop[currep],currep));
        }
    }
}

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    init(n,m);
    processfront(q,n,m);
    processback(q,n,m);
    FREP(i,1,q){
        printf("%lld\n",-queryans[i]);
    }
    return 0;
}
