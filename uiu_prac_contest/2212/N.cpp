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

int smallestp[1000005];
int diffp[1000005];

int prefsum[12][1000005];

void sieve(){
    MSET(smallestp,-1);
    for(int i = 2;i<=1000004;++i){
        if(smallestp[i]==-1){
            smallestp[i] = i;
            for(int j = (i+i); j <= 1000004; j+=i){
                if(smallestp[j]==-1){
                    smallestp[j] = i;
                }
            }
        }
    }
}

void setdistinct(int val){
    int temp = val;
    int cc = 0;
    while(temp>1){
        cc++;
        int sp = smallestp[temp];
        while(temp%sp==0){
            temp/=sp;
        }
    }
    diffp[val] = cc;
}

void precalc(){
    sieve();
    diffp[1] = 0;
    FREP(i,2,1000004)setdistinct(i);
    FREP(i,0,10){
        prefsum[i][0]=0;
        FREP(k,1,1000004){
            if(diffp[k]==i){
                prefsum[i][k]=1;
            }
            else{
                prefsum[i][k] = 0;
            }
            prefsum[i][k]+=prefsum[i][k-1];
        }
    }
}

int solve(int a, int b, int n){
    return prefsum[n][b]-prefsum[n][a-1];
}

int main(){
    precalc();
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        printf("%d\n",solve(a,b,n));
    }
    return 0;
}
