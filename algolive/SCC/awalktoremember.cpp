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


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<VI>g;
vector<VI>rg;

int gvis[100005];
int rgvis[100005];

int member[100005];
int cmemb[100005];

stack<int>order;

void init(){
    g.clear(); rg.clear();
    MSET(gvis,0); MSET(rgvis,0);
    MSET(member,-1); MSET(cmemb,0);
}

void dfs1(int c){
    gvis[c]=1;
    FREP(i,0,g[c].size()-1){
        int v = g[c][i];
        if(!gvis[v]){
            dfs1(v);
        }
    }
    order.push(c);
}

void dfs2(int c, int num){
    rgvis[c]=1;
    member[c]=num;
    cmemb[num]++;
    FREP(i,0,rg[c].size()-1){
        int v = rg[c][i];
        if(!rgvis[v]){
            dfs2(v,num);
        }
    }
}
void solve(int n){
    FREP(i,1,n){
        if(!gvis[i]){
            dfs1(i);
        }
    }
    int cc=1;
    while(!order.empty()){
        int tt = order.top();
        order.pop();
        if(!rgvis[tt]){
            dfs2(tt,cc);
            cc++;
        }
    }
    FREP(i,1,n){
        int pp = member[i];
        if(cmemb[pp]>1){
            printf("1 ");
        }
        else{
            printf("0 ");
        }
    }
    printf("\n");
}

void takeg(int n, int m){
    VI line;
    FREP(i,1,(n+3)){g.PB(line);rg.PB(line);}
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].PB(v);
        rg[v].PB(u);
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    init();
    takeg(n,m);
    solve(n);
    return 0;
}
