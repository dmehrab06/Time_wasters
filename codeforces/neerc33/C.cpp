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

LLI getsum(LLI n){
    LLI ans = n*(n+1);
    return ans/2;
}

LLI getbrackval(LLI n){
    return getsum(n-1);
}

LLI getclosest(LLI ss){
    LLI sss = ss*2;
    LLI n  = sqrt(sss);
    FREP(i,-2,2){
        LLI cur = (n+i);
        LLI sm = getsum(cur);
        if(sm>ss)return (cur-1);
    }
    return -1; //ghapla
}

int main(){
    LLI n,k;
    cin>>n>>k;
    if(getbrackval(n)<k){
        printf("Impossible\n");
        return 0;
    }
    if(k==0){
        FREP(i,1,n){
            printf("()");
        }
        printf("\n");
        return 0;
    }
    LLI x = getclosest(k)+1;
    LLI canmake = getbrackval(x);
    LLI left = k - canmake;
    //cout<<x<<" "<<canmake<<" "<<left<<"\n";
    int used = 0;
    FREP(i,1,x){
        printf("(");
        used++;
    }
    FREP(i,1,(x-left)){
        printf(")");
    }
    if(used<n){
        printf("()");
        used++;
        FREP(i,1,left){
            printf(")");
        }
        while(used<n){
            printf("()");
            used++;
        }
    }
    printf("\n");
    return 0;
}
