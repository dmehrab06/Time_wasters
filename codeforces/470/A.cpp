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
#define INRANGEI(val,l,r) ((val)>=(l) && (val)<=(r))
using namespace std;
using namespace __gnu_pbds;

typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char grid[503][503];

void print(int r, int c){
    FREP(i,0,r-1){
        FREP(j,0,c-1)printf("%c",grid[i][j]);
        printf("\n");
    }
}

void fillgrid(int r, int c){
    FREP(i,0,r-1){
        FREP(j,0,c-1)if(grid[i][j]=='.')grid[i][j] = 'D';
    }
}

bool check(int r, int c){
    FREP(i,0,r-1){
        FREP(j,0,c-1){
            if(grid[i][j]=='W'){
                FREP(dx,-1,1){
                    FREP(dy,-1,1){
                        if((dx==0 || dy==0) && (dx || dy)){
                            int ii = dx+i; int jj = dy+j;
                            if(INRANGEI(ii,0,r-1) && INRANGEI(jj,0,c-1) && grid[ii][jj]=='S')return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    FREP(i,0,r-1)scanf("%s",grid[i]);
    if(!check(r,c)){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        fillgrid(r,c);
        print(r,c);
    }
    return 0;
}
