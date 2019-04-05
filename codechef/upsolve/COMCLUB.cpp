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
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


//typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector < vector <LLI> > dp;
int clublevels[500005];
int clubmem[500005];
int memlevel[500005];
LLI ans[500005];
vector < vector <int> >g;

void init(){
    dp.clear();
    g.clear();
    MSET(clublevels,0);
    MSET(ans,0);
}

void takeg(int n){
    VI line;
    FREP(i,1,(n+3))g.PB(line);

    FREP(i,1,n-1){
        int p;
        scanf("%d",&p);
        g[p].PB(i);
        g[i].PB(p);
    }
}

void initdp(int n){
    FREP(i,0,n){
        int sz = clublevels[i];
        vector<LLI> line; dp.PB(line);
        FREP(j,0,sz+3){
            dp[i].PB(0);
        }
    }
}

//dp[color][level]

void dfs(int cur, int par){
    int curclub = clubmem[cur];
    int curlev = memlevel[cur];

    //error(cur,curclub,curlev);

    LLI before = (curlev>0 && curlev<clublevels[curclub])?dp[curclub][curlev-1]:0;

    //error(before);

    FREP(i,0,g[cur].size()-1){
        int v = g[cur][i];
        if(v==par)continue;
        //error(v);
        dfs(v,cur);
        //dp[curclub][curlev] += dp[curclub][curlev-1]
    }

    if(curlev==0){
        dp[curclub][curlev]+=1;
        dp[curclub][curlev]%=MDD;
        ans[cur] = 1;
    }
    else if(curlev>=clublevels[curclub]){
        ans[cur] = 0;
    }
    else{
        LLI curans = (dp[curclub][curlev-1] - before);

        if(curans<0)curans+=MDD;
        curans%=MDD;
        dp[curclub][curlev]+=curans;
        dp[curclub][curlev]%=MDD;
        ans[cur] = curans;
    }

}

int main(){
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        init();
        int n,x;
        scanf("%d %d",&n,&x);
        takeg(n);

        int mxc = -1;

        FREP(i,0,n-1)scanf("%d",&clubmem[i]);
        FREP(i,0,(n-1))scanf("%d",&memlevel[i]);

        FREP(i,0,(n-1))clublevels[clubmem[i]]++;

        FREP(i,0,(n-1))mxc = max(mxc,clubmem[i]);

        initdp(mxc);

        /*FREP(club,0,mxc){
            error(club,dp[club].size());
            printf("\n");
        }*/

        dfs(0,-1);

        FREP(i,0,(n-1)){
            printf("%lld\n",ans[i]);
        }

    }
    return 0;
}
