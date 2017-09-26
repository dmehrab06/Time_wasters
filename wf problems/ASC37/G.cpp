/*-------property of the half blood prince-----*/
//dmehrab06
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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI ans[200005];
int query[200005];
LLI tmp[200005];

ifstream fin("queue.in");
ofstream fout("queue.out");

vector< vector< pair<int,LLI> > >g;

void takeg(int n){
    g.clear();
    vector<pair<int,LLI>>line;
    FREP(i,1,(n+4))g.PB(line);
    FREP(i,1,n){
        int type;
        fin>>type;
        if(type==1){
            int v,val;
            fin>>v>>val;
            g[v].PB(make_pair(i,val));
        }
        else{
            int v;
            fin>>v;
            g[v].PB(make_pair(i,-10000000000));
            query[i]=1;
        }
    }
}

void dfs(int cur, int popcount, int pushcount, int needans){
    if(needans==1){
        ans[cur]=tmp[popcount];
    }
    int l=g[cur].size();
    FREP(i,0,(l-1)){
        int nxt=g[cur][i].first;
        LLI nxtval=g[cur][i].second;
        if(nxtval<(-8000000000)){
            //porer tay pop lagbe
            dfs(nxt,popcount+1,pushcount,1);
        }
        else{
            tmp[pushcount+1]=nxtval;
            dfs(nxt,popcount,pushcount+1,0);
        }
    }
}

int main(){
    int n;
    fin>>n;
    takeg(n);
    dfs(0,0,0,0);
    FREP(i,1,n){
        if(query[i]==1){
            fout<<ans[i]<<"\n";
        }
    }
    fin.close();
    fout.close();
}
