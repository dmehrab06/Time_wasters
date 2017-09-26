#include<bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))
#define MXX 1000000000
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
#define XX first
#define YY second
using namespace std;

int representative[20005];

void init(int n){
    FREP(i,0,(n+2))representative[i]=i;
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
}

pair<int,PII> mnedges[12007];

int kruskalmn(int n, int sz){
    sort(mnedges,mnedges+sz);
    init(n);
    int cst=0;
    int taken=0;
    int it=0;
    while(taken<n){
        pair<int,PII>cur=mnedges[it++];
        int u=cur.second.first;
        int v=cur.second.second;
        if(findrep(u)!=findrep(v)){
            unionfind(u,v);
            taken++;
            cst+=cur.first;
        }
    }
    return cst;
}

int kruskalmx(int n, int sz){
    //sort(mxedges,mxedges+sz);
    init(n);
    int cst=0;
    int taken=0;
    int it=sz-1;
    while(taken<n){
        pair<int,PII>cur=mnedges[it--];
        int u=cur.second.first;
        int v=cur.second.second;
        if(findrep(u)!=findrep(v)){
            unionfind(u,v);
            taken++;
            cst+=(cur.first);
        }
    }
    return cst;
}

int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        scanf("%d",&n);
        //mxedges.clear();
        //mnedges.clear();
        int sz=0;
        while(true){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            if(!u && !v && !w)break;
           // mxedges[sz]=(make_pair(-w,make_pair(u,v)));
            mnedges[sz++]=(make_pair(w,make_pair(u,v)));
        }
        printf("Case %d: ",cs++);
        int ans=kruskalmn(n,sz)+kruskalmx(n,sz);
        if(ans%2==0){
            printf("%d\n",ans/2);
        }
        else{
            printf("%d/2\n",ans);
        }
    }
    return 0;
}

