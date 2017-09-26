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
#define MODD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction



typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int attractive[100005][22];
int beauty[100005];
int nodelevel[100005];

int modlevel[22];

vector<VI>level;
vector<VI>g;

int phi(int n)
{
    int result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

LLI bigmod(int base, int exp, int mdd){
    if(exp==0){
        return (LLI)1;
    }
    if(exp==1){
        return (LLI)(base%mdd);
    }
    int exp2=exp/2;
    LLI ans=bigmod(base,exp2,mdd);
    if(exp%2){
        return (((ans*ans)%mdd)*base)%mdd;
    }
    else{
        return ((ans*ans)%mdd);
    }
}

void init(int n, int k){
    memset(attractive,-1,sizeof(attractive));
    level.clear();
    g.clear();
    VI line;
    //VI line2;
    FREP(i,1,(k+3)){
        level.PB(line);
    }
    FREP(i,1,(n+3)){
        g.PB(line);
    }
    modlevel[0]=MODD;
    FREP(i,1,20){
        modlevel[i]=phi(modlevel[i-1]);
    }
}

void takebeauty(int n){
    FREP(i,1,n){
        scanf("%d",&beauty[i]);
    }
}

void takelevel(int k){
    FREP(i,1,k){
        int ase;
        scanf("%d",&ase);
        level[i].PB(ase);
        FREP(j,1,ase){
            int idx;
            scanf("%d",&idx);
            level[i].PB(idx);
            nodelevel[idx]=i;
        }
    }
}

void takeg(int m){
    FREP(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        int ulevel=nodelevel[u];
        int vlevel=nodelevel[v];
        if(ulevel<vlevel){
            g[u].PB(v);
        }
        else{
            g[v].PB(u);
        }
    }
}

int solve(int cur, int level){
    int l=g[cur].size();
    if(l==0){
        return attractive[cur][level]=beauty[cur]%modlevel[level];
    }
    if(attractive[cur][level]!=-1)return attractive[cur][level];
    LLI s=0;
    FREP(i,0,(l-1)){
        int nxt=g[cur][i];
        int ret=solve(nxt,level+1);
        LLI oka=bigmod(beauty[cur],ret,modlevel[level]);
        s+=oka;
        s%=modlevel[level];
    }
    return attractive[cur][level]=(int)s;

}

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    init(n,k);
  //  cout<<"init hoise\n";
    takebeauty(n);
   // cout<<"beauty nisi\n";
    takelevel(k);
   // cout<<"level nisi\n";
    takeg(m);
   // cout<<"graph nisi\n";
   // cout<<"hoise\n";
    FREP(lvl,1,k){
        int ase=level[lvl][0];
        FREP(j,1,ase){
            int node=level[lvl][j];
            if(attractive[node][0]==-1){
                solve(node,0);
            }
        }
    }
  //  cout<<"sesh\n";
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int node;
        scanf("%d",&node);
        printf("%d\n",attractive[node][0]);
    }

    return 0;
}
