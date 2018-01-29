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

LLI dp[12][100003]; //dp[g][l] = min risk using g guards for first l prisoners
int leaves[100003];
LLI cumsum1[100003];
int cumsum2[100003];

LLI cost(int l, int r){
    if(l>r)return 0;
    LLI ans1 = cumsum1[r]-cumsum1[l-1]; //al*l+al+1*(l+1) etc
    LLI ans2 = (LLI)l*(cumsum2[r]-cumsum2[l-1]);
    //cout<<"cost for "<<l<<" to "<<r<<" is "<<ans1-ans2<<"\n";
    return ans1-ans2;
}

void precalc(int n){
    FREP(i,1,n){
        cumsum1[i] = leaves[i]*i;
        cumsum1[i] = cumsum1[i-1]+cumsum1[i];
    }
    FREP(i,1,n){
        cumsum2[i] = leaves[i];
        cumsum2[i] = cumsum2[i-1]+cumsum2[i];
    }
}

void div_conq(int g, int l, int r, int ans1, int ans2){
    //finding dp[g][(l+r)/2] when i know that dp_partition lies between ans1 and ans2
    if(l>r)return;

    int mid = l+(r-l)/2;
    dp[g][mid] = 100000000000000000;

    int partk = -1;

    FREP(k,ans1,min(ans2,mid)){
        LLI val = dp[g-1][k]+cost(k+1,mid);
        if(val<dp[g][mid]){
            dp[g][mid] = val;
            partk = k;
        }
    }

    div_conq(g,l,mid-1,ans1,partk);
    div_conq(g,mid+1,r,partk,ans2);
}

void solve(int gg, int n){
    FREP(i,0,n)dp[1][i] = cost(1,i);
    FREP(g,2,gg)div_conq(g,1,n,1,n);
}

int main(){

    int L,G;
    scanf("%d %d",&L,&G);
    FREP(i,1,L)scanf("%d",&leaves[i]);
    precalc(L);
    solve(G,L);
    printf("%lld\n",dp[G][L]);
    /*FREP(g,1,G){
        FREP(l,1,L){
            printf("dp_partition[%d][%d] = %d ",g,l,dp_partition[g][l]);
        }
        printf("\n");
    }*/
    return 0;
}
