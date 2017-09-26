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
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI twopow[300015];

LLI bigval=(LLI)MDD*MDD;

void get2pow(){
    twopow[0]=1;
    FREP(i,1,300011){
        twopow[i]=twopow[i-1]*2;
        twopow[i]%=MDD;
    }
}

LLI findcoeff(int idx, int n){
    int startsat=(idx*2);
    if(n==(startsat-1)){
        return 0;
    }
    int powval=(n-startsat+1);
    LLI gun=twopow[powval];
    gun = gun - 1;
    if(gun<0)gun+=MDD;
    LLI startval = twopow[idx-1];
    return (startval*gun)%MDD;
}

int arr[300005];

LLI coeffs[300005];

int main(){
    get2pow();
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    if(n%2){
        int mid=(n/2)+1;
        coeffs[mid]=0;
        FREP(i,1,mid-1){
            coeffs[i]=-findcoeff(i,n);
        }
        FREP(i,mid+1,n){
            coeffs[i]=-coeffs[n-i+1];
        }
        LLI s=0;
        RFREP(i,n,1){
            LLI vv=coeffs[i]*arr[i];
            if(vv<0){
                vv+=bigval;
                vv%=MDD;
            }
            s=s+vv;
            s%=MDD;
        }
        printf("%lld\n",s);
    }
    else{
        int mid=(n/2);
        FREP(i,1,mid){
            coeffs[i]=-findcoeff(i,n);
        }
        FREP(i,mid+1,n){
            coeffs[i]=-coeffs[n-i+1];
        }
        LLI s=0;
        RFREP(i,n,1){
            LLI vv=coeffs[i]*arr[i];
            if(vv<0){
                vv+=bigval;
                vv%=MDD;
            }
            s=s+vv;
            s%=MDD;
        }
        printf("%lld\n",s);
    }
    return 0;
}
