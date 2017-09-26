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

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<VI>edg;

vector< pair<PII,int> >circle;

int vis[205];

void takeg(int n){
    VI line;
    FREP(i,1,(n+5))edg.PB(line);
    FREP(i,0,(n-1)){
        FREP(j,0,(n-1)){
            if(i==j)continue;
            int jx=circle[j].first.first;
            int jy=circle[j].first.second;
            int ix=circle[i].first.first;
            int iy=circle[i].first.second;
            int ir=circle[i].second;
            int jr=(jx-ix)*(jx-ix)+(jy-iy)*(jy-iy);
            if(jr<=(ir*ir)){
                edg[i].PB(j);
                //edg[j].PB(i);
            }
        }
    }
}

int dfs(int cur){
    int sz=1;
    vis[cur]=1;
    int l=edg[cur].size();
    FREP(i,0,(l-1)){
        int v=edg[cur][i];
        if(!vis[v]){
            sz+=dfs(v);
        }
    }
    return sz;
}

ifstream fin("moocast.in");
ofstream fout("moocast.out");

int main(){
    int n;
    fin>>n;
    FREP(i,1,n){
        int x,y,r;
        fin>>x>>y>>r;
        pair<PII,int> meh=make_pair(make_pair(x,y),r);
        circle.PB(meh);
    }
    int mxx=0;
    takeg(n);
    FREP(i,0,(n-1)){
        memset(vis,0,sizeof(vis));
        int cmp=dfs(i);
        if(cmp>mxx)mxx=cmp;
    }
    fout<<mxx<<"\n";
    fin.close();
    fout.close();
    return 0;
}
