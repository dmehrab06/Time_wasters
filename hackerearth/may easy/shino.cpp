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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

typedef long long int ll;

// Utility function to find GCD of 'a' and 'b'

int dp[52][6][11][11][11][11][11];

int A[6];
int B[6];

int tot=0;

void init(){
    memset(dp,-1,sizeof(dp));
}

int solve(int cur, int previd, int prevdone, int firstleft, int secleft, int thirdleft, int frthleft){
    int ret=0;
    int ss=firstleft+secleft+thirdleft+frthleft;
    int fifthleft=(tot-cur+1)-ss;
    int arr[6]={0,firstleft,secleft,thirdleft,frthleft,fifthleft};
    int sss=0;
    FREP(i,1,5)sss+=arr[i];
    if(cur==tot){
        if(sss==1)return 1;
        else return 0;
    }
    if(dp[cur][previd][prevdone][firstleft][secleft][thirdleft][frthleft]!=-1){
        return dp[cur][previd][prevdone][firstleft][secleft][thirdleft][frthleft];
    }

    for(int i=1;i<=5;++i){
        if(i!=previd){
            if(arr[i]>0){
                arr[i]=arr[i]-1;
                int ret1=solve(cur+1,i,1,arr[1],arr[2],arr[3],arr[4]);
                arr[i]=arr[i]+1;
                LLI aa=(LLI)ret+(LLI)ret1;
                aa%=1000000007;
                ret=aa;
            }
        }
        else{
            if(B[i]>prevdone && arr[i]>0){
                arr[i]=arr[i]-1;
                int ret1=solve(cur+1,i,prevdone+1,arr[1],arr[2],arr[3],arr[4]);
                arr[i]=arr[i]+1;
                LLI aa=(LLI)ret+(LLI)ret1;
                aa%=1000000007;
                ret=aa;
            }
        }
    }
    return dp[cur][previd][prevdone][firstleft][secleft][thirdleft][frthleft]=ret;
}

int main()
{
    FREP(i,1,5)scanf("%d",&A[i]);
    FREP(i,1,5)scanf("%d",&B[i]);
    FREP(i,1,5)tot+=A[i];
    init();
    int ans=solve(1,0,0,A[1],A[2],A[3],A[4]);
    printf("%d\n",ans);
    return 0;
}
