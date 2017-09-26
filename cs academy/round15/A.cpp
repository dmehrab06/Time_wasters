/*-------property of the half blood prince-----*/

#include <bits/stdc++.h>
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

char grid[203][203];

int dx[5]={0,0,0,1,2};
int dy[5]={0,-1,1,0,0};

bool check(int x, int y, int n, int m){
    FREP(i,0,4){
        int sx=x+dx[i];
        int sy=y+dy[i];
        if(!ISVALID(sx,sy,n,m) || grid[sx][sy]!='t'){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%s",grid[i-1]);
    }
    int tot=0;
    FREP(i,0,(n-1)){
        FREP(j,0,(m-1)){
            if(check(i,j,n,m))tot++;
        }
    }
    printf("%d\n",tot);
}
