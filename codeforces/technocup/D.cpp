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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

vector<PII>rating;

int main(){
    LLI xmin=-20000000000;
    LLI xmax=20000000000;
    int n;
    LLI offset=0;
    scanf("%d",&n);
    FREP(i,1,n){
        int r,d;
        scanf("%d %d",&r,&d);
        PII rt=make_pair(r,d);
        rating.PB(rt);
    }
    FREP(i,0,(n-1)){
        if(rating[i].second==2){
            LLI leqthan=(LLI)1899-offset;
            xmax=min(xmax,leqthan);
        }
        else if(rating[i].second==1){
            LLI geqthan=(LLI)1900-offset;
            xmin=max(xmin,geqthan);
        }
        offset+=rating[i].first;
    }
    if(xmax==20000000000){
        printf("Infinity\n");
    }
    else if(xmax<xmin){
        printf("Impossible\n");
    }
    else{
        cout<<xmax+offset<<"\n";
    }
    return 0;
}


