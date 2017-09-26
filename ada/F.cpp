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

char minar[70][20];

int main(){
    int t;
    scanf("%d",&t);
    minar[1][5]='|';
    minar[1][6]='|';
    minar[2][3]='|';
    minar[2][5]='|';
    minar[2][6]='|';
    minar[2][8]='|';
    minar[3][3]='|';
    minar[3][5]='|';
    minar[3][6]='|';
    minar[3][8]='|';
    minar[3][1]='|';
    minar[3][10]='|';
  //  int cs=1;
    FREP(i,1,3){
        FREP(j,1,10){
            if(minar[i][j]!='|'){
                minar[i][j]=' ';
            }
        }
    }
    FREP(i,4,60){
        FREP(j,1,10){
            minar[i][j]=minar[3][j];
        }
    }
    while(t--){
        int n;
        scanf("%d",&n);
        FREP(i,1,n){
            FREP(j,1,10){
                printf("%c",minar[i][j]);
            }
            printf("\n");
        }
        //printf("Case %d: %lld\n",cs++,n);
    }
    return 0;
}

