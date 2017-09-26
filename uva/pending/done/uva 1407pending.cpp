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
#define FREV(i,N,I) for(int (i)=(N);(i)>=(I);(i)--)
#define eps 0.0000000001
using namespace std;

int dp[503][503][3];
int subsz[503];
int par[504];
PII edges[503][503];
int postorder[503];
void init(){
    postorder[0]=0;
    FREP(i,0,502)FREP(j,0,502)FREP(k,0,2)dp[i][j][k]=MXX;
    FREP(i,0,502)edges[i][0].first=0;
    FREP(i,0,503)par[i]=i;
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
        par[u]=v;
    }
}


void solve(){
    int l=postorder[0];
    FREP(i,1,l){
        int root=postorder[i];
    //    cout<<"for root "<<root<<"\n";
        dp[root][1][0]=0;
        dp[root][1][1]=0;
        int deg=edges[root][0].first;
        int cancover=1;
        FREP(i,1,deg){
            int focusv=edges[root][i].first;
            if(focusv==par[root])continue;
            int focus=subsz[focusv];
            int focusw=edges[root][i].second;
      //      cout<<focusv<<" "<<focus<<" "<<focusw<<"\n";
            cancover+=focus;
            FREV(covered,cancover,2){
                FREP(divide,0,min(covered,focus)){
                    int dis1=dp[root][covered-divide][1]+dp[focusv][divide][0]+focusw; //previous done but this not done
                    int dis2=dp[root][covered-divide][0]+dp[focusv][divide][1]+2*focusw; //this done but previous not done
                    dp[root][covered][0]=min(dp[root][covered][0],min(dis1,dis2));
                    int dis3=dp[root][covered-divide][1]+dp[focusv][divide][1]+2*focusw; //done in both previous and this
                    dp[root][covered][1]=min(dis3,dp[root][covered][1]);
                }
        //        cout<<"dp obostha\n";
          //      cout<<" root "<<root<<" covered "<<covered<<" "<<dp[root][covered][0]<<" "<<dp[root][covered][1]<<"\n";

            }

        }
    }

}

int bs(int n,int dis, int main){
    int l=1;
    int h=n;
    while(true){
        int mid=(l+h)/2;
        if(dp[main][mid][0]<=dis){
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
    //    NOWROOTCHILD=i;
      //  int nowsubsz=subsz[cur];

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
    postorder[postorder[0]+1]=cur;
	postorder[0]++;
    return subsz[cur];
}

int main(){
    int N;
    int cs=1;
    while(scanf("%d",&N)==1 && N){
        init();
        scanedge(N);
        int parn;
        FREP(i,0,(N-1))if(par[i]==i){parn=i;break;}
        //cout<<parn<<"\n";
        dfs(parn,parn);
        //FREP(i,0,(N-1))cout<<subsz[i]<<"\n";
        solve();
        /*FREP(i,0,N){
            FREP(j,0,N)cout<<dp[i][j][0]<<" ";
            cout<<"\n";
        }
        FREP(i,0,N){
            FREP(j,0,N)cout<<dp[i][j][1]<<" ";
            cout<<"\n";
        }*/
        int q;
        printf("Case %d:\n",cs++);
        scanf("%d",&q);
        FREP(i,1,q){
            int dis;
            scanf("%d",&dis);
            int ans=bs(N,dis,parn);
            printf("%d\n",ans);
        }
    }
    return 0;
}
