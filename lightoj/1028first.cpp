/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
//#include <dirent.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000
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

int sieve[1000005];
int allps[80000];

int sv(){
    int tot = 0;
    FREP(i,2,1000000){
        if(!sieve[i]){
            allps[++tot]=i;
            for(int j = (i+i); j<=1000000; j+=i){
                sieve[j] = 1;
            }
        }
    }
    return tot;
}

LLI cntbase(LLI n, int tt){
    if(n==1)return 1;
    if(n<=1000000 && sieve[n]==0)return 2; //commenting this does not give TLE either both from here and bottom
    LLI s = 1;
    int sss = (int)sqrt(n); //not using this? what happens? this gives TLE
    for(int i =1;i<=tt && allps[i]<=sss && n>1;++i){
        int cnt = 0;
        if(n<=1000000 && sieve[n]==0)return (s<<1);
        if(allps[i]>n)break; //commenting this does not give TLE
        while((n%allps[i])==0){
            cnt++;
            n/=allps[i];
        }

        s = s *(cnt+1);
    }
    if(n>1){
        s = s<<1;
    }
    return s;
}

template< class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int main(){
    int tt = sv();
    int t;
    scanf("%d",&t);
    FREP(cs,1,t){
        LLI n;
        read(n);
        LLI ans = cntbase(n,tt);
        printf("Case %d: %lld\n",cs,ans-1);
    }
    return 0;
}