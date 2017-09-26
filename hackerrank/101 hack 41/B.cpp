#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 100000000000000000
#define MNN -MXX
#define VALID(X,Y,N,M) ((X)>=0 && (X)<(N) && (Y)>=0 && (Y)<(M))
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
#define pi acos(-1.0)
#define float double
#define MAXMOD 100000000
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define mp make_pair
#define EPS 1e-10
#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)

using namespace std;

template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}


const int MX = 1e5 + 7 ;
const int MXLG = 22 ;
const int INF = 1e8 + 7;
vector<PII>edge[MX] ;

//my arrays and functions not his
vector<VI>MYedge;
LLI sqsm[MX];
LLI lnsm[MX];
int par[MX];
LLI term[MX];
LLI sqsmelse[MX];
LLI lnsmelse[MX];
LLI termelse[MX];
//eida ar subtreesize same e

void setelse(int N){
    sqsmelse[1]=0;
    lnsmelse[1]=0;
    termelse[1]=0;
    FREP(i,2,N){
        LLI curterm=term[par[i]]-term[i];
        LLI curln=lnsm[par[i]]-lnsm[i]-term[i];
        LLI cursq=sqsm[par[i]]-sqsm[i]-2*lnsm[i]-term[i];
        sqsmelse[i]=cursq;
        lnsmelse[i]=curln;
        termelse[i]=curterm;
    }
    return;
}

void mydfs(int cur, int p){
    par[cur]=p;
    LLI t=1;
    LLI sq=0;
    LLI ln=0;
    int d=MYedge[cur].size();
    FREP(i,0,(d-1)){
        int nxt=MYedge[cur][i];
        mydfs(nxt,cur);
        t+=term[nxt];
        ln+=(lnsm[nxt]+term[nxt]);
        sq+=(sqsm[nxt]+2*lnsm[nxt]+term[nxt]);
    }
    sqsm[cur]=sq;
    lnsm[cur]=ln;
    term[cur]=t;
    return;
}

//my array and functions end
int N , P[MX][MXLG] , L[MX] , T[MX];
LLI dist[MX];
bool Vis[MX];
void dfs(int u , int p , int d){
    Vis[u] = true ;
    T[u] = p ; L[u] = d ;
    forstl(i,edge[u]){
        int v = i->first , w = i->second;
        if( Vis[v] ) continue;
        P[v][0] = u ;
        dist[v] = dist[u] + w ;
        dfs(v,u,d+1);
    }
}
void preprocess() {
    for( int i = 1 ; i <= N ; i++ ){
        for( int j = 0 ; (1 << j) < N ; j++ ){
            P[i][j] = -1 ;
        }
    }
    dfs(0,-1,0); // call with u = 0 becase The first anthill, numbered 0, did not require any tunnel
    for( int j = 1 ; (1 << j) < N ; j++ ) {
        for( int i = 1 ; i <= N ; i++ ) {
            if( P[i][j - 1] == -1 ) continue ;
            P[i][j] = P[ P[i][j - 1] ][j - 1];
        }
    }
    mydfs(1,1);
    setelse(N);
}
void Reset(){
    for( int i = 0 ; i <=  N ; i++ ){
        edge[i].clear();
        Vis[i] = false ;
        dist[i] = -1;
    }
    dist[0] = 0 ;// 0 is root of  the tree
    VI line;
    FREP(i,1,(MX)){
        MYedge.push_back(line);
    }
}
int lca(int p , int q){
    if(L[p] < L[q] ) swap(p,q);
    int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg );
    lg--;
    for( int i = lg ; i >= 0 ; i--){
        if( L[p] - (1 << i) >= L[q] ){
            p = P[p][i];
        }
    }
    if( p == q ) return p ;
    for( int i = lg ; i >= 0 ; i-- ){
        if( P[p][i] != -1 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return T[p];
}
void Input(){
    Reset();
    For(u,N-1) {
        int v;
        read(v);
        int w=1;
        edge[u].pb(mp(v-1,w));
        edge[v-1].pb(mp(u,w));
        MYedge[v].pb(u+1);
    }
}

int main(){
#ifdef LOCAL
         FI ;
#endif
        read(N);
        Input();
        preprocess();
        int Q ; read(Q);
        rep(q,Q){
            //if(q) printf(" ");
            int x , y ; read(x) , read(y);  //turn on y //check whether x is in y subtree or outside
            int a = lca(x-1,y-1);
            LLI Ans = dist[x-1] + dist[y-1] - 2 * dist[a] ;
            //printf("%d %lld\n",a+1,Ans);
            if((a+1)==y){
                //x is  a part of y subtree
                //cout<<"parina\n";
                if(x==y){
                    printf("%lld\n",sqsm[x]);
                }
                else if(par[x]==y){
                    int prev;
                    int cur=x;
                    LLI ans=0;
                    int dis=0;
                    while(cur!=y){
                        prev=cur;
                        cur=par[cur];
                        dis++;
                        LLI cursq=sqsm[cur]-sqsm[prev]-2*lnsm[prev]-term[prev];
                        LLI curln=lnsm[cur]-lnsm[prev]-term[prev];
                        LLI curterm=term[cur]-term[prev];
                        LLI ans1=cursq+2*dis*curln+curterm*dis*dis;
                        ans+=ans1;
                    }
                    LLI ans2=sqsm[x];
                    ans+=ans2;
                    printf("%lld\n",ans);
                }
                else{
                    LLI ans1=sqsm[x];
                    LLI ans2=sqsmelse[x];
                    LLI sqq=sqsmelse[y];
                    LLI lnn=lnsmelse[y];
                    LLI tt=termelse[y];
                    LLI ddd=Ans+1;
                    LLI ans3=sqq+2*ddd*lnn+tt*ddd*ddd;
                    LLI ans4=ans2-ans3;
                    LLI ans=ans1+ans4;
                    printf("%lld\n",ans);
                }
            }
            else{
               // keu karo subtree na
               //eida soja hobe maybe
               LLI xx=Ans;
               LLI cursq=sqsm[y];
               LLI curln=lnsm[y];
               LLI t=term[y];
               LLI ret=cursq+2*xx*curln+t*xx*xx;
               printf("%lld\n",ret);

            }
        }
        //printf("\n");
    }

