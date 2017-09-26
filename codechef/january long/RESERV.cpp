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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction




typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char grid[1003][1003];
char inp[1003];

bool ok(int x, int y){
    if(grid[x][y]=='A')return true;
    if(grid[x][y]=='B'){
        return grid[x+1][y]=='B';
    }
    return !(grid[x][y-1]=='A' || grid[x][y+1]=='A' || grid[x+1][y]=='A');
}

void init(int n, int m){
    FREP(j,0,(m+1)){
        grid[0][j]='A';
    }
    FREP(i,0,(n+1)){
        grid[i][0]='A';
    }
    FREP(i,0,(n+1)){
        grid[i][m+1]='A';
    }
    FREP(j,0,(m+1)){
        grid[n+1][j]='B';
    }
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        init(n,m);
        FREP(i,1,n){
            scanf("%s",inp);
            FREP(j,0,(m-1)){
                grid[i][j+1]=inp[j];
            }
        }
        int f=1;
        FREP(i,1,n){
            if(!f)break;
            FREP(j,1,m){
                if(!ok(i,j)){
                    f=0;
                    break;
                }
            }
        }
        if(f){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}


