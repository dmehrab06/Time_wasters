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

int len[20005];
char dir[20005][5];
int newlen[20005];
char newdir[20005][5];

int compress(int n){
    int curidx=1;
    int curlen=len[1];
    char curdir=dir[1][0];
    FREP(i,2,n){
        if(dir[i][0]==curdir){
            curlen+=len[i];
        }
        else{
            newdir[curidx][0]=curdir;
            newlen[curidx]=curlen;
            curidx++;
            curlen=len[i];
            curdir=dir[i][0];
        }
    }
    newdir[curidx][0]=curdir;
    newlen[curidx]=curlen;
    return curidx;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n,r;
        scanf("%d %d",&n,&r);
        FREP(i,1,n){
            scanf("%d",&len[i]);
        }
        FREP(i,1,n){
            scanf("%s",dir[i]);
        }
        int tot=compress(n);
        int curilluminated=0;
        int candles=0;
        int curidx=1;
        while(true){
            if(curidx>tot){
                break;
            }
            if(curilluminated==newlen[curidx]){
                curidx++;
                curilluminated=0;
                continue;
            }
            int nowplace=min(curilluminated+r,newlen[curidx]);
            candles++;
            curilluminated=min(nowplace+r,newlen[curidx]);
            if(curilluminated==newlen[curidx]){
                if(curidx==tot)break;
                if(nowplace==newlen[curidx]){
                    curilluminated=min(r,newlen[curidx+1]);
                    curidx++;
                }
                else{
                    curilluminated=0;
                    curidx++;
                }
            }
        }
        printf("Case %d: %d\n",cs++,candles);

    }
    return 0;
}
