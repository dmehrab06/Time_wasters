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

char grid[205][205];

int soldiervis[205][205];
int princevis[205][205];
int hatchx,hatchy;
int soldierbfs(int n, int m){
    queue<PII>myq;
    memset(soldiervis,-1,sizeof(soldiervis));
    FREP(i,1,n){
        FREP(j,1,m){
            if(grid[i][j]=='$'){
                soldiervis[i][j]=0;
                myq.push(make_pair(i,j));
            }
        }
    }
    while(!myq.empty()){
        PII oka=myq.front();
        myq.pop();
        int dis=soldiervis[oka.first][oka.second];
        FREP(dx,-1,1){
            FREP(dy,-1,1){
                if(dx==0 || dy==0){
                    int nxtx=oka.first+dx;
                    int nxty=oka.second+dy;
                    if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]!='#' && soldiervis[nxtx][nxty]==-1){
                        soldiervis[nxtx][nxty]=dis+1;
                        myq.push(make_pair(nxtx,nxty));
                    }
                }

            }
        }
    }
    return soldiervis[hatchx][hatchy];
}

int princessbfs(int n, int m){
    queue<PII>myq;
    memset(princevis,-1,sizeof(princevis));
    FREP(i,1,n){
        FREP(j,1,m){
            if(grid[i][j]=='@'){
                princevis[i][j]=0;
                myq.push(make_pair(i,j));
            }
        }
    }
    while(!myq.empty()){
        PII oka=myq.front();
        myq.pop();
        int dis=princevis[oka.first][oka.second];
        FREP(dx,-1,1){
            FREP(dy,-1,1){
                if(dx==0 || dy==0){
                    int nxtx=oka.first+dx;
                    int nxty=oka.second+dy;
                    if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]!='#' && princevis[nxtx][nxty]==-1){
                        princevis[nxtx][nxty]=dis+1;
                        myq.push(make_pair(nxtx,nxty));
                    }
                }

            }
        }
    }
    return princevis[hatchx][hatchy];
}

char str[205];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        scanf("%s",str);
        FREP(j,1,m){
            grid[i][j]=str[j-1];
            if(grid[i][j]=='%'){
                hatchx=i;
                hatchy=j;
            }
        }
    }
    int sold=soldierbfs(n,m);
    if(sold==-1){
        printf("Yes\n");
    }
    else{
        int pr=princessbfs(n,m);
        if(pr<sold){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    //printf("%lld\n",mx);
    return 0;
}
