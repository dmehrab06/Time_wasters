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

int visited[1003][1003];
int grid[1003][1003];

int bfs(int srcx, int srcy, int n, int m){
  //  cout<<"for "<<srcx<<" "<<srcy<<"\n";
    queue<PII>myq;
    visited[srcx][srcy]=1;
    myq.push(make_pair(srcx,srcy));
    int sz=0;
    int mxx=-1,mxy=-1;
    while(!myq.empty()){
        PII oka=myq.front();
        myq.pop();
        sz++;
        int cx=oka.first;
        int cy=oka.second;
        if(cx>mxx)mxx=cx;
        if(cy>mxy)mxy=cy;
        FREP(dx,-1,1){
            FREP(dy,-1,1){
                if((dx==1 && dy>=0) || (dy==1 && dx==0)){
                    int nxtx=cx+dx;
                    int nxty=cy+dy;
                    if( ISVALID(nxtx,nxty,n,m) && grid[nxtx][nxty] && !visited[nxtx][nxty]){
                        myq.push(make_pair(nxtx,nxty));
                        visited[nxtx][nxty]=1;
                    }
                }
            }
        }
    }
   // cout<<"got "<<mxx<<" "<<mxy<<"\n";
    int x=mxx-srcx+1;int y=mxy-srcy+1;
    if((x*y)!=sz){
        return -1;
    }
    if((srcy-1)>=1){
        FREP(i,(srcx-1),(mxx+1)){
            if(i<1 || i>n)return -1;
            else if(grid[i][srcy-1]!=0)return -1;
        }
    }
    else{
        return -1;
    }
    if((srcx-1)>=1){
        FREP(i,(srcy-1),(mxy+1)){
            if(i<1 || i>m)return -1;
            else if(grid[srcx-1][i]!=0)return -1;
        }
    }
    else{
        return -1;
    }
    if((mxy+1)<=m){
        FREP(i,(srcx-1),(mxx+1)){
            if(i<1 || i>n)return -1;
            else if(grid[i][mxy+1]!=0)return -1;
        }
    }
    else{
        return -1;
    }
    if((mxx+1)<=n){
        FREP(i,(srcy-1),(mxy+1)){
            if(i<1 || i>m)return -1;
            else if(grid[mxx+1][i]!=0)return -1;
        }
    }
    else{
        return -1;
    }
    return sz;
}

int main(){
    int n,m;
    memset(visited,0,sizeof(visited));
    int mxarea=-1;
    scanf("%d %d",&n,&m);
    FREP(i,1,n){
        FREP(j,1,m){
            scanf("%d",&grid[i][j]);
        }
    }
    FREP(i,1,n){
        FREP(j,1,m){
            if(grid[i][j]==1 && !visited[i][j]){
                int area=bfs(i,j,n,m);
                cout<<"got area "<<area<<"\n";
                if(area==-1)continue;
                if(area>mxarea)mxarea=area;
            }
        }
    }
    cout<<mxarea<<"\n";
    return 0;
}
