#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 10000000000000000
#define MNN -MXX
#define ISVALID(X,Y,N,M) ((X)>=1 && (X)<=(N) && (Y)>=1 && (Y)<=(M))
#define LLI long long int
#define VI vector<int>
#define VLLI vector<long long int>
#define MII map<int,int>
#define SI set<int>
#define MSI map<string,int>
#define PII pair<int,int>
#define FREP(i,I,N) for(int (i)=(I);(i)<=(N);(i)++)

using namespace std;

//Data Structure used: 2D doubly linked list
//store val; up, down, left and right node
//take row+2, col+2 area to avoid null pointer hasty checking
//when swapping two rectangle only outer boundary pointers need to be updated

vector< vector < int > >edges;

int compsize[200007];
int representative[200007];
int ispar[200007];
int hascycle[200007];
LLI fact[200007];
LLI twopow[200007];


int solve(int par){
    //hascycle[par]<=compsize[par]
    LLI ans=fact[hascycle[par]-1]*twopow[compsize[par]-hascycle[par]];
    ans%=1000000007;
    return ans;
}

void init(int n){
    FREP(i,1,n){
        representative[i]=i;
        compsize[i]=1;
        hascycle[i]=0;
        ispar[i]=0;
    }
    twopow[0]=1;
    fact[0]=1;
    FREP(i,1,200006){
        fact[i]=fact[i-1]*i;
        fact[i]%=1000000007;
        twopow[i]=twopow[i-1]*2;
        twopow[i]%=1000000007;
    }
}

int findrep(int a){
    if(representative[a]!=a){
        return representative[a]=findrep(representative[a]);
    }
    else{
        return a;
    }
}

void unionfind(int x, int y){
    int xp,yp;
    xp=findrep(x);
    yp=findrep(y);
    representative[yp]=xp;
    compsize[xp]+=compsize[yp];
}

int main(){
    int N;
    scanf("%d",&N);
    init(N);
    vector<int>line;
    FREP(i,0,(N+2))edges.push_back(line);
    FREP(i,1,N){
        int v;
        scanf("%d",&v);
        if(i<v)
        edges[i].push_back(v);
        else{
            edges[v].push_back(i);
        }
    }
    FREP(i,1,N){
        int deg=edges[i].size();
        FREP(j,0,(deg-1)){
            int u=i;
            int v=edges[i][j];
            int up=findrep(u);
            int vp=findrep(v);
            if(up==vp){
                hascycle[up]=compsize[up];
            }
            else{
                unionfind(u,v);
            }
        }

    }
    LLI ans=1;
    FREP(i,1,N){
        if(representative[i]==i && hascycle[i]){
            LLI ret=solve(i);
            ans=ans*ret;
            ans%=1000000007;
        }
    }
    ans=twopow[N]-ans;
    while(ans<0)ans+=1000000007;
    cout<<ans<<"\n";

    return 0;
}
