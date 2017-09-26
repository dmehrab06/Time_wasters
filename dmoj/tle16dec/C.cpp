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
#define MXX 1000000000000000000
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

int pts[8]={0,1,2,3,4,5,6,7};

int g[12][12];

PII neededge[12];

bool can(){
    FREP(i,0,11){
        int u=pts[neededge[i].first];
        int v=pts[neededge[i].second];
        if(!g[u][v])return false;
    }
    return true;
}

int main(){
    neededge[0]=make_pair(0,1);
    neededge[1]=make_pair(1,3);
    neededge[2]=make_pair(0,2);
    neededge[3]=make_pair(2,3);
    neededge[4]=make_pair(4,5);
    neededge[5]=make_pair(4,6);
    neededge[6]=make_pair(6,7);
    neededge[7]=make_pair(5,7);
    neededge[8]=make_pair(0,4);
    neededge[9]=make_pair(1,5);
    neededge[10]=make_pair(3,7);
    neededge[11]=make_pair(2,6);

    FREP(i,0,7)pts[i]=i;

    int n;

    scanf("%d",&n);

    FREP(i,1,n){
        int u,v;
        scanf("%d %d",&u,&v);
        g[u-1][v-1]=1;
        g[v-1][u-1]=1;
    }
    int f=0;
    do{
        if(can()){
            f=1;
            break;
        }
    }while(next_permutation(pts,pts+8) );

    if(f){
        printf("Ja\n");
    }
    else{
        printf("Nej\n");
    }

    return 0;
}

