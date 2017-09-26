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
#define LEFT 1
#define RIGHT 2
#define MDD 1000000007
using namespace std;
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

LLI ncrtable[200005];

LLI arr[200005];

LLI coeffA[200005];
LLI coeffB[200005];

LLI bigmod(LLI base, LLI pow, LLI mdd){
    if(pow==0)return (LLI)1;
    LLI ret = bigmod(base,pow/2,mdd);
    if(pow%2==0)return (ret*ret)%mdd;
    return (((base*ret)%mdd)*ret)%mdd;
}

LLI setval(LLI v, LLI mdd){
    if(v<0)return v+mdd;
    return v%mdd;
}

void fillncr(int n, int mdd){
    ncrtable[0]=1;
    FREP(r,1,n){
        LLI lob = n-r+1;
        LLI invhor = bigmod(r,mdd-2,mdd);
        LLI ans = (lob*invhor)%mdd;
        ncrtable[r]=ncrtable[r-1]*ans;
        ncrtable[r]%=mdd;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        cin>>arr[i];
    }
    if(n%2){
        int stepneeded = n-1; int last4 = (stepneeded/4)*4;
        int coeff = last4/2;
        fillncr(coeff,MDD);
        FREP(i,0,coeff){
            int pos = i*2+1;
            coeffA[pos]=ncrtable[i]; coeffB[pos+1]=ncrtable[i];
        }
        int kk=0;
        FREP(i,last4+1,stepneeded){
            if((kk%4)<=1){
                FREP(j,1,n)coeffA[j]=coeffA[j]+coeffB[j];
                FREP(j,1,n-1)coeffB[j+1]=coeffA[j]*(j%2?1:-1);
            }
            else{
                FREP(j,1,n)coeffA[j]=coeffA[j]-coeffB[j];
                FREP(j,1,n-1)coeffB[j+1]=coeffA[j]*(j%2?1:-1);
            }
            FREP(j,1,n){
                coeffA[j]=setval(coeffA[j],MDD); coeffB[j]=setval(coeffB[j],MDD);
            }
            kk++;
            kk%=4;
        }
        LLI s=0;
        FREP(i,1,n){
            LLI pp = coeffA[i]*arr[i];
            pp%=MDD;
            s+=pp;
            s%=MDD;
        }
        cout<<s<<"\n";
    }
    else{
        int stepneeded = n-1; int last4 = (stepneeded/4)*4;
        int coeff = last4/2;
        fillncr(coeff,MDD);
        FREP(i,0,coeff){
            int pos = i*2+1;
            coeffA[pos]=ncrtable[i]; coeffB[pos+1]=ncrtable[i];
        }
        int kk=0;
        FREP(i,last4+1,stepneeded){
            if((kk%4)==0){
                FREP(j,1,n)coeffA[j]=coeffA[j]+coeffB[j];
                FREP(j,1,n-1)coeffB[j+1]=coeffA[j]*(j%2?1:-1);
            }
            else{
                FREP(j,1,n)coeffA[j]=coeffA[j]-coeffB[j];
                FREP(j,1,n-1)coeffB[j+1]=coeffA[j]*(j%2?1:-1);
            }
            FREP(j,1,n){
                coeffA[j]=setval(coeffA[j],MDD); coeffB[j]=setval(coeffB[j],MDD);
            }
            kk++;
            kk%=4;
        }
        LLI s=0;
        FREP(i,1,n){
            LLI pp = coeffA[i]*arr[i]; pp=setval(pp,MDD);
            s+=pp; s =setval(s,MDD);
        }
        cout<<s<<"\n";
    }
    return 0;
}
