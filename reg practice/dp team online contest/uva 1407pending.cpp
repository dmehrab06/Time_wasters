#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000005
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
using namespace std;

int dp[503][503][3];
int subsz[503];
PII edges[503][503];

void init(){
    FREP(i,0,502)FREP(j,0,502)FREP(k,0,2)dp[i][j][k]=MXX;
    FREP(i,0,502)edges[i][0].first=0;
}

void scanedge(int n){
    FREP(i,1,(n-1)){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        PII uv=make_pair(v,w);
        PII vu=make_pair(u,w);
        edges[u][edges[u][0].first+1]=uv;
        edges[u][0].first++;
        edges[v][edges[v][0].first+1]=vu;
        edges[v][0].first++;
    }
}

int NOWROOTCHILD;

int solve(int root, int covered, int done){
    if(covered==0)return MXX;
    if(covered==1){
        return dp[root][covered][done]=0;
    }
    if(dp[root][covered][done]!=MXX){
        return dp[root][covered][done];
    }
    //int deg=edges[root][0].first;

    int to=edges[root][NOWROOTCHILD].first;
    int ww=edges[root][NOWROOTCHILD].second;
    cout<<"aschi2\n";
    if(done==0){
        int ret1, ret2;
        cout<<"dhukbo\n";
        FREP(x,0,min(covered,subsz[to])){
            cout<<x<<"\n";
            ret1=solve(root,covered-x,1)+solve(to,x,0)+ww; //covered-x part is finished, inside to subtree
            ret2=solve(root,covered-x,0)+solve(to,x,1)+2*ww; //v subtree finished, back to u hence ww+ww and then not done in covered-x part
            dp[root][covered][done]=min(dp[root][covered][done], min(ret1,ret2));
        }
    }
    else{
        int ret;
        cout<<"dhukbo2\n";
        FREP(x,0,min(covered,subsz[to])){
            cout<<x<<"\n";
            ret=solve(root,covered-x,1)+solve(to,x,1)+2*ww; //both part done
            dp[root][covered][done]=min(dp[root][covered][done], ret);
        }
    }
    cout<<"root "<<root<<" covered "<<covered<<" done "<<done<<" hoise\n";
    return dp[root][covered][done];
}

int bs(int n,int dis){
    int l=1;
    int h=n;
    while(true){
        int mid=(l+h)/2;
        if(dp[0][mid][0]<=dis){
            if((mid+1)>n || dp[0][mid+1][0]>dis){
                return mid;
            }
            else{
                l=mid+1;
            }
        }
        else{
            h=mid;
        }
    }
}

int dfs(int cur, int par){
    subsz[cur]=1;
    int deg=edges[cur][0].first;
    FREP(i,1,deg){
        int v=edges[cur][i].first;
        if(v==par)continue;
        subsz[cur]+=dfs(v,cur);
        NOWROOTCHILD=i;
        int nowsubsz=subsz[cur];
        cout<<"aschi\n";
        for(int j=nowsubsz;j>1;j--){
            solve(cur,j,0);
        }
    }
    //int subtreesize=subsz[cur];
    /*FREP(i,2,subtreesize){
        solve(cur,i,0);
        solve(cur,i,1);
    }*/
    /*cout<<"hoise\n";
    for(int i=subtreesize;i>=1;i--){
        solve(cur,i,0);
        solve(cur,i,1);
    }
    cout<<"hoise2\n";*/
    return subsz[cur];
}

int main(){
    int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N){
        init();
        scanedge(N);
        dfs(0,0);
        int q;
        printf("Case %d:\n",cs++);
        scanf("%d",&q);
        FREP(i,1,q){
            int dis;
            scanf("%d",&dis);
            int ans=bs(N,dis);
            printf("%d\n",ans);
        }
    }
    return 0;
}
