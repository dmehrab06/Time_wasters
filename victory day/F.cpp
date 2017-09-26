/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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
#define ISVALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define PB push_back
#define MSI map<string,int>
#define PII pair<int,int>
#define PLLI pair<LLI,LLI>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

int flr[1000006];
int foot[1000006];
int chain[1000006];



int main(){
    int n;
    scanf("%d",&n);
    FREP(i,1,n){
        scanf("%d",&flr[i]);
    }
    FREP(i,1,n){
        scanf("%d",&foot[i]);
    }
    FREP(i,1,n){
        scanf("%d",&chain[i]);
    }
    LLI ss1=0;
    FREP(i,1,n){
        ss1=ss1+(flr[i]-foot[i])*(flr[i]-foot[i]);
    }
    LLI ss2=0;
    FREP(i,1,n){
        ss2=ss2+(flr[i]-chain[i])*(flr[i]-chain[i]);
    }
    if(ss1<ss2){
        printf("Yan\n");
    }
    else{
        printf("MaratonIME\n");
    }
    return 0;
}
