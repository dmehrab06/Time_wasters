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
using namespace __gnu_pbds;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


typedef tree < int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

char grid[10][100005];
int vis[10][100005];

void init(){
    FREP(i,0,9)FREP(j,0,100004)vis[i][j]=-2;
}

void bfs(int srcx,int srcy, int n){
    queue<PII>all;
    all.push(make_pair(srcx,srcy));
    vis[srcx][srcy]=0;
    while(!all.empty()){
        PII nw=all.front();
        all.pop();
        int cx=nw.first;
        int cy=nw.second;
        if(cy==(n-1))break;
        int nx1,nx2;
        if(cx==9){
            nx1=cx;
            nx2=cx-1;
        }
        else if(cx==0){
            nx1=cx;
            nx2=cx+1;
        }
        else{
            nx1=cx+1;
            nx2=cx-1;
        }
        if(vis[nx1][cy+1]==-2 && grid[nx1][cy+1]=='.'){
            vis[nx1][cy+1]=nx1-cx;
            all.push(make_pair(nx1,cy+1));
        }
        if(vis[nx2][cy+1]==-2 && grid[nx2][cy+1]=='.'){
            vis[nx2][cy+1]=nx2-cx;
            all.push(make_pair(nx2,cy+1));
        }
    }
}

vector <int> ans;
vector <PII> mainans;
void iter(int curx, int cury){
    if(cury==-1){
        return;
    }
    int gox=curx-vis[curx][cury];
    iter(gox,cury-1);
    ans.PB(curx);
}

void solve(){
    int l=ans.size();
    int prevasctime=-1;
    FREP(i,1,(l-1)){
        if(ans[i]<ans[i-1]){
            if(prevasctime==-1){
                prevasctime=(i-1);
            }
        }
        else if(ans[i]>ans[i-1]){
            if(prevasctime!=-1){
                mainans.PB(make_pair(prevasctime,((i-1)-prevasctime)));
                prevasctime=-1;
            }
        }
    }
    if(prevasctime!=-1){
        mainans.PB(make_pair(prevasctime,(l-1-prevasctime)));
    }
}

int main(){
    int column;
    scanf("%d",&column);
    FREP(i,0,9){
        scanf("%s",grid[i]);
    }
    init();
    bfs(9,0,column);
    FREP(i,0,9){
        if(vis[i][column-1]!=-2){
            iter(i,column-1);
            break;
        }
    }
    solve();
    int l=mainans.size();
    cout<<l<<"\n";
    FREP(i,0,(l-1)){
        cout<<mainans[i].first<<" "<<mainans[i].second<<"\n";
    }
    return 0;
}
