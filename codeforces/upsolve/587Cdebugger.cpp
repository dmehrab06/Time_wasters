/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

#define MXLOG 19
#define MAXN 100005

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int mxpeople = 20;

typedef VI peoplelist;

peoplelist _merge2(peoplelist a, peoplelist b){
    cout<<"merging...\n";
    FREP(i,0,(int)a.size()-(int)1)cout<<a[i]<<" ";
    cout<<"\nand\n";
    FREP(i,0,(int)b.size()-(int)1)cout<<b[i]<<" ";
    cout<<"\n";
    peoplelist aa = a;
    aa.insert(aa.end(),b.begin(),b.end());
    sort(aa.begin(), aa.end());
    aa.erase(unique(aa.begin(), aa.end()), aa.end());
    SORTV(aa);
    if((int)aa.size()>mxpeople)aa.resize(mxpeople);
    cout<<"merge result...\n";
    FREP(i,0,(int)aa.size()-(int)1)cout<<aa[i]<<" ";
    cout<<"\n";
    return aa;
}

void print(peoplelist pp, int tot){
    int mnn = min((int)pp.size(),tot);
    cout<<mnn;
    FREP(i,0,(mnn-1)){
        cout<<" "<<pp[i];
    }
    cout<<"\n";
}

peoplelist topar[MXLOG][MAXN];
int par[MXLOG][MAXN];
int height[MAXN];

vector< VI > adj;
vector< VI > peoples;

void takeinp(int n, int m){
    adj.clear(); peoples.clear();
    memset(par,-1,sizeof(par));
    FREP(i,1,max(n+3,m+3)){
        VI line;
        adj.PB(line);
        peoples.PB(line);
    }
    FREP(i,1,(n-1)){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].PB(v); adj[v].PB(u);
    }
    FREP(i,1,m){
        int city;
        scanf("%d",&city);
        peoples[city].PB(i);
    }
}

void dfs(int cur, int pp = -1){
    cout<<"at dfs for "<<cur<<"\n";
    if(pp+1){
        height[cur] = height[pp]+1;
    }
    par[0][cur] = cur;
    vector<int> myv = peoples[cur];
    topar[0][cur] = myv;
    //cout<<"0th level e par bosaisi\n";
    par[1][cur] = pp;
    if(pp+1)topar[1][cur] = _merge2(topar[0][cur],topar[0][pp]);
    //cout<<"1st level e par bosaisi\n";
    for(int i = 1; i<(MXLOG-1);++i){
        //cout<<"i: "<<i<<"\n";
        if((par[i][cur]+1) && (topar[i][par[i][cur]].size())>0){
            par[i+1][cur] = par[i][par[i][cur]];
            topar[i+1][cur] = _merge2(topar[i][cur],topar[i][par[i][cur]]);
        }
    }
    for(auto u: adj[cur]){
        if(u!=pp){
            dfs(u,cur);
        }
    }
}

void printpeople(int v){
    FREP(i,0,MXLOG-1){
        peoplelist his = topar[i][v];
        cout<<"printing info for vertex "<<v<<" for travelling his parent at distance 2^"<<i-1<<"\n";
        print(his,mxpeople);
        cout<<"level "<<i<<" done\n";
    }
}

peoplelist LCAmerge(int v,int u){
	if(height[v] < height[u])swap(v,u);

    //cout<<u<<","<<v<<"\n";

	peoplelist uset = topar[0][u];
	peoplelist vset = topar[0][v];

    //cout<<"vset now\n";
    //print(vset,mxpeople);
	RFREP(i,MXLOG-1,1){
        if((par[i][v]+1) && (height[par[i][v]]>=height[u])){
            vset = _merge2(vset,topar[i][v]);
            v = par[i][v];
            //cout<<"v now "<<v<<"\n";
            //cout<<"vset now\n";
            //print(vset,mxpeople);
        }
	}

	if(v == u) return _merge2(vset,uset);

	RFREP(i,MXLOG-1,1){
        if(par[i][v]-par[i][u]){
            vset = _merge2(vset,topar[i][v]); uset = _merge2(uset,topar[i][u]);
            v = par[i][v] ; u = par[i][u];
            /*cout<<"v now "<<v<<"\n";
            cout<<"vset now\n";
            print(vset,mxpeople);
            cout<<"u now "<<u<<"\n";
            cout<<"uset now\n";
            print(uset,mxpeople);*/
        }
	}
	vset = _merge2(vset,topar[1][v]); uset = _merge2(uset,topar[1][u]);
    return _merge2(vset,uset);
}

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    takeinp(n,m);
    dfs(1,-1);
    //cout<<"dfs done\n";

    FREP(i,1,n)printpeople(i);


    FREP(i,1,q){
        int u,v,k;
        scanf("%d %d %d",&u,&v,&k);
        peoplelist ans = LCAmerge(v,u);
        print(ans,k);
    }
    return 0;
}
