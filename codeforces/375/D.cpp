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
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)
#define eps 0.0000000001
#define RFREP(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define SORTV(VEC) sort(VEC.begin(),VEC.end())
#define SORTVCMP(VEC,cmp) sort(VEC.begin(),VEC.end(),cmp)
#define REVV(VEC) reverse(VEC.begin(),VEC.end())
using namespace std;

char grid[65][65];
int visited[65][65];
char s[65];

vector<pair<int,PII>>comps;
int cursize=0;
int curflag;
int n,m,k;
void dfs(int curx, int cury){
    cursize++;
    //int curflag=valid;
    if(curx==1 || curx==n || cury==1 || cury==m){
        curflag=0;
    }
    visited[curx][cury]=1;
    FREP(i,-1,1){
        FREP(j,-1,1){
            if(i==0 || j==0){
                int nxtx=curx+i;
                int nxty=cury+j;
                if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]=='.' && !visited[nxtx][nxty]){
                    dfs(nxtx,nxty);
                }
            }
        }
    }
    return;

}
void dfs2(int curx, int cury){
   // cursize++;
    //int curflag=valid;
   // if(curx==1 || curx==n || cury==1 || cury==m){
     //   curflag=0;
   // }
    visited[curx][cury]=1;
    grid[curx][cury]='*';
    FREP(i,-1,1){
        FREP(j,-1,1){
            if(i==0 || j==0){
                int nxtx=curx+i;
                int nxty=cury+j;
                if(ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty]=='.' && !visited[nxtx][nxty]){
                    dfs(nxtx,nxty);
                }
            }
        }
    }
    return;

}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    FREP(i,1,n){
        scanf("%s",s);
        FREP(j,1,m){
            grid[i][j]=s[j-1];
        }
    }
    FREP(i,1,n){
        FREP(j,1,m){
            if(!visited[i][j] && grid[i][j]=='.'){
                cursize=0;
                curflag=1;
                dfs(i,j);
                if(curflag){
                    pair<int,PII>pp=make_pair(cursize,make_pair(i,j));
                    comps.push_back(pp);
                }
            }
        }
    }
    sort(comps.begin(),comps.end());
    int sz=comps.size();
    FREP(i,0,(sz-1)){
        cout<<comps[i].first<<" "<<comps[i].second.first<<" "<<comps[i].second.second<<"\n";
    }
    int todel=sz-k;
    int ok=0;
    FREP(i,1,n){
        FREP(j,1,m){
            visited[i][j]=0;
        }
    }
    FREP(i,0,(todel-1)){
        pair<int,PII> nw=comps[i];
        ok+=nw.first;
        int cx=nw.second.first;
        int cy=nw.second.second;
        dfs2(cx,cy);
    }
    cout<<ok<<"\n";
    FREP(i,1,n){
        FREP(j,1,m){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
