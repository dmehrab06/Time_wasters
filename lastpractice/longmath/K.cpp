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

int allps[1000005];

int primes[1000005];
int smallest[1000005];
int lastprime[1000005];

int totprime=0;

int vis[1000005];
double dp[1000005];

void sieve(){
    memset(vis,-1,sizeof(vis));
    FREP(i,2,1000004){
        if(primes[i]==0){
            allps[++totprime]=i;
            smallest[i]=i;
            for(int j=(i+i);j<=1000004;j+=i){
                primes[j]=1;
                if(smallest[j]==0){
                    smallest[j]=i;
                }
            }
        }
        lastprime[i]=totprime;
    }
}

double solve(int x){
    //cout<<"in "<<x<<"\n";
    if(x==1)return 0.0;
    if(vis[x]!=-1)return dp[x];
    int a = lastprime[x];
    int b = 0;
    int tmp = x;
    vector<int>alldiv;
    while(tmp>1){
        int div = smallest[tmp];
        alldiv.PB(div);
        b++;
        while(tmp%div==0){
            tmp/=div;
        }
    }
    double s = 0.0;
    FREP(i,0,alldiv.size()-1){
        s+=(1.0/(double)a)*(1.0+solve(x/alldiv[i]));
    }
    s+=((double)(a-b)/(double)a);
    s=s*(double)a;
    s=s/(double)b;
    vis[x]=1;
    return dp[x]=s;
}

int main(){
    sieve();
    //FREP(i,1,1000000){
      //  solve(i);
        //cout<<i<<" done\n";
    //}
    //cout<<"done\n";
    int t;
    scanf("%d",&t);
    int cs = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",cs++,solve(n));
    }
    return 0;
}
