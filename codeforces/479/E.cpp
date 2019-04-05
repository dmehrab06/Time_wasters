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

int rep[200005];

vector< vector <int> >g;

vector < vector <int> >comps;

int findrep(int n){
    if(rep[n]==n)return rep[n];
    else return rep[n] = findrep(rep[n]);
}

void uni(int u, int v){
    int pu = findrep(u); int pv = findrep(v);
    if(pu!=pv){
        rep[pu]=pv;
        //cout<<"uniting "<<u<<" and "<<v<<"\n";
    }
}

void init(int n, int m){
    FREP(i,1,(n+3)){
        VI line;
        g.PB(line);
        comps.PB(line);
        rep[i] = i;
    }
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v); g[v].PB(u);
        uni(u,v);
    }
}

void getcomp(int n){
    FREP(i,1,n){
        int rr = findrep(i);
        //cout<<i<<" "<<rr<<"\n";
        comps[rr].PB(i);
    }
}

bool dfs(int cur, int par, int st){
    if(g[cur].size()!=2)return false;
    FREP(i,0,g[cur].size()-1){
        int v = g[cur][i];
        if(v==par)continue;
        else if(v==st)return true;
        else return dfs(v,cur,st);
    }
    return false;
}

int solve(int n){
    int ans = 0;
    FREP(i,1,n){
        if(comps[i].size()>2){
            //cout<<" comp i "<<i<<"\n";
            //FREP(j,0,comps[i].size()-1)cout<<comps[i][j]<<" ";
            //cout<<"\n";
            if(dfs(comps[i][0],-1,comps[i][0]))ans++;
        }
    }
    return ans;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init(n,m);
    getcomp(n);
    printf("%d\n",solve(n));
    return 0;
}
