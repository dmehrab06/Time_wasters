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
#define FREP(i,I,N) for(int (i)=(int)(I);(i)<=(int)(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(int)(N);(i)>=(int)(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
#define INRANGED(val,l,r) (((l)<(val) || fabs((val)-(l))<eps) && ((val)<(r) || fabs((val)-(r))<eps))
#define MDD 1000000007
#define ll long long
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI cntdp[3003][3003];

void calc(){
    cntdp[1][0]=1;
    cntdp[1][1]=0;
    FREP(i,1,3001){
        FREP(j,0,i){
            int tot1=j*2+2;
            int tot2=(i+1)-tot1;
            LLI cnt1=tot1*cntdp[i][j];
            LLI cnt2=tot2*cntdp[i][j];
            cnt1%=MDD;
            cnt2%=MDD;
            cntdp[i+1][j]+=cnt1; cntdp[i+1][j]%=MDD;
            cntdp[i+1][j+1]+=cnt2; cntdp[i+1][j+1]%=MDD;
        }
    }
}

void dekhi(){
    FREP(i,1,12){
        FREP(j,0,i){
            printf("%10lld",cntdp[i][j]);
        }
        printf("\n");
    }
}

void cum(){
    FREP(i,1,3001){
        FREP(j,1,i){
            cntdp[i][j]+=cntdp[i][j-1];
            cntdp[i][j]%=MDD;
        }
    }
}


int main(){
    calc();
    cum();
    //dekhi();
    int q;
    scanf("%d",&q);
    FREP(i,1,q){
        int n,k;
        scanf("%d %d",&n,&k);
        int col=max(0,(n-1-k));
        LLI ans=cntdp[n][col];
        if(n==k)ans=0;
        printf("%lld\n",ans);
    }
}
