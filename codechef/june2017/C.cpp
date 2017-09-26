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

LLI A[100005];
LLI B[100005];
LLI C[100005];

LLI cumA[100005];
LLI cumB[100005];
LLI cumC[100005];

int aptr,bptr,cptr;

void init(){
    aptr = 0;
    bptr = 0;
    cptr = 0;
}

void sortt(int asz, int bsz, int csz){
    sort(A+1,A+1+asz);
    sort(B+1,B+1+bsz);
    sort(C+1,C+1+csz);
}

void searchA(LLI val, int asz){
    for(int i = aptr ; ; ++i){
        if(A[i]>val){
            aptr = i-1;
            break;
        }
        else if(i==asz){
            aptr = i;
            break;
        }
    }
}

void searchC(LLI val, int csz){
    for(int i = cptr ; ; ++i){
        if(C[i]>val){
            cptr = i-1;
            break;
        }
        else if(i==csz){
            cptr = i;
            break;
        }
    }
}

void getcumsum(int asz, int bsz, int csz){
    cumA[0]=0; cumB[0]=0; cumC[0]=0;
    FREP(i,1,asz){
        cumA[i]=cumA[i-1]+A[i];
    }
    FREP(i,1,csz){
        cumC[i]=cumC[i-1]+C[i];
    }
}

int getf(int bidx, int asz, int csz){
    LLI curval = B[bidx];
    searchA(curval,asz); searchC(curval,csz);
    LLI part1 = ((cumA[aptr]%MDD)*(cptr%MDD))%MDD;
    LLI part2 = ((cumC[cptr]%MDD)*(aptr%MDD))%MDD;
    LLI part3 = ((( (LLI)aptr*cptr)%MDD)*((curval*curval)%MDD))%MDD;
    LLI part4 = ((cumA[aptr]%MDD)*(cumC[cptr]%MDD))%MDD;
    LLI ans1 =  ((curval%MDD)*part1)%MDD;
    LLI ans2 =  ((curval%MDD)*part2)%MDD;
    LLI ans = (ans1+ans2)%MDD;
    ans+=part3; ans%=MDD; ans+=part4; ans%=MDD;
    return ans;
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int asz,bsz,csz;
        scanf("%d %d %d",&asz,&bsz,&csz);
        FREP(i,1,asz)scanf("%lld",&A[i]);
        FREP(i,1,bsz)scanf("%lld",&B[i]);
        FREP(i,1,csz)scanf("%lld",&C[i]);
        sortt(asz,bsz,csz);
        getcumsum(asz,bsz,csz);
        LLI ss=0;
        FREP(i,1,bsz){
            ss+=getf(i,asz,csz);
            ss%=MDD;
        }
        printf("%lld\n",ss);
    }
    return 0;
}
